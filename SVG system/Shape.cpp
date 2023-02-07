#include "Shape.h"
Shape::Shape(const Point& p, String fill) {
	this->p = p;
	this->fill = fill;
}
void Shape::print()const {
	std::cout << p.getX() << " " << p.getY();
}
void Shape::translate(double x, double y) {
	Point tmp(y, x);
	p += tmp;
}