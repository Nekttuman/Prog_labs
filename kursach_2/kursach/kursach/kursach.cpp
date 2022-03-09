#include <iostream>
#include <string>
#include <fstream>

enum Themes {
	BIRDS,
	BICICLES,
	FISH,
	INSECTS,
	PRESIDENTS,
	SHIPS,
	DINOSAURS,
	BUILDINGS,
	MASHROOMS
};


class Stamp {
	std::string name;
	Themes theme;
	double price;
	bool is_canceled;
	bool is_exchangeable;
public:
	Stamp(std::string name, Themes theme, double price, bool is_canceled = false, bool is_exchangeable = true) :
		name(name), theme(theme), price(price), is_canceled(is_canceled), is_exchangeable(is_exchangeable) {}
	Stamp() {}

	void setName(const std::string& n) { name = n; }
	void setTheme(const Themes& t) { theme = t; }
	void setPrice(const double& p) { price = p; }
	void setCancellation(bool is_cancelled) { is_canceled = is_canceled; }
	void setExchangeability(bool is_exchangable) { is_exchangable = is_exchangeable; }

	friend std::istream& operator>>(std::istream& in, Stamp& stamp) {
		short theme_n;
		in >> stamp.name >> theme_n >> stamp.price >> stamp.is_canceled >> stamp.is_exchangeable;
		stamp.theme = Themes(theme_n);
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const Stamp& stamp) {
		out << stamp.name << ' ' << stamp.price << '\n' ;
		return out;
	}
};

class Collection {
	Stamp* stamps;
	short n;
public:
	Collection(short n = 0, Stamp* st = nullptr): n(n) {
		stamps = new Stamp[n];
		//if (stamps) 
	}
	friend std::istream& operator>>(std::istream& in, Collection& coll);
	friend std::ostream& operator<<(std::ostream& out, const Collection& coll);
};


int main() {
	std::fstream in("input.txt", 'r');

	Collection myColl(1);
	in >> myColl;
	std::cout << myColl;
}

std::istream& operator>>(std::istream& in, Collection& coll) {
	for (int i = 0; i < coll.n; i++) {
		in >> coll.stamps[i];
	}
	return in;
}


std::ostream& operator<<(std::ostream& out, const Collection& coll) {
	for (int i = 0; i < coll.n; i++) {
		out << coll.stamps[i];
	}
	return out;
}


