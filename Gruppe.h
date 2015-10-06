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
    Gruppe(vector<const Element&> elemente);
    bool checkAsso();
    bool checkNeutral();
    bool checkInvers();
    void addElement(const Element& element); //Fügt ein Element der Gruppe hinzu
    void create(); //Erstellt die Verknüpfungstabelle, prüft ob die Gruppe abgeschlossen ist
    bool getE(); //Gits das neutrale Element?

private:
    bool closure=false; //Abgeschlossen?
    bool asso = false;//assoziativ?
    bool neutral = false;//Gibt es neutrales Element?
    bool inverse = false;//existieren Inverse?

    int order = 0; //Ordnung der Gruppe
    EW* e; //Das neutrale Element
    std::vector<EW> elemente;
    
};

#endif	/* GRUPPE_H */
