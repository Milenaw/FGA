/* 
 * File:   ElementWrapper.cpp
 * Author: benjamin
 * 
 * Created on September 23, 2015, 5:43 PM
 */
#include <iostream>

#include "ElementWrapper.h"
#include "Element.h"

ElementWrapper::ElementWrapper(const Element& element, int id): element(element), id(id) {
}

ElementWrapper::ElementWrapper(const ElementWrapper& orig): element(orig.element), id(orig.id){ 
    if (orig.links.size() != 0) {
        std::cerr << "Fehler, EW kopiert, Links Liste verloren gegangen " << orig.links.size() << std::endl;
    }
}

ElementWrapper& ElementWrapper::operator =(const ElementWrapper& left) {
    
    //std::cout << "Ich werde zugewiesen" << std::endl;
    
    return *this;
}

ElementWrapper::~ElementWrapper() {
}

bool ElementWrapper::operator ==(const ElementWrapper& secound) const {
    return this->id == secound.id;
}

const ElementWrapper& ElementWrapper::operator +(const ElementWrapper& secound) const {
    return *(this->links[secound.id]);
}

bool ElementWrapper::calculate(const std::vector<ElementWrapper>* alle) {
    for (auto& i : *alle) {
        bool temp = false;
        Element result(this->element, i.element);
        for (int such = 0; such < alle->size() ; ++such) {
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

string ElementWrapper::toString() const{
    return element.toString();
}