//
// Created by benjamin on 15.10.15.
//

#include "Subset.h"

Subset::Subset(int order, std::vector<EW>* all) : order(order), all(all), bitset(order) {
}

Subset::~Subset() {

}

Subset::Subset(const Subset& origin) {
    this->bitset = origin.bitset;
    this->all = origin.all;
}

Subset Subset::merge(const Subset& other) const {
    Subset set(order, all);
    set.bitset = this->bitset | other.bitset;
    return set;
}

Subset Subset::intersection(const Subset& other) const {
    Subset set(order, all);
    set.bitset = this->bitset & other.bitset;
    return set;
}

std::vector<EW*> Subset::get() const {
    std::vector<EW*> result;
    for (int i = 0 ; i < order ; ++i) {
        if (bitset[i] == 1) {
            result.push_back(&(all->at(i)));
        }
    }
}

void Subset::add(EW* element) {
    bitset[element->getId()] = 1;
}
