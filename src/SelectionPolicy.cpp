#include "SelectionPolicy.h"
#include "Agent.h"
#include "Graph.h"
#include "Simulation.h"


int MandatesSelectionPolicy::select(vector<int> neighbors, Graph &g, Agent agent)
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
    return mandatePartyID;
}

int EdgeWeightSelectionPolicy::select(vector<int> neighbors, Graph &g, Agent agent)
{
    int edgePartyID;
    int maxEdge =0 ;
    for(int i=0; i < neighbors.size(); i++){
        int currentEdge = g.getEdgeWeight(agent.getPartyId(),i);
        if(maxEdge < currentEdge) 
        {
            maxEdge = currentEdge;
            edgePartyID = neighbors[i];
        }
    }
    return edgePartyID;
}