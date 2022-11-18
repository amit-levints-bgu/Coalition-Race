#include "../include/Coalition.h"

Coalition::Coalition(int mandates, int first_party) : mandates(mandates) 
{
    partiesIDs.push_back(first_party);
}
