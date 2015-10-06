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
    for (int i = 0; i < elemente.size();++i) {
        if (!elemente[i].calculate(&elemente)) {
            return false;
        }
    }
    return true;
}

bool Gruppe::checkAsso() {
    for (auto& a : elemente) {
        for (auto& b : elemente) {
            for (auto& c : elemente) {
                if (!((a+b)+c == a +(b+c))) {
                    return false;
                }
            }
        }
    }
    return true;
}