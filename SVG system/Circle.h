#pragma once
#include "Shape.h"
class Circle: public Shape {
private:
	double radius;
public:
	
	Circle(const Point&, String, double);
	~Circle()=default;
	friend std::ostream& operator<<(std::ostream&, const Circle&);
	friend std::istream& operator>>(std::istream&, Circle&);
	void print()const override;
	const char* getType()const override;
	double getArea()const override;
	bool pointIn(const Point&)const override;
	bool within(const Shape*)const override;
	double getPerimeter()const override;
	Shape* clone()override;


};