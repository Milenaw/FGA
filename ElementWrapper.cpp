/* 
 * File:   ElementWrapper.cpp
 * Author: benjamin
 * 
 * Created on September 23, 2015, 5:43 PM
 */


#include "ElementWrapper.h"
#include "Element.h"

ElementWrapper::ElementWrapper(const Element& element, int id): element(element), id(id) {
}

ElementWrapper::ElementWrapper(const ElementWrapper& orig): element(orig.element), id(orig.id){ 
}

ElementWrapper::~ElementWrapper() {
}

bool ElementWrapper::operator ==(const ElementWrapper& secound) const {
    
}

ElementWrapper& ElementWrapper::operator +(const ElementWrapper& secound) const {
    
}

bool ElementWrapper::calculate(const std::vector<ElementWrapper>* alle) {
    for (auto i : *alle) {
        bool temp = false;
        Element result(this->element, i.element);
        for (auto such : *alle) {
            if (result == such.element) {
                links.push_back(&such);
                temp = true;
            }
        }
        if (!temp) {
            return false; //Die Gruppe ist nicht abgeschlossen
        }
    }
}
