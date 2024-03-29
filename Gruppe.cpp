/*
 * File:   Gruppe.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:11 PM
 */

#include "Gruppe.h"
#include "ElementWrapper.h"

Gruppe::Gruppe() {
    order = 0;
}

Gruppe::Gruppe(std::vector<Element>& elemente) {
    asso = false;
    closure = false;
    order = 0;
    for (auto& a: elemente) {
        this->addElement(a);
    }
    if (!this->create()) {
        std::cerr << "Nicht abgeschlossen" << std::endl;
        std::clog << "Terminating group creation, since the \'group\' is not closed." << endl;
    }
    else if (!this->checkNeutral()) {
        std::cerr << "Kein neutrales Element" << std::endl;
        std::clog << "Terminating group creation, since the \'group\' is has no neutral element." << endl;
    }
    else if (!this->checkAsso()) {
        std::cerr << "Nicht assoziativ" << std::endl;
        std::clog << "Terminating group creation, since the \'group\' is not associative." << endl;
    }
    else if (!this->checkInvers()) {
        std::cerr << "Es existieren nicht für alle Elemente inverse" << std::endl;
        std::cerr << "Terminating group creation, since not all elements of the \'group\' have inverse elements." <<
        endl;
    }
    else {
    	this->calculateCyclicSubgroups();
        std::cout << "Group creation successful." << endl;
        this->calcOrders();
        std::cout << "Orders claculation successful" << endl;
        return;
    }
    throw 0;
}

void Gruppe::addElement(const Element& element) {
    for (auto& a: elemente) {
        if (a == element) {
            std::clog << "Mehrfaches Element ignoriert" << std::endl;
            return;
        }
    }
    EW add(element, order);
    this->elemente.push_back(add);
    order++;
}

bool Gruppe::create() {
    for (unsigned int i = 0; i < elemente.size(); ++i) {
        if (!elemente[i].calculate(&elemente)) {
            closure = false;
            return false;
        }
    }
    closure = true;
    return true;
}

void Gruppe::calculateCyclicSubgroups() {
	for (unsigned int i = 0; i < elemente.size(); ++i) {
		int j=0;
		EW current=elemente[i];
		EW start=current;
		elemente[i].generatedCyclicSubgroup[0]=&start;
		while(current!=*this->e) {
			j++;
			current=start+current;
			elemente[i].generatedCyclicSubgroup[j]=&current;
			if(j==this->order) {
				this->cyclic=true;
			}
		}
	}
}

bool Gruppe::checkAsso() {
    for (auto& a : elemente) {
        for (auto& b : elemente) {
            for (auto& c : elemente) {
                if (!((a + b) + c == a + (b + c))) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Gruppe::checkNeutral() {
    for (auto& e : elemente) { //Über alle Elemente iterieren, die neutral sein könnten
        bool t = true;
        for (auto& a : elemente) { //Prüfen ob e neutral ist
            if (!(e + a == a && a + e == a)) { //e ist nicht neutral
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

string Gruppe::getE() {
    if (!neutral) {
        if (!this->checkNeutral()) {
            throw 1;
        }
    }
    string r = e->toString();
    return r;
}

bool Gruppe::checkInvers() {
    for (auto& a : elemente) {//suche nach dem Inversen von a
        bool test = false;
        for (auto& b : elemente) {
            if (a + b == *(this->e)) {
                a.setInverse(b);
                test = true;
            }
        }
        if (!test) {
            return false;
        }
    }
    return true;
}

void Gruppe::calcOrders() {
    for(auto& i : elemente) {
        i.calcOrder(*e);
    }
}

bool Gruppe::iscyclic() {
	return this->cyclic;
}

int Gruppe::getOrder() {
	return this->order;
}

vector<EW*> Gruppe::getElemente() {
	vector<EW*> res;
	for(auto& a:elemente) {
		res.push_back(&a);
	}
	return res;
}
