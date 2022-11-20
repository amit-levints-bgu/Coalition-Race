#include "Agent.h"
#include "Graph.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

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

void Agent::step(Simulation &sim)
{
    Graph graph = sim.getGraph();
    vector<int> neighbors;
    for(int i=0; i<graph.getNumVertices(); i++) {
        if (graph.getEdgeWeight(this->getPartyId(),i) != 0)
            neighbors.push_back(i);   
    }
    int partyOfferID = mSelectionPolicy->select(neighbors,graph,*this);
    Party partyOffer = graph.getParty(partyOfferID);
    partyOffer.offer(this->getPartyId(),sim);
}
