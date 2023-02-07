#include "Rectangle.h"
Rectangle::Rectangle(Point&p,String fill, double width,double height):Shape(p,fill) {
	type = Type::rectangle;
	this->width = width;
	this->heigth = height;
}
void Rectangle::print()const {
	std::cout << "rectangle ";
	Shape::print();
	std::cout<<" "<<width << " " << heigth << " " << fill << std::endl;
}
double Rectangle::getArea()const {
	return width * heigth;
}
double Rectangle::getPerimeter()const {
	return 2 * (width + heigth);
}
Shape* Rectangle::clone() {
	return new Rectangle(*this);
}
const char* Rectangle:: getType()const  {
	return "Rectangle";
}
bool Rectangle::pointIn(const Point& tmp)const {
	Point p1(p.getX() +width, p.getY()-heigth);
	return tmp.getX() >= p.getX() && tmp.getX() <= p1.getX() && tmp.getY() <= p.getY() && tmp.getY() >= p1.getY();
}
std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
	os << "<rect x=" << '"' << obj.p.getX() << '"' << " y=" << '"' << obj.p.getY() << '"' << " width=" << '"' << obj.width << '"' <<" height="<<'"'<< obj.heigth <<'"' << " fill=" << '"' << obj.fill << '"' << "/>";
	return os;
}
double Rectangle::getHeight()const {
	return heigth;
}
double Rectangle::getWidth()const {
	return width;
}
bool Rectangle::within(const Shape* shape)const {

	Point ld(p.getX(), p.getY() - heigth);
	Point rd(p.getX() + width, p.getY() - heigth);
	Point rup(p.getX() + width, p.getY());
	return shape->pointIn(p) && shape->pointIn(ld) && shape->pointIn(rd) && shape->pointIn(rup);
}