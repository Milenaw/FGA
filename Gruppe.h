/*
 * File:   Gruppe.h
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:11 PM
 */

#ifndef GRUPPE_H
#define	GRUPPE_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ElementWrapper.h"

using namespace std;

class Element;

class Gruppe {
public:
    Gruppe();
    bool checkClosure();
    bool checkAsso();
    bool checkNeutral();
    bool checkInvers();
    void addElement(const Element& element); //Fügt ein Element der Gruppe hinzu
    string getE(); //Gitb das neutrale Element aus

private:
    bool closure; //Abgeschlossen?
    bool asso = false;//assoziativ?
    bool neutral = false;//Gibt es neutrales Element?
    bool inverse = false;//existieren Inverse?

    int order = 0; //Ordnung der Gruppe
    EW* e; //Das neutrale Element
    std::vector<EW> elemente;
    
};

#endif	/* GRUPPE_H */
