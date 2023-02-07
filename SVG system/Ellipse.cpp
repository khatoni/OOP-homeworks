#include "Ellipse.h"

Ellipse::Ellipse(const Point& p, String fill, double rx, double ry) :Shape(p, fill) {
	this->rx = rx;
	this->ry = ry;
}
std::ostream& operator<<(std::ostream& os, const Ellipse& obj) {
	os << "<ellipse x=" << '"' << obj.p.getX() << '"' << " y=" << '"' << obj.p.getY() << '"' << " rx=" << '"' << obj.rx << '"' << " ry=" << '"' << obj.ry<<'"'<< " fill=" << '"' << obj.fill << '"' << "/>";
	return os;
}
void Ellipse::print()const {
	std::cout << "ellipse ";
	Shape::print();
	std::cout << " " << rx << " " <<ry<< " "<<fill << std::endl;
}
Shape* Ellipse::clone() {
	return new Ellipse(*this);
}
double Ellipse::getArea()const {
	return 3.1415 * rx * ry;
}
double Ellipse::getPerimeter()const {
	return  3.1415 * (rx+ry);
}

const char* Ellipse::getType() const {
	return "Ellipse";
}
bool Ellipse::pointIn(const Point& tmp) const {
	return ((tmp.getX() - p.getX())*(tmp.getX() - p.getX()) / (rx * rx) + (tmp.getY() - p.getY())* (tmp.getY() - p.getY()) / (ry * ry)) <= 1;
}
bool Ellipse::within(const Shape* shape)const {
	Point up(p.getX(), p.getY() + ry);
	Point down(p.getX(), p.getY() -ry);
	Point left(p.getX() - rx, p.getY());
	Point right(p.getX() + rx, p.getY());
	return shape->pointIn(up) && shape->pointIn(down) && shape->pointIn(left) && shape->pointIn(right);
}
