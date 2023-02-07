#pragma once
#include "Collection.h"
#include "Shape.h"
#include "Ellipse.h"

size_t strLen(char* );
size_t getIndexOfOpening(char* );
size_t getIndexOfClosing(char* , size_t start);
char* getTag(char*, size_t, size_t);
char* parseTypeOfFigure(const char* str);
size_t getIndexofOpenComma(char* str, size_t current_index);
size_t getIndexofClosingComa(char* str, size_t start);
double power(double, int);
double parseToDouble(char* str);
Circle* createCircle(char* str);
Rectangle* createRectangle(char* str);
Ellipse* createEllipse(char* str);
char* parseFirstPart(char* str);
char* parseSecondPart(char* str);
char* parseThirdPart(char* str);
bool saveToFileAll(char*,const Collection&);
Point createPoint(char* str);
char* addCommas(char*);

