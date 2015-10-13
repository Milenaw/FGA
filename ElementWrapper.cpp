/* 
 * File:   ElementWrapper.cpp
 * Author: benjamin
 * 
 * Created on September 23, 2015, 5:43 PM
 */
#include <iostream>

#include "ElementWrapper.h"
#include "Element.h"

ElementWrapper::ElementWrapper(const Element& element, int id) : element(element), id(id) {
}

ElementWrapper::ElementWrapper(const ElementWrapper& orig) : element(orig.element), id(orig.id) {
    if (orig.links.size() != 0) {
        std::cerr << "Fehler, EW kopiert, Links Liste verloren gegangen " << orig.links.size() << std::endl;
    }
}

ElementWrapper::~ElementWrapper() {
}

bool ElementWrapper::operator==(const ElementWrapper& second) const {
    return this->id == second.id;
}

bool ElementWrapper::operator==(const Element& second) const {
    return this->element == second;
}

const ElementWrapper& ElementWrapper::operator+(const ElementWrapper& second) const {
    return *(this->links[second.id]);
}

const ElementWrapper& ElementWrapper::operator-(const ElementWrapper& second) const {
    return *(this->links[second.inverse->id]);
}

bool ElementWrapper::calculate(const std::vector<ElementWrapper>* alle) {
    for (auto& i : *alle) {
        bool temp = false;
        Element result(this->element, i.element);
        for (unsigned int such = 0; such < alle->size(); ++such) {
            if (result == (alle->at(such)).element) {
                const EW* adresse = &(alle->at(such));
                links.push_back(adresse);
                temp = true;
                break;
            }
        }
        if (!temp) {
            return false; //Die Gruppe ist nicht abgeschlossen
        }
    }
    return true;
}

string ElementWrapper::toString() const {
    return element.toString();
}

EW& EW::getInverse() const {
    return *inverse;
}

void EW::setInverse(ElementWrapper& inverse) {
    this->inverse = &inverse;
}

int EW::getId() {
    return id;
}

int EW::calcOrder(EW& e) {
    const EW* temp = this;
    int counter = 1;
    while(!(*temp == e)) {
        temp = &(*temp + *this);
        counter++;
    }
    this->order = counter;
    return counter;
}