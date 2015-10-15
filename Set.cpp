//
// Created by benjamin on 15.10.15.
//

#include "Set.h"



template <int ORDER> Set<ORDER>::Set(std::vector<EW>* all) {
    this->bitset.reset();
    this->all = all;
}

template <int ORDER> Set<ORDER>::Set(const Set& origin) {
    this->bitset = origin.bitset;
    this->all = origin.all;
}

template <int ORDER> Set<ORDER> Set<ORDER>::merge(const Set& other) const {
    Set<ORDER> set;
    set.bitset = this->bitset |= other.bitset;
    set.all = this->all;
    return set;
}

template <int ORDER> Set<ORDER> Set<ORDER>::intersection(const Set& other) const {
    Set<ORDER> set;
    set.bitset = this->bitset &= other.bitset;
    set.all = this->all;
    return set;
}