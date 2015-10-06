/*
 * File:   main.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 8:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Gruppe.h"
#include "Element.h"

using namespace std;

int main(int argc, char** argv) {
    Gruppe gruppe;
    Element::fill(gruppe);
    cout << gruppe.create() << endl;
    cout << gruppe.checkAsso() << endl;
    cout << gruppe.checkNeutral() << endl;
    cout << gruppe.getE() << endl;
    
}
