/* 
 * File:   ElementWrapper.cpp
 * Author: benjamin
 * 
 * Created on September 23, 2015, 5:43 PM
 */

#include "ElementWrapper.h"
#include "Element.h"

ElementWrapper::ElementWrapper(Element* element): element(*element) {
}

ElementWrapper::ElementWrapper(const ElementWrapper& orig): element(orig.element){ 
}

ElementWrapper::~ElementWrapper() {
}

bool ElementWrapper::operator ==(const ElementWrapper& secound) const {
    return this->element == secound.element;
}

ElementWrapper* ElementWrapper::operator +(const ElementWrapper& secound) const {
    return new ElementWrapper(new Element(this->element, Element(secound.element)));
}
