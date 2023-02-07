#pragma once
#include<iostream>
#include "Point.h"
#include "String.h"
class Shape{
protected:
	Point p;
	String fill;
public:
	enum Type {
		circle,
		rectangle,
		ellipse
	}type;
	Shape(const Point&, String);
	virtual ~Shape()=default;
	virtual Shape* clone() = 0;
	void translate(double, double);
	virtual const char* getType()const  = 0;
	virtual void print()const;
	virtual bool pointIn(const Point&) const = 0;
	virtual bool within(const Shape*)const = 0;
	virtual double getArea()const = 0;
	virtual double getPerimeter()const = 0;
	
};

