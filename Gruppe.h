/*
 * File:   Gruppe.h
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:11 PM
 */

#ifndef GRUPPE_H
#define    GRUPPE_H

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

    Gruppe(vector<Element>& elemente);

    bool checkAsso();

    bool checkNeutral();

    bool checkInvers();

    void addElement(const Element& element); //Fügt ein Element der Gruppe hinzu, prüft jedoch nicht die Gruppenaxiome

    bool create(); //Erstellt die Verknüpfungstabelle, prüft ob die Gruppe abgeschlossen ist

    string getE(); //Gits das neutrale Element?

private:
    bool closure = false; //Abgeschlossen?
    bool asso = false;
    //assoziativ?
    bool neutral = false;
    //Gibt es neutrales Element?
    bool inverse = false;//existieren Inverse?

    int order = -1; //Ordnung der Gruppe
    EW* e; //Das neutrale Element
    std::vector<EW> elemente;

    void calcOrders();

};

#endif	/* GRUPPE_H */
