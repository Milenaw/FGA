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

string Element::toString() const {
    string text = "Restklasse: ";
    return text += std::to_string(this->number);
}

bool Element::operator ==(const Element& secound) const{
    return this->number == secound.number;
}

Element::Element(const Element& first,const Element& secound) {
    this->number = (first.number + secound.number) % 5; //Das Stellt die Restklassen modulo 19 dar.
}

void Element::fill(Gruppe& gruppe) {
    for (int i = 0; i < 5 ; ++i) {
        Element add(i);
        gruppe.addElement(add);
    }
}