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
}

ElementWrapper::~ElementWrapper() {
}

bool ElementWrapper::operator ==(const ElementWrapper& secound) const {
    return this->id == secound.id;
}

ElementWrapper& ElementWrapper::operator +(const ElementWrapper& secound) const {
    std::cout << this->links[secound.id] << std::endl;
    return *this->links[secound.id];
}

bool ElementWrapper::calculate(const std::vector<ElementWrapper>* alle) {
    for (EW i : *alle) {
        bool temp = false;
        Element result(this->element, i.element);
        for (EW such : *alle) {
            if (result == such.element) {
                std::cout << &such << std::endl;
                links.push_back(&such);
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
