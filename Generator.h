/*
 * File:   Gruppe.h
 * Author: colinRothgang
 *
 * Created on October 17, 2015
 */

#ifndef GENERATORS_H
#define    GENERATORS_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ElementWrapper.h"
#include "Gruppe.h"

using namespace std;

class Generator {
public:
	Generator(vector<const EW&> elemente);
	vector<const Generator*> findGenerators(const Gruppe& group);
private:
	vector<const EW*> Elemente;
};

#endif	/*GENERATORS_H*/
