#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ElementWrapper.h"
#include "Gruppe.h"
#include "QuotientGroup.h"
#include "Set.h"

using namespace std;
QuotientGroup::QuotientGroup(Gruppe& G) {
	QuotientGroup* copy=reinterpret_cast<QuotientGroup*>(&G);
	this->closure 	= copy->closure;
	this->asso 		= copy->asso;
	this->neutral 	= copy->neutral;
	this->inverse 	= copy->inverse;
	this->order   	= copy->order;
	this->e			=copy->e;
	this->elemente	=copy->elemente;
	this->subgroups	=copy->subgroups;
	this->cyclic	=copy->cyclic;
}

QuotientGroup::QuotientGroup(QuotientGroup& Q) : QuotientGroup(reinterpret_cast<Gruppe&>(Q)) {

}

QuotientGroup::QuotientGroup(Gruppe& G, const EW& g) {
	vector<EW*> res;
	//TODO:
	//Implement the real functionality
	vector<vector<EW*>> classes;
	vector<EW*> still;
	for(int i=0; i<G.getOrder();i++) {
		still.push_back(G.getElemente()[i]);
	}
	while(still.size()) {
		vector<EW*> newClass;
		newClass.push_back(still[0]);
		still.erase(still.begin());
		classes.push_back(newClass);
		int numclasses=classes.size();
		for(auto a:newClass[0]->generatedCyclicSubgroup) {
			int id=const_cast<EW*>(a)->getId();
			for(unsigned int i=0; i<still.size(); i++) {
				if(still[i]->getId()==id) {
					classes[numclasses-1].push_back(still[i]);
					still.erase(still.begin()+i);
				}
				else {
					i++;
				}
			}
		}
	}

	vector<Element> result;
	for(auto a:res) {
		result.push_back(a->getElement());
	}
	Gruppe gruppenres=*new Gruppe(result);
	QuotientGroup* copy=new QuotientGroup(gruppenres);
	this->closure 	= copy->closure;
	this->asso 		= copy->asso;
	this->neutral 	= copy->neutral;
	this->inverse 	= copy->inverse;
	this->order   	= copy->order;
	this->e			=copy->e;
	this->elemente	=copy->elemente;
	this->subgroups	=copy->subgroups;
	this->cyclic	=copy->cyclic;
}
