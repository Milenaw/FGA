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
    closure = true;
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
    asso = true;
    return true;
}

bool Gruppe::checkNeutral() {
    for (auto& e : elemente) { //Über alle Elemente iterieren, die neutral sein könnten
        bool t = true;
        for (auto& a : elemente) { //Prüfen ob e neutral ist
            if (!(e+a == a && a + e == a)) { //e ist nicht neutral
                t = false;
                break;
            }
        }
        if (t) {
            neutral = true;
            this->e = &e;
            return true;
        }
    }
    return false;
}

const string Gruppe::getE() const {
    string r = e ->toString();
    return r;
}