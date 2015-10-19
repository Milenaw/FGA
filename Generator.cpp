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
		vector<const Generator*> result;
		for(auto a:this->Elemente) {
			if(a->generatedCyclicSubgroup.size()==(unsigned)G.order) {
				g=a;
				break;
			}
		}
		for(int i=0; i<G.order;i++) {
			if(i%G.order) {
				vector<const EW*> res;
				res.push_back(g->generatedCyclicSubgroup[i]);
				const Generator resgen(res);
				result.push_back(&resgen);
			}
		}
		return result;
	}
	//Continuing with step 2

	//TODO: Implement it, using code from QuotientGroup
	//Finish the main constructor there doing the real work.
	vector<QuotientGroup*> Q;
	vector<const EW*> gen;
	Gruppe* inp=&const_cast<Gruppe&>(G);
	QuotientGroup cur=*new QuotientGroup(*inp);

	Q.push_back(&cur);
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
	const Generator generator(gen);
	vector<const Generator*> result;
	result.push_back(&generator);
	return result;
}
