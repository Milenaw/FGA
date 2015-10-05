/*
 * File:   Gruppe.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:11 PM
 */

#include "Gruppe.h"
#include "ElementWrapper.h"

Gruppe::Gruppe() {
    
}

void Gruppe::addElement(const Element& element) {
    EW add(element, order);
    this->elemente.push_back(add);
    order++;
}

bool Gruppe::create() {
    for (EW i : elemente) {
        if (!i.calculate(&elemente)) {
            return false;
        }
    }
    return true;
}

