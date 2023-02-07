#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;;
}
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}
double Point::getX()const {
	return x;
}
double Point::getY()const {
	return y;
}
void Point::setX(double x) {
	this->x = x;
}
void Point::setY(double y) {
	this->y = y;
}
Point& Point::operator+=(const Point& other) {
	x += other.x;
	y += other.y;
	return *this;
}