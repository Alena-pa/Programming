#pragma once
#include <stdbool.h>

//Checking if an element was added correctly
bool testAddElement();

//Checking the correctness of the element location
bool testFindNodeByKey();

//Checking for correctness of element existence check
bool testExistenceOfElement();

//Checking if an element without children was deleted correctly
bool testDeleteElementWithoutChildrens();

//Checking if deleting an element with one child is correct
bool testDeleteElementWithOneChildren();

//Checking if deleting an element with multiple children is correct
bool testDeleteElementWithManyChildrens();

//Combining tests
bool allTests();