/*
 * File:   Gruppe.h
 * Author: colinRothgang
 *
 * Created on October 17, 2015
 */

#ifndef QUOTIENTGROUP_H
#define    QUOTIENTGROUP_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ElementWrapper.h"
#include "Gruppe.h"

using namespace std;

class Gruppe;

class QuotientGroup : Gruppe {
public:
	QuotientGroup(Gruppe& G);
	QuotientGroup(QuotientGroup& G);
	QuotientGroup(const Gruppe& G, const EW& g);
};
#endif	/*GENERATORS_H*/
