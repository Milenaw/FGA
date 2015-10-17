#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ElementWrapper.h"
#include "Gruppe.h"
#include "Generator.h"

using namespace std;

Generator::Generator(vector<const EW&> elemente) {
	for(unsigned int i=0; i<elemente.size();i++) {
		this->Elemente.push_back(&elemente[i]);
	}
}
