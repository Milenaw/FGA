/*
 * File:   Gruppe.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:11 PM
 */

#include <bits/stl_vector.h>

#include "Gruppe.h"
#include "ElementWrapper.h"

Gruppe::Gruppe() {
    
}

Gruppe::addElement(const Element& element) {
    EW add(element, order);
    this->elemente.push_back(add);
    order++;
}

