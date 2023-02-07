#pragma once
#include "Shape.h"
class Rectangle:public Shape
{
	double width;
	double heigth;

public:
	Rectangle(Point&, String, double, double);
	~Rectangle() = default;
	void print()const override;
	const char* getType()const override;
	double getArea()const override;
	double getPerimeter()const override;
	double getHeight()const;
	double getWidth()const;
	bool pointIn(const Point&)const override;
	bool within(const Shape*)const override;
	Shape* clone()override;
	friend std::ostream& operator<<(std::ostream&, const Rectangle&);
	friend std::istream& operator>>(std::istream&, Rectangle&);
};

