#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ElementWrapper.h"
#include "Gruppe.h"
#include "QuotientGroup.h"

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

QuotientGroup::QuotientGroup(const Gruppe& G, const EW& g) {
	vector<EW*> res;
	//TODO:
	//Implement the real functionality

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
