#pragma once
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Ellipse.h"
class Collection
{
private:
	Shape** shapes;
	size_t capacity;
	size_t count;
public:
	Collection();
	Collection(size_t capacity);
	Collection(const Collection&);
	Collection& operator=(const Collection&);
	~Collection();
	void addShape(Shape* shape);
	bool erase(size_t);
	void print()const;
	void printAreas()const;
	void printPers()const;
	size_t getCount()const;
	void translateAll(double,double);
	void translate(size_t,double,double);
	void pointsIn(const Point&);
	void within(const Shape*)const;
	const char* getType(size_t)const;
	friend std::ostream& operator<<(std::ostream&,const Collection&);
private:
	void copy(const Collection&);
	void free();
	void resize();
};

