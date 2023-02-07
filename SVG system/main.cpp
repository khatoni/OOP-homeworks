#include<iostream>
#include<fstream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "functions.h"
#include "Collection.h"
#include "Ellipse.h"

const int MAX = 256;

int main() {
	
	std::cout << "Enter a filepath: ";
	char filepath[MAX];
	std::cin.getline(filepath,MAX);
	std::ifstream inFile(filepath);

	if (!inFile.is_open()) {
		std::cout << "Unable to load the file!\n";
		return -1;
	}

	std::cout << "Successfully opened "<<filepath<<std::endl;
	Collection list;

	while (!inFile.eof()) {
		char buffer[MAX];
		inFile.getline(buffer, MAX);
		size_t start = getIndexOfOpening(buffer);
		size_t end = getIndexOfClosing(buffer, start);
		char* tag = getTag(buffer, start + 1, end);
		char* figure = parseTypeOfFigure(tag);

		if (strcmp(figure, "rect") == 0) {
			Rectangle *obj = createRectangle(tag);
			list.addShape(obj);
			delete obj;
		}

		if (strcmp(figure, "circle") == 0) {
				Circle *obj = createCircle(tag);
				list.addShape(obj);
				delete obj;
		}

		if(strcmp(figure,"ellipse")==0){
			Ellipse *obj = createEllipse(tag);
			list.addShape(obj);
			delete obj;
		}

		if (strcmp(tag, "/svg") == 0) {
			delete[]tag;
			delete[]figure;
			break;
		}

		delete[]figure;
		delete[]tag;
		
	}
	inFile.close();
	
	std::cout << "Enter command: "<<std::endl;

	while (true) {

		char command[MAX];
		
		std::cin.getline(command, MAX);
		char* first = parseFirstPart(command);

		if (strcmp(first, "print") == 0) {
			list.print();
		}

		if (strcmp(first, "create") == 0) {
			char* second = parseSecondPart(command);

			if (strcmp(second, "rectangle") == 0) {
				char* tmp = parseThirdPart(command);
				char* toCreate = addCommas(tmp);
				Rectangle *rect=createRectangle(toCreate);
				std::cout << "Successfully create rectangle:" << std::endl;
				list.addShape(rect);
				delete[]tmp;
				delete[]toCreate;
				delete rect;
			}

			if (strcmp(second, "circle") == 0){
				char* tmp = parseThirdPart(command);
				char* toCreate = addCommas(tmp);
				Circle *circ = createCircle(toCreate);
				std::cout << "Successfully created circle: " << std::endl;
				list.addShape(circ);
				delete[] tmp;
				delete[] toCreate;
				delete circ;
			}

			if (strcmp(second, "ellipse") == 0) {
				char* tmp = parseThirdPart(command);
				char* toCreate = addCommas(tmp);
				Ellipse *el = createEllipse(toCreate);
				std::cout << "Successfully created ellipse: " << std::endl;
				list.addShape(el);
				delete[] tmp;
				delete[] toCreate;
				delete el;
			}

			delete[]second;
		}

		if (strcmp(first, "erase") == 0) {
			char* second = parseSecondPart(command);
			size_t index=parseToDouble( second);
			
			if (index > list.getCount()) {
				std::cout<< "There is no figure number " << index << std::endl;
			}
			else {
				index--;
				const char* type = list.getType(index);

				if (list.erase(index) == 0) {
					std::cout << "There is no figure number " << index << std::endl;
				}

				else {
					std::cout << "Erased a " << type << std::endl;
				}
			}
			delete[]second;
		}

		if (strcmp(first, "save") == 0) {

			if (saveToFileAll(filepath, list)) {
				std::cout << "Successfully saved into file: " << std::endl;
			}
			else {
				std::cout << "Problem while saving into file: " << std::endl;
			}
		}

		if (strcmp(first, "PointIn") == 0) {
			Point p = createPoint(command);
			list.pointsIn(p);
		}

		if (strcmp(first, "translate") == 0) {
			std::cout << "Enter an index:-1 for all or specific index: ";
			int index;
			std::cin >> index;
			std::cout << "vertical:";
			double x;
			double y;
			std::cin >> x;
			std::cout << std::endl;
			std::cout << "horizontal: ";
			std::cin >> y;
			std::cout << std::endl;
			Point p(x, y);

			if (index == -1) {
				list.translateAll(x, y);
				std::cout << "Translated all figures: " << std::endl;
			}

			else {
				list.translate( index, x, y);
				std::cout << "Translated figure number " << index << std::endl;
			}
		}

		if(strcmp(first, "within") == 0) {
			char* second = parseSecondPart(command);

			if (strcmp(second, "circle") == 0) {
				char* str = parseThirdPart(command);
				char* toCreate = addCommas(str);
				Circle *circle = createCircle(toCreate);
				list.within(circle);
				delete circle;
				delete[]toCreate;
				delete[]str;
			}

			if (strcmp(second, "rectangle") == 0) {
				char* str = parseThirdPart(command);
				char* toCreate = addCommas(str);
				Rectangle* rect = createRectangle(toCreate);
				list.within(rect);
				delete rect;
				delete[]str;
				delete[]toCreate;
			}
			delete[]second;

		}

		if (strcmp(first, "Areas") == 0) {
			list.printAreas();	
		}

		if (strcmp(first, "Pers") == 0) {
			list.printPers();
			
		}

		if (strcmp(first, "quit") == 0) {
			delete[]first;
			return 1;
		}
		
		delete[]first;
	}
	return 0;
}