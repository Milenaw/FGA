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
#include "Set.h"
//#include "Generator.h"

using namespace std;

class Element;
class Generator;

class Gruppe {
	friend Generator;
public:
    Gruppe();

    Gruppe(vector<Element>& elements);

//    Gruppe(vector<EW> elements);

    bool checkAsso();

    bool checkNeutral();

    bool checkInvers();

    void addElement(const Element& element); //Fügt ein Element der Gruppe hinzu, prüft jedoch nicht die Gruppenaxiome

    bool create(); //Erstellt die Verknüpfungstabelle, prüft ob die Gruppe abgeschlossen ist

    void calculateCyclicSubgroups();

    string getE(); //Gibt das neutrale Element aus

    bool iscyclic();
    int getOrder();
    vector<EW*> getElemente();

protected:
    bool closure = false; //Abgeschlossen?
    bool asso = false;    //assoziativ?
    bool neutral = false; //Gibt es neutrales Element?
    bool cyclic=false; //Cyclic Group?
    bool inverse = false;//existieren Inverse?

    int order = -1; //Ordnung der Gruppe
    EW* e; //Das neutrale Element
    std::vector<EW> elemente;

    std::vector<Set> subgroups;



    void calcOrders();
};

#endif	/* GRUPPE_H */
