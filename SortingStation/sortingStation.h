#pragma once

// checks if element operation or not
bool isOperation(char element);

// checks if element is digit or not
bool isDigit(char element);

// defines operator priority
int precedence(char element);

// convert string to postfix notation
void convertStringFromInfixToPostfixNotation(const char* stringToConvert, char* outputString, int* errorCode);