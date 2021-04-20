#include <iostream>
#include<vector>

class Mn {
public:
	Mn() = default;
	~Mn() = default;
	bool is_inside(int rhs);
	void add(int rhs);
	void pop(int rhs);
	void writeAll();
private:
	std::vector<bool>data_ = std::vector<bool>(1000,0);
};

int main() {
	Mn a;
	a.add(8);
	a.add(9);
	a.add(456);
	a.add(789);
	a.writeAll();
	std::cout << std::endl;
	a.pop(8);
	a.writeAll();
	std::cout << a.is_inside(78) << ' ' << a.is_inside(9);
}

bool Mn::is_inside(int rhs) {
	if (rhs < 1000) {
		return data_[rhs];
	}
	else {
		std::cout << "out of range" << std::endl;
	}
}

void Mn::add(int rhs) {
	if (rhs < 1000) {
		data_[rhs] = 1;
	}
	else {
		std::cout << "out of range" << std::endl;
	}
}
void Mn::pop(int rhs) {
	if (rhs < 1000) {
		data_[rhs] = 0;
	}
	else {
		std::cout << "out of range" << std::endl;
	}
}
void Mn::writeAll() {
	for (std::ptrdiff_t i = 0; i < 1000; i++) {
		if (data_[i]) {
			std::cout << i << ' ';
		}
	}
}