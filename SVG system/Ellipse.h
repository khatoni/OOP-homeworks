#pragma once
#include "Shape.h"
class Ellipse:public Shape {

	double rx;
	double ry;
public:
	Ellipse(const Point&, String, double ,double);
	~Ellipse() = default;
	friend std::ostream& operator<<(std::ostream&, const Ellipse&);
	void print()const override;
	const char* getType()const override;
	double getArea()const override;
	bool pointIn(const Point&)const override;
	bool within(const Shape*)const override;
	double getPerimeter()const override;
	Shape* clone()override;

};

