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
    //std::cout << "Ich werde kopiert" << std::endl;
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
    //std::cout << this->links.at(secound.id) << std::endl;
    return *(this->links[secound.id]);
}

bool ElementWrapper::calculate(const std::vector<ElementWrapper>* alle) {
    for (EW i : *alle) {
        bool temp = false;
        Element result(this->element, i.element);
        for (int such = 0; such < alle->size() ; ++such) {
            if (result == (alle->at(such)).element) {
                const EW* adresse = &(alle->at(such));
                //std::cout << adresse << std::endl;
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
