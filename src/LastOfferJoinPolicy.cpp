#include "../include/JoinPolicy.h"
#include "../include/Party.h"

void LastOfferJoinPolicy::join_coalition(std::vector<int> offers , Simulation &s, int my_id){
    int party_id = offers.back();
    int mandates = s.getParty(party_id).getMandates();
    s.join_coalition(my_id, mandates, party_id);
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone(){
    return new LastOfferJoinPolicy(*this);
}
