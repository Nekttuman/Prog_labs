#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


struct coord {
  double x;
  double y;
};

struct fig {
  coord first = { 0,0 };
  coord second = { 0,0 };
  coord third = { 0,0 };
  coord four;
  coord five;
  coord center;
  coord sub_center;
  int inner_points_count = 5;
};


bool check_line(std::string l) {
  bool has_first_n = false, has_one_whitespace = false, has_second_digit = false,
    has_two_whitespaces = true;
  for (int ch = 0; ch < l.size(); ch++) {
    if ((isdigit(l[ch]) || l[ch] == '-' || l[ch] == '.') && !has_first_n) {
      has_first_n = true;
    }
    else if ((isdigit(l[ch]) || l[ch] == '-' || l[ch] == '.') && has_one_whitespace && !has_second_digit) {
      has_second_digit = true;
    }
    else if (l[ch] == ' ' && has_first_n && !has_one_whitespace) {
      has_one_whitespace = true;
    }
    else if (l[ch] == ' ' && has_first_n && has_one_whitespace && !has_second_digit) {
      has_one_whitespace = false;
    }
    else if (has_first_n && has_one_whitespace && has_second_digit && (!isdigit(l[ch]) && l[ch] != '-' && l[ch] != '.')) {
      if (l[ch] == ' ' || l[ch] == '\n') {
        has_two_whitespaces = true;
      }
      else {
        has_two_whitespaces = false;
        break;
      }
    }
  }
  return (has_first_n && has_one_whitespace && has_second_digit && has_two_whitespaces);
}

int get_n(std::fstream& in, std::fstream& log) {
  std::string line = "aa";
  int n = 0;
  int line_c = 0;
  while (!in.eof()) {
    std::getline(in, line);
    line_c++;
    if (check_line(line))
      n++;
    else
      log << "format error in input file in " + std::to_string(line_c) + " line\n";
  }
  in.close();
  in.open("../../input.txt");
  return n;
}

bool is_in(coord point, coord* points, const int n) {
  for (int i = 0; i < n; i++) {
    if (point.x == points[i].x && point.y == points[i].y) {
      return true;
    }
  }

  return false;
}

void read_points(std::fstream& in, coord* points, int &n, std::fstream &log) {
  int p = 0;
  std::string line;
  log << "read points: \n";
  while (!in.eof()) {
    std::getline(in, line);
    if (check_line(line)) {
      int first_space_ptr = -1, second_space_ptr = -1;
      for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
          if (first_space_ptr == -1)
            first_space_ptr = i;
          else if (second_space_ptr == -1) {
            second_space_ptr = i;
            break;
          }
        }
        else if (line[i] == '\n') {
          second_space_ptr = i;
          break;
        }
      }
      coord tmp{ stod(line.substr(0, first_space_ptr)) ,stod(line.substr(first_space_ptr, second_space_ptr)) };
      if (!is_in(tmp, points, n)) {
        points[p].x = tmp.x;
        points[p].y = tmp.y;

        log << points[p].x << " " << points[p].y << '\n';
        p++;
      }
      else {
        log << "found doubles " << std::to_string(tmp.x) << " : " << std::to_string(tmp.y)<<'\n';
        n--;
      }
    }
  }
  std::fstream f("../../beauty_points.txt", std::fstream::out | std::fstream::trunc);
  for (int i = 0; i < n; i++) {
    f << points[i].x << " " << points[i].y << '\n';
  }
}

double distance(coord a, coord b) {
  double d = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
  return d;
}

bool is_equval(const coord& a, const coord& b) {
  return (a.x == b.x && a.y == b.y);
}

bool is_equval(const fig& figure, const coord& p) {
  return (is_equval(figure.first, p) || is_equval(figure.second, p) || is_equval(figure.third, p));
}

bool is_collinear(const coord& a, const coord& b, const coord& c) {
  return ((c.x - a.x) * (b.y - a.y) == (c.y - a.y) * (b.x - a.x));
}

void draw_all_points() {
  system("python ../../visualisation/draw_points.py");
}

void draw_figure(const fig& cur_figure) {
  std::string args = std::to_string(cur_figure.first.x) + ' ' + std::to_string(cur_figure.first.y) + ' ' +
    std::to_string(cur_figure.second.x) + ' ' + std::to_string(cur_figure.second.y) + ' ' +
    std::to_string(cur_figure.third.x) + ' ' + std::to_string(cur_figure.third.y) + ' ' +
    std::to_string(cur_figure.four.x) + ' ' + std::to_string(cur_figure.four.y) + ' ' +
    std::to_string(cur_figure.five.x) + ' ' + std::to_string(cur_figure.five.y);
  std::string command = "python ../../visualisation/draw_fig_with_points.py " + args;
  system(command.c_str());
}

void print_fig_coords(fig figure) {
  std::cout << "1: " << figure.first.x << " : " << figure.first.y << "\n" <<
    "2: " << figure.second.x << " : " << figure.second.y << "\n" <<
    "3: " << figure.third.x << " : " << figure.third.y << "\n" <<
    "4: " << figure.four.x << " : " << figure.four.y << "\n" <<
    "5: " << figure.five.x << " : " << figure.five.y << "\n" <<
    "sub_c: " << figure.sub_center.x << " : " << figure.sub_center.y << "\n\n";
}

void log_fig_coords(fig figure, std::fstream& log) {
  log<< "figure has "<<figure.inner_points_count<< " inner points\n" << "1: " << figure.first.x << " : " << figure.first.y << "\n" <<
    "2: " << figure.second.x << " : " << figure.second.y << "\n" <<
    "3: " << figure.third.x << " : " << figure.third.y << "\n" <<
    "4: " << figure.four.x << " : " << figure.four.y << "\n" <<
    "5: " << figure.five.x << " : " << figure.five.y << "\n" <<
    "sub_c: " << figure.sub_center.x << " : " << figure.sub_center.y << "\n\n";
}

unsigned find_inner_points(const coord* points, const fig & figure, int n, bool *is_inner) {
  //print_fig_coords(figure);
  unsigned count = 0;
  for (int i = 0; i < n; i++) {
    // проверка приинадлежности кругу
    double r = abs(distance(figure.first, figure.second));
    if (sqrt(pow(points[i].x - figure.second.x, 2) + pow(points[i].y - figure.second.y, 2)) <= r) {
      count++;
      is_inner[i] = true;
    }
    else if (sqrt(pow(points[i].x - figure.sub_center.x, 2) + pow(points[i].y - figure.sub_center.y, 2)) <= r) {
      count++;
      is_inner[i] = true;
    }
    else {
      double a = distance(figure.first, figure.third),
        b = distance(figure.first, figure.five);
      double S = a * b;
      double d1 = distance(points[i], figure.first),
        d2 = distance(points[i], figure.third),
        d3 = distance(points[i], figure.four),
        d4 = distance(points[i], figure.five);
      double p1 = (d1 + a + d2) / 2,
        p2 = (d2 + b + d3) / 2,
        p3 = (d3 + a + d4) / 2,
        p4 = (d4 + d1 + b) / 2;
      double s1 = sqrt(p1 * (p1 - a) * (p1 - d1) * (p1 - d2)),
        s2 = sqrt(p2 * (p2 - b) * (p2 - d3) * (p2 - d2)),
        s3 = sqrt(p3 * (p3 - a) * (p3 - d4) * (p3 - d3)),
        s4 = sqrt(p4 * (p4 - b) * (p4 - d1) * (p4 - d4));
      if (s1 + s2 + s3 + s4 == S) {
        count++;
        is_inner[i] = true;
      }
    }
  }
  return count;
}

fig find_max(int n, coord* points, std::fstream& log, bool*is_inner_mask,bool visualizate=false) {
  fig best_figure;
  for (int first = 0; first < n - 2; first++) {
    for (int second = first + 1; second < n - 1; second++) {
      if (is_equval(points[first], points[second]))
        continue;
      double ab = distance(points[first], points[second]);
      for (int third = second + 1; third < n; third++) {
        if (is_equval(points[first], points[third]) || is_equval(points[second], points[third]))
          continue;
        double bc = distance(points[second], points[third]);
        fig cur_figure;
        if (is_collinear(points[first], points[second], points[third])) {
          if (ab == bc) {
            cur_figure.first = points[first];
            cur_figure.second = points[second];
            cur_figure.third = points[third];
          }
          else if (ab == 0.5 * bc) {
            cur_figure.first = points[second];
            cur_figure.second = points[first];
            cur_figure.third = points[third];
          }
          else if (0.5 * ab == bc) {
            cur_figure.first = points[first];
            cur_figure.second = points[third];
            cur_figure.third = points[second];
          }
          else continue;
        }
        else continue;
        fig save_fig = cur_figure;

        for (int four = 0; four < n - 1; four++) {
          for (int five = four + 1; five < n; five++) {
            if (is_equval(cur_figure, points[four]) || is_equval(cur_figure, points[five]))
              continue;
            if (distance(cur_figure.first, cur_figure.third) != distance(points[four], points[five]) || 
              distance(cur_figure.first, points[five]) != distance(points[four], cur_figure.third))
              continue;
            coord four_point, five_point;
            if (distance(points[four], cur_figure.first) < distance(points[four], cur_figure.third)) {
              four_point = points[five];
              five_point = points[four];
            }
            else {
              four_point = points[four];
              five_point = points[five];
            }
            cur_figure.center.x = (cur_figure.first.x + four_point.x) / 2;
            cur_figure.center.y = (cur_figure.first.y + four_point.y) / 2;
            cur_figure.sub_center.x = (four_point.x + five_point.x) / 2;
            cur_figure.sub_center.y = (four_point.y + five_point.y) / 2;
            if (distance(cur_figure.center, cur_figure.first) == distance(cur_figure.center, cur_figure.third )) {
              cur_figure.four = four_point;
              cur_figure.five = five_point;
              bool* is_inner = new bool[n];
              for (int i = 0; i < n; i++) {
                is_inner[i] = false;
              }
              cur_figure.inner_points_count = find_inner_points(points, cur_figure, n, is_inner);
              log_fig_coords(cur_figure, log);
              if (visualizate)
                draw_figure(cur_figure);
              if (cur_figure.inner_points_count >= best_figure.inner_points_count) {
                for (int i = 0; i < n; i++) {
                  is_inner_mask[i] = is_inner[i];
                }
                best_figure = cur_figure;
              }
              delete[] is_inner;
              is_inner = nullptr;
            }

            cur_figure = save_fig;
          }
        }
      }
    }
  }
  return best_figure;
}

bool is_empty(const fig& figure) {
  return (figure.first.x == 0 && figure.first.y == 0 && figure.second.x == 0 && figure.second.y == 0);
}

void out_result(const fig& figure, std::fstream &out, coord*points, int n) {
  out << "read points: \n";
  for (int i = 0; i < n; i++) {
    out << points[i].x << " : " << points[i].y << '\n';
  }
  out << "best figure has " << figure.inner_points_count << " inner points\n" << "1: " << figure.first.x << " : " << figure.first.y << "\n" <<
    "2: " << figure.second.x << " : " << figure.second.y << "\n" <<
    "3: " << figure.third.x << " : " << figure.third.y << "\n" <<
    "4: " << figure.four.x << " : " << figure.four.y << "\n" <<
    "5: " << figure.five.x << " : " << figure.five.y << "\n" <<
    "sub_c: " << figure.sub_center.x << " : " << figure.sub_center.y << "\n\n";
}

int main()
{
  std::fstream in("../../input.txt");
  std::fstream out("../../output.txt", std::fstream::out | std::fstream::trunc);
  std::fstream log("../../log.txt", std::fstream::out | std::fstream::trunc);

  int n = get_n(in,log);
  log << "number of matching strings = " << n << '\n';

  bool VISUALIZATE = false;

  coord* points = new coord[n];
  read_points(in, points, n, log);
  fig best_figure;
  bool* is_inner = new bool[n];
  for (int i = 0; i < n; i++)
    is_inner[i] = false;

  if (n >= 5) {
    log << "n = " << n << '\n';
    best_figure = find_max(n, points, log, is_inner, VISUALIZATE);
  }
  else {
    log << "points count (n) < 5: " << n << '\n';
    out << "points count (n) < 5: " << n << '\n';
  }

  if (!is_empty(best_figure)) {
    out_result(best_figure, out, points,n);
    for (int i = 0; i < n; i++) {
      if (is_inner[i]) {
        out << points[i].x << " : " << points[i].y << "\n";
      }
    }
    draw_figure(best_figure);
  }
  else {
    log << "figure not found" <<'\n';
    out << "figure not found" <<'\n';
    if (n > 0) {
      draw_all_points();
    }
  }

  in.close();
  out.close();
  log.close();

  delete[] points;
  points = nullptr;
  delete[] is_inner;
  is_inner = nullptr;
}
