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
#include "QuotientGroup.h"
#include "Set.h"

using namespace std;

class Generator {
public:
	Generator(Set<const EW> elements);
	Set<const Generator> findGenerators(const Gruppe& group);
	bool operator==(const Generator& Gen) const;
private:
	Set<const ElementWrapper> Elemente;
};

#endif	/*GENERATORS_H*/
