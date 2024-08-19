#include "Point.hpp"

int main() {
	Point a(0, 2);
	Point b(0, 0);
	Point c(2, 0);
	// Point point(0.5f, 0.5f);
	Point point(2.0f, 2.0f);

	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}