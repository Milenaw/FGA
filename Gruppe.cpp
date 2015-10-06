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
    for (int az = 0 ; az < elemente.size() ;++az) {
        for (int bz = 1 ; bz < elemente.size() ;++bz) {
            for (int cz = 2 ; cz < elemente.size() ;++cz) {
                EW& a = elemente[az];
                EW& b = elemente[bz];
                EW& c = elemente[cz];
                if (!((a+b)+c == a +(b+c))) {
                    return false;
                }
            }
        }
    }
    return true;
}