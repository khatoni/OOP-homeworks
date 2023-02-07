#include "Circle.h"
#include "Rectangle.h"
#include <fstream>
#include "functions.h"
#include "Collection.h"
const int MAX_SIZE = 100;
size_t strLen(char* str1) {
	int pos = 0;
	while (str1[pos] != '\0') {
		pos++;
	}
	return pos;
}
size_t getIndexOfOpening(char* str) {
	int i = 0;
	while (str[i] !='<' && i<strLen(str)) {
		i++;
	}
	return i;
}
size_t getIndexOfClosing(char* str,size_t indexofopening) {
	int i = indexofopening;
	while (str[i] != '>' && i < strLen(str)) {
		i++;
	}
	return i;
}
char* getTag(char* str, size_t indexOpening, size_t indexClosing) {
	size_t size = 0;
	char* tmp = new char[300];
	for (int i = indexOpening; i < indexClosing; i++) {
		tmp[size] = str[i];
		size++;
	}
	tmp[size] = '\0';
	return tmp;
}
char* parseTypeOfFigure(const char* str) {
	char* tmp = new char[111];
	int i = 0;
	size_t size = strlen(str);
	while (str[i] != ' '&&i<size) {
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return tmp;
}
size_t getIndexofOpenComma(char* str,size_t start) {
	int i = start;
	while (str[i] != '"' && i < strLen(str)) {
		i++;
	}
	return i;
}
size_t getIndexofClosingComa(char* str, size_t start) {
	int i = start+1;
	while (str[i] != '"' && i < strLen(str)) {
		i++;
	}
	return i;
}
double power(double a, int power) {
	int counter = 0;
	while (counter < power) {
		a = a * a;
		counter++;
	}
	return 1.0 / a;
}
double parseToDouble(char* str) {
	double number = 0;double remain = 0;
	int i = 0;
	if (str[0] != '-') {
		while (str[i] != '.' && i < strLen(str)) {
			number = number * 10 + (int)(str[i] - '0');
			i++;
		}
		if (str[i] == '.') {
			i++;
			int counter = 0;

			while (str[i] != '\0') {
				remain = remain * 10 + (int)(str[i] - '0');
				i++;
				counter++;
			}
			for (int i = 0; i < counter; i++) {
				remain /= 10;
			}
		}
		number += remain;
	}
	else {
		i++;
		while (str[i] != '.' && i < strLen(str)) {
			number = number * 10 + (int)(str[i] - '0');
			i++;
		}
		if (str[i] == '.') {
			i++;
			int counter = 0;

			while (str[i] != '\0') {
				remain = remain * 10 + (int)(str[i] - '0');
				i++;
				counter++;
			}
			for (int i = 0; i < counter; i++) {
				remain /= 10;
			}
		}
		number += remain;
		number *= -1;
	}
	return number;
}
Circle* createCircle(char* str) {
	size_t current = 0;
	double arr[3];
	for (int i = 0; i < 3; i++) {
			size_t op = getIndexofOpenComma(str, current);
			size_t end = getIndexofClosingComa(str, op);
			current = end + 1;
			char* number=getTag(str, op + 1, end);
			arr[i] = parseToDouble(number);
			delete[]number;
	}
	
	Point p(arr[0],arr[1]);
	double r = arr[2];
	size_t first = getIndexofOpenComma(str, current);
	size_t second = getIndexofClosingComa(str, first);
	
	char* colour = getTag(str, first + 1, second);
	String fill(colour);
	Circle *obj=new Circle(p, fill, r);
	delete[] colour;
	return obj;
}
Rectangle *createRectangle(char* str) {
	size_t current = 0;
	double arr[4];
	for (int i = 0; i < 4; i++) {
		size_t op = getIndexofOpenComma(str, current);
		size_t end = getIndexofClosingComa(str, op);
		current = end + 1;
		char* number = getTag(str, op + 1, end);
		arr[i] = parseToDouble(number);
		delete[]number;

	}
	Point p(arr[0], arr[1]);
	double width = arr[2];
	double height = arr[3];
	size_t first = getIndexofOpenComma(str, current);
	size_t second = getIndexofClosingComa(str, first);

	char* colour = getTag(str, first + 1, second);
	String fill(colour);
	Rectangle *obj=new Rectangle(p, fill, width,height);
	delete[] colour;
	return obj;
}

char* parseFirstPart(char* str) {
	int i = 0;
	char* result = new char[MAX_SIZE];
	while (str[i] != '\0' && str[i] != ' ') {
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return result;
}
char* parseSecondPart(char* str) {
	int i = 0;
	while (str[i] != ' ' && str[i] != '\0') {
		i++;
	}
	i++;
	char* result = new char[MAX_SIZE];
	int size = 0;
	while (str[i] != ' ' && str[i] != '\0') {
		result[size] = str[i];
		size++;
		i++;
	}
	result[size] = '\0';
	return result;
}
char* parseThirdPart(char* str) {
	int i = 0;
	while (str[i] != ' ' && str[i] != '\0') {
		i++;
	}
	i++;
	while (str[i] != ' ' && str[i] != '\0') {
		i++;
	}
	i++;
	char* result = new char[MAX_SIZE];
	int size = 0;
	while (str[i] != '\0') {
		result[size] = str[i];
		size++;
		i++;
	}
	result[size] = '\0';
	return result;
}
bool saveToFileAll(char* filename, const Collection& list) {
	std::ofstream outFile(filename);
	outFile<<"<svg xmlns = \"http://www.w3.org/2000/svg\" version = \"1.1\">"<<std::endl;
	outFile << list;
	outFile << "</svg>";
	if (outFile.good() == 1) {
		return true;
	}
	else {
		return false;
	}
	outFile.close();
}
Ellipse *createEllipse(char* str) {
	size_t current = 0;
	double arr[4];
	for (int i = 0; i < 4; i++) {
		size_t op = getIndexofOpenComma(str, current);
		size_t end = getIndexofClosingComa(str, op);
		current = end + 1;
		char* number = getTag(str, op + 1, end);
		arr[i] = parseToDouble(number);
		delete[]number;

	}
	Point p(arr[0], arr[1]);
	double rx = arr[2];
	double ry = arr[3];
	size_t first = getIndexofOpenComma(str, current);
	size_t second = getIndexofClosingComa(str, first);

	char* colour = getTag(str, first + 1, second);
	String fill(colour);
	Ellipse *obj=new Ellipse(p, fill, rx, ry);
	delete[] colour;
	return obj;
}
Point createPoint(char* str) {
	char* x = parseSecondPart(str);
	char* y = parseThirdPart(str);
	Point p(parseToDouble(x), parseToDouble(y));
	delete[]x;
	delete[]y;
	return p;
}
char* addCommas(char* tmp)
{
	char* toCreate = new char[100];
	size_t final_size = 0;
	toCreate[final_size++] = '"';

	for (size_t i = 0; i < strlen(tmp); i++) {
		if (tmp[i] != ' ') {
			toCreate[final_size++] = tmp[i];
		}
		if (tmp[i] == ' ') {
			toCreate[final_size++] = '"';
			toCreate[final_size++] = ' ';
			toCreate[final_size++] = '"';
		}
	}
	toCreate[final_size++] = '"';
	toCreate[final_size] = '\0';
	return toCreate;
}

