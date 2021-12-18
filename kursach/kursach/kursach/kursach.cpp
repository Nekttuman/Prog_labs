#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

struct coord {
  double x;
  double y;
};

struct fig {
  coord first;
  coord second;
  coord third;
  coord four;
  coord five;
  coord center;
  coord sub_center;
};

bool check_line(std::string l) {
  bool has_first_n = false, has_one_whitespace = false, has_second_digit = false,
    has_smth_else = false;
  for (int ch = 0; ch < l.size(); ch++) {
    if ((isdigit(l[ch]) || l[ch] == '-' || l[ch] == '.') && !has_first_n) {
      has_first_n = true;
    }
    else if ((isdigit(l[ch]) || l[ch] == '-' || l[ch] == '.') && has_one_whitespace && !has_second_digit) {
      has_second_digit = true;
    }
    else if (l[ch] == ' ' && !has_first_n) {
      has_smth_else = true;
      break;
    }
    else if (l[ch] == ' ' && has_first_n && !has_one_whitespace) {
      has_one_whitespace = true;
    }
    else if (l[ch] == ' ' && has_first_n && has_one_whitespace && !has_second_digit) {
      has_one_whitespace = false;
    }
    else if (l[ch] == ' ' && has_first_n && has_one_whitespace && has_second_digit) {
      has_smth_else = true;
      break;
    }
    else if (l[ch] != ' ' and !(isdigit(l[ch]) || l[ch] == '-' || l[ch] == '.')) {
      has_smth_else = true;
      break;
    }
  }
  return (has_first_n && has_one_whitespace && has_second_digit && !has_smth_else);
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

void read_points(std::fstream& in, coord* points, int &n, std::fstream &log) {
  int p = 0;
  std::string line;
  log << "readen points: \n";
  while (!in.eof()) {
    std::getline(in, line);
    if (check_line(line)) {
      int space_ptr;
      for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
          space_ptr = i;
          break;
        }
      }
      points[p].x = stod(line.substr(0, space_ptr));
      points[p].y = stod(line.substr(space_ptr, line.size()));
      log << points[p].x << " " << points[p].y << '\n';
      p++;
    }
  }
}

double distance(coord a, coord b) {
  double d = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
  return d;
}

bool is_equval(const coord& a, const coord& b) {
  return (a.x == b.x && a.y == b.y);
}

bool is_collinear(const coord& a, const coord& b, const coord& c) {
  return ((c.x - a.x) * (b.y - a.y) == (c.y - a.y) * (b.x - a.x));
}

bool is_equval(const fig& figure, const coord& p) {
  return (is_equval(figure.first, p) || is_equval(figure.second, p) || is_equval(figure.third, p));
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


double find_inner_points(const coord* points, const fig & figure, int n, coord* inner_points) {
  unsigned count = 0;
  for (int i = 0; i < n; i++) {
    // проверка приинадлежности кругу
    double r = abs(distance(figure.first, figure.second));
    if (sqrt(pow(points[i].x - figure.second.x, 2) + pow(points[i].y - figure.second.y, 2)) <= r) {
      count++;
    }
    else if (sqrt(pow(points[i].x - figure.sub_center.x, 2) + pow(points[i].y - figure.sub_center.y, 2)) <= r) {
      count++;
    }
    else if ()
  }
  return count;
}

void find_max(int n, coord* points) {
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
            if (distance(cur_figure.first, cur_figure.third) != distance(points[four], points[five]))
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
            cur_figure.sub_center.x = (cur_figure.four.x + cur_figure.five.x) / 2;
            cur_figure.sub_center.y = (cur_figure.four.y + cur_figure.five.y) / 2;
            if (distance(cur_figure.center, cur_figure.first) == distance(cur_figure.center, cur_figure.third)) {
              cur_figure.four = four_point;
              cur_figure.five = five_point;
              draw_figure(cur_figure);
              coord* inner_points;
              double inner_points = find_inner_points(points, cur_figure, n, inner_points);
            }

            cur_figure = save_fig;
          }
        }
      }
    }
  }
}

int main()
{
  std::fstream in("../../input.txt");
  std::fstream out("../../output.txt", std::fstream::out | std::fstream::trunc);
  std::fstream log("../../log.txt", std::fstream::out | std::fstream::trunc);
  int n = get_n(in,log);
  log << "number of matching strings = " << n << '\n';



  coord* points = new coord[n];
  read_points(in, points, n, log);
  log << "n = " << n << '\n';

  find_max(n, points);

}

