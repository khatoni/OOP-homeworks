#pragma once
class Point
{
	double x;
	double y;
public:
	Point();
	Point(double, double);

	void setX(double);
	void setY(double);
	double getX()const;
	double getY()const;
	Point& operator+=(const Point&);
};

