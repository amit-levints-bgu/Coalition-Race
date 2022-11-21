#include "Agent.h"
#include "Graph.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
#include <algorithm>


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

vector<int> Agent::findMyCoalition(Simulation &sim){
    vector<vector<int>> CoalitionIDs = sim.getPartiesByCoalitions();
    for(vector<int> coalition: CoalitionIDs )
    {
        if (std::count(coalition.begin(), coalition.end(), mPartyId))
            return coalition;
    }
}

void Agent::step(Simulation &sim)
{
    Graph graph = sim.getGraph();
    
    //find all agent neighbors
    vector<int> neighbors;
    for(int i=0; i<graph.getNumVertices(); i++) {
        if (graph.getEdgeWeight(this->getPartyId(),i) != 0)
            neighbors.push_back(i);   
    }
   
    vector<int> myCoalition = findMyCoalition(sim);
    int partyOfferID = mSelectionPolicy->select(neighbors,graph,*this,myCoalition);
   
    //check if there is a relevanc party to sent an offer
    if(partyOfferID != -1){
        Party partyOffer = graph.getParty(partyOfferID);
        partyOffer.offer(this->getPartyId());
    }

}
