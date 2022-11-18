#include "Agent.h"
#include "Graph.h"
#include "Simulation.h"
// #include "Party.h"

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

Party Agent::findMandateParty(vector<int> neighbors, Graph &g)
{
    int mandatePartyID;
    int maxMandate =0 ;
    for(int i=0; i < neighbors.size(); i++){
        int currentMandates = g.getParty(neighbors[i]).getMandates();
        if(maxMandate < currentMandates) 
        {
            maxMandate = currentMandates;
            mandatePartyID = neighbors[i];
        }
    }
    return g.getParty(mandatePartyID);
}

Party Agent::findEdgeWeightParty(vector<int> neighbors, Graph &g)
{
    int edgePartyID;
    int maxEdge =0 ;
    for(int i=0; i < neighbors.size(); i++){
        int currentEdge = g.getEdgeWeight(mPartyId,i);
        if(maxEdge < currentEdge) 
        {
            maxEdge = currentEdge;
            edgePartyID = neighbors[i];
        }
    }
    return g.getParty(edgePartyID);
}

void Agent::step(Simulation &sim)
{
    Graph agenstG = sim.getGraph();
    vector<int> neighbors;
    for(int i=0; i<agenstG.getNumVertices(); i++) {
        if (agenstG.getEdgeWeight(this->getPartyId(),i) != 0)
            neighbors.push_back(i);   
    }


}
