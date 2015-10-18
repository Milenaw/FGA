#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ElementWrapper.h"
#include "Gruppe.h"
#include "Generator.h"

using namespace std;

Generator::Generator(vector<const EW*> elemente) {
	for(unsigned int i=0; i<elemente.size();i++) {
		this->Elemente.push_back(elemente[i]);
	}
}

vector<const Generator*> Generator::findGenerators(const Gruppe& G) {
	/*used (greedy) Algorithm:
	1. Step:
		Check whether the group G with order n is cyclic
		If so find a generating element g
		compute the set X of numbers, who don't divide the order of G
		Then return the set of generating elements, namely g^x, for all x in X
	2. Step:
		Compute the orders of the elements of G
	3. Step:
		H_0=G
		int count=1
		Subsets 3.1:
			Choose an element a_count of G, with highest order o_count and with o_1*o_2*...*o_count | m
			Calculate H_count:=G\<a_1, a_2, ..., a_count>
			count++
		Repeat Subset 3.1 until H_count={}, in the following this count is called s
	Repeat Step 3 using anouther starting element a_0 and at no moment j choosing an a_i,j s.t.
	{a_1j, a_2j, ..., a_sj}={{a_1k, a_2k, ..., a_sk} for k\neq j
	return the set of generators {{a_11, a_21, ..., a_s1}, {a_12, a_22, ..., a_s2}, ...}
	*/
}
