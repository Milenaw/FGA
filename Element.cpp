/*
 * File:   Element.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:07 PM
 */

#include "Element.h"
#include "Gruppe.h"
#include <sstream>
//#include <string>

using namespace std;

Element::Element(int number) {
    this->number = number;
}

string Element::toString() const {
    string text = "Restklasse: ";
    stringstream ss;
    ss<<this->number;
    string str;
    ss>>str;
    return text+=str;
    //return text +=to_string(this->number);
}

bool Element::operator ==(const Element& secound) const{
    return this->number == secound.number;
}

Element::Element(const Element& first,const Element& secound) {
    this->number = (first.number * secound.number) % 5; //Das Stellt die Restklassen modulo 19 dar.
}
