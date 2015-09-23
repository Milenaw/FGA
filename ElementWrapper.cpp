/* 
 * File:   ElementWrapper.cpp
 * Author: benjamin
 * 
 * Created on September 23, 2015, 5:43 PM
 */

#include "ElementWrapper.h"
#include "Element.h"

ElementWrapper::ElementWrapper(Element& element): element(element) {
}

ElementWrapper::ElementWrapper(const ElementWrapper& orig): element(orig.element){
    
}

ElementWrapper::~ElementWrapper() {
}

