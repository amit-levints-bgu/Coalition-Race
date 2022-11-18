#pragma once
#include <vector>
#include "Party.h"

using std::vector;

class Coalition
{
public:
    Coalition(int mandates, int first_party);


private:
    vector<int> partiesIDs;
    int mandates;
};