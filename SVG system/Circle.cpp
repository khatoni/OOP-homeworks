#include"Circle.h"
#include <limits>
Circle::Circle(const Point& p, String fill, double radius) : Shape(p, fill) {
	type = Type::circle;
	this->radius = radius;
}
std::ostream& operator<<(std::ostream& os, const Circle& obj) {
	os << "<circle cx=" << '"' << obj.p.getX() << '"' << " cy=" << '"' << obj.p.getY() << '"' << " r=" << '"' << obj.radius << '"' << " fill=" << '"' << obj.fill <<'"'<<"/>";
	return os;
}
void Circle::print()const {
	std::cout << "circle ";
	Shape::print();
	std::cout<<" "<<radius << " " << fill << std::endl;
} 
Shape* Circle::clone() {
	return new Circle(*this);
}
double Circle::getArea()const {
	return 3.1415 * radius * radius;
}
double Circle::getPerimeter()const {
	return 2 * 3.14 * radius;
}
const char* Circle::getType() const {
	return "Circle";
}
bool Circle::pointIn(const Point& tmp) const {
	return sqrt((tmp.getX() - p.getX()) * (tmp.getX() - p.getX()) + (tmp.getY() - p.getY() * (tmp.getY() - p.getY()))) <= radius;
}
bool Circle::within(const Shape* shape)const {
	if (strcmp(shape->getType(),"Circle")==0) {
		Circle* circ = (Circle*)(shape);
		double dist = sqrt((circ->p.getX() - p.getX()) * (circ->p.getX() - p.getX()) + (circ->p.getY() - p.getY()) * (circ->p.getY() - p.getY()));
		return dist + radius <= circ->radius;

	}
	else {
		Point up(p.getX(), p.getY() + radius);
		Point down(p.getX(), p.getY() - radius);
		Point left(p.getX() - radius, p.getY());
		Point right(p.getX() + radius, p.getY());
		return shape->pointIn(up) && shape->pointIn(down) && shape->pointIn(left) && shape->pointIn(right);
	}
}