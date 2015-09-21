/*
 * File:   Element.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:07 PM
 */

#include "Element.h"
#include "Gruppe.h"
#include <sstream>

using namespace std;

Element::Element() {
	this->number=0;
}
Element::Element(int number) {
    this->number = number;
}

string Element::toString(void) {
	int num=this->number;
	stringstream ss;
	ss<<num;
	string res;
	ss>>res;
	return res;
}

Element::Element(string str) {
	stringstream ss;
	ss<<str;
	int res=0;
	ss>>res;
	this->number=res;
}

bool Element::operator ==(const Element& secound) {
    return this->number == secound.number;
}

Element::Element(const Element& first,const Element& secound) {
    this->number = (first.number * secound.number) % 1009; //Das Stellt die Restklassen modulo 7 dar.
}

Element Element::operator *(const Element& secound) {
    return Element(*this, secound);
}

std::vector<Element> Element::getElements() { //Muss implementiert wird
    std::vector<Element> elemente;
    for (int i = 1; i < 1009; ++i) {
        Element element(i);
        elemente.push_back(element);
    }
    return elemente;
}