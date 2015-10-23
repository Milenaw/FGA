#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ElementWrapper.h"
#include "Gruppe.h"
#include "Generator.h"
#include "Set.h"
#include "Set.cpp"

using namespace std;

Generator::Generator(Set<const EW> elements) {
	this->Elemente=*new Set<const EW>(elements);
}

bool Generator::operator==(const Generator& Gen) const {
	if(this->Elemente.order()!=Gen.Elemente.order()) {
		return false;
	}
	for(int i=0; i<this->Elemente.order(); i++) {
		if(*(this->Elemente.get()[i])!=*(Gen.Elemente.get()[i])) {
			return false;
		}
	}
	return true;
}

Set<const Generator> Generator::findGenerators(const Gruppe& G) {
	/*used (greedy) Algorithm:
	1. Step:
		Check whether the group G with order n is cyclic
		If so find a generating element g
		Compute the set X of numbers, who don't divide the order of G
		Then return the set of generating elements, namely g^x, for all x in X
	3. Step:
		Q_0=G
		int count=1
		Subsets 3.1:
			Choose an element a_count of Q_count, with highest order o_count and with o_count | card(Q_count)
			Calculate Q_count:=QuotientGroup(Q_{count-1}, a_count)
			count++
		Repeat Subset 3.1 until Q_count={}, in the following this count is called s
	//Repeat Step 3 using anouther starting element a_0 and at no moment j choosing an a_i,j s.t.
	//{a_1j, a_2j, ..., a_sj}={{a_1k, a_2k, ..., a_sk} for k\neq j
	//return the set of generators {{a_11, a_21, ..., a_s1}, {a_12, a_22, ..., a_s2}, ...}
	return {{a_1, a_2, ..., a_s}}
	*/

	//Starting with step 1:
	if(G.cyclic) {
		const EW* g;
		Set<const Generator> result;
		for(auto a: this->Elemente.get()) {
			if((*a).generatedCyclicSubgroup.size()==(unsigned)G.order) {
				g=a;
				break;
			}
		}
		for(int i=0; i<G.order;i++) {
			if(i%G.order) {
				vector<const EW*> res;
				res.push_back(g->generatedCyclicSubgroup[i]);
				Set<const EW> next(res);
				const Generator gennext(next);
				result.addElement(gennext);
			}
		}
		return result;
	}
	//Continuing with step 2

	vector<QuotientGroup*> Q;
	vector<const EW*> gen;
	Gruppe* inp=&const_cast<Gruppe&>(G);

	Q.push_back(new QuotientGroup(*inp));
	int count=0;
	while(reinterpret_cast<Gruppe*>(Q[count])->getOrder()>1) {
		Gruppe* current=reinterpret_cast<Gruppe*>(Q[count]);
		int pos=0;
		int ord=0;
		for(int i=0; i<current->getOrder(); i++) {
			int curord=current->getElemente()[i]->generatedCyclicSubgroup.size();
			if(curord>ord && !(current->getOrder()%curord)) {
				pos=i;
				ord=curord;
			}
		}
		const EW* g=current->getElemente()[pos];
		gen.push_back(g);
		Q.push_back(new QuotientGroup(*current, *g));
		count++;
	}
	for(auto a: Q) {
		delete a;
	}
	const Generator generator(gen);
	vector<const Generator*> result;
	result.push_back(&generator);
	return result;
}
