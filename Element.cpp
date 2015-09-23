/*
 * File:   Element.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:07 PM
 */

#include "Element.h"
#include "Gruppe.h"

using namespace std;

Element::Element(int number) {
    this->number = number;
}

string Element::toString() {
    string text = "Restklasse: ";
    return text += toString(this->number);
}

Element::Element(string str) {
    this->number = stoi(str);
}

string Element::serialize() {
    return this->toString();
}

bool Element::operator ==(const Element& secound) {
    return this->number == secound.number;
}

Element::Element(const Element& first,const Element& secound) {
    this->number = (first.number * secound.number) % 1009; //Das Stellt die Restklassen modulo 7 dar.
}