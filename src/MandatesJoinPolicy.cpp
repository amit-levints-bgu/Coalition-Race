#include "../include/JoinPolicy.h"
#include "../include/Party.h"
#include "../include/Simulation.h"

void MandatesJoinPolicy::join_coalition(std::vector<int> offers , Simulation &s, int my_id){
    int most_mandates = 0;
    int most_mandates_party_id; 
    for (int party_id: offers){
        Party party = s.getParty(party_id);
        int mandates = party.getMandates();
        if (most_mandates < mandates){
            most_mandates = mandates;
            most_mandates_party_id = party_id;
        }
    }
    s.join_coalition(most_mandates_party_id, most_mandates, my_id);
}