#include "Collection.h"
void Collection::copy(const Collection& other) {
	count = other.count;
	capacity = other.capacity;
	shapes = new Shape * [other.capacity];
	
	for (int i = 0; i < count; i++) {
		shapes[i] = other.shapes[i]->clone();
	}

}
void Collection::free() {

	for (size_t i = 0; i < count; i++) {
		delete shapes[i];
	}
	delete[] shapes;
	capacity = count = 0;
}
void Collection::resize() {
	Shape** newshapes = new Shape*[capacity *= 2];
	for (size_t i = 0; i < count; i++) {
		newshapes[i] = shapes[i];
	}
	delete[]shapes;
	shapes = newshapes;
}
void Collection::addShape( Shape* other) {

	if (count == capacity) {
		resize();
	}
	shapes[count++] = other->clone();
}
Collection::Collection() {
	capacity = 4;
	count = 0;
	shapes = new Shape * [capacity];
}
Collection::Collection(const Collection& other) {
	copy(other);
}
Collection& Collection::operator=(const Collection& other) {

	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}
Collection::~Collection() {
	free();
}
void Collection::print()const {
	for (int i = 0; i < count; i++) {
		std::cout<<i+1 << ".";
		shapes[i]->print();
	}
}
void Collection::printAreas()const {
	for (int i = 0; i < count; i++) {
		std::cout << i + 1 << " Area:" << shapes[i]->getArea()<<std::endl;
	}
}
void Collection::printPers()const {
	for (int i = 0; i < count; i++) {
		std::cout << i + 1 << " Per:" << shapes[i]->getPerimeter() << std::endl;
	}
}bool Collection::erase(size_t index) {
	if (index >= count) {
		return false;
	}
	delete shapes[index];
	shapes[index] = nullptr;
	for (size_t i = index; i < count-1; i++) {
		shapes[i] = shapes[i + 1];
	}
	count--;
	return true;
}
size_t Collection::getCount()const {
	return count;
}
void Collection::translateAll(double x,double y){
	for (size_t i = 0; i < count; i++) {
		shapes[i]->translate(x, y);
	}
}
void Collection::translate(size_t index, double x,double y) {
	index--;
	shapes[index]->translate(x, y);
}
const char* Collection::getType(size_t index)const{
	return shapes[index]->getType();
}
std::ostream& operator<<(std::ostream& os, const Collection& list) {
	for (int i = 0; i < list.count; i++) {
		if (list.shapes[i]->getType() == "Circle") {
			Circle* c = (Circle*)(list.shapes[i]);
			os << *c<<std::endl;
			
		}
		else if (list.shapes[i]->getType() == "Rectangle") {
			Rectangle* r = (Rectangle*)(list.shapes[i]);
			os << *r << std::endl;
			
		}
		else if (list.shapes[i]->getType() == "Ellipse")
		{
			Ellipse* el = (Ellipse*)(list.shapes[i]);
			os << *el << std::endl;
			
		}
	}
	return os;
}
void Collection::pointsIn(const Point& p) {
	for (size_t i = 0; i < count; i++) {
		if (shapes[i]->pointIn(p)) {
			shapes[i]->print();
		}
	}
}
void Collection::within(const Shape* shape)const {
	for (size_t i = 0; i < count; i++) {
		if (shapes[i]->within(shape)) {
			shapes[i]->print();
		}
	}
}