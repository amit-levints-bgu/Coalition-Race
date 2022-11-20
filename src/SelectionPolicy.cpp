#include "SelectionPolicy.h"
#include "Agent.h"
#include "Graph.h"
#include "Simulation.h"

//TODO: add rule of 5
int MandatesSelectionPolicy::select(vector<int> neighbors, Graph &g, Agent agent)
{
    //TODO: verify if the party get offer from my colition
    int mandatePartyID = -1;
    int maxMandate =0 ;
    for(int i=0; i < neighbors.size(); i++){
        Party currentParty = g.getParty(neighbors[i]);
        int currentMandates = currentParty.getMandates();
        if(maxMandate < currentMandates && currentParty.getState() != Joined) 
        {
            maxMandate = currentMandates;
            mandatePartyID = neighbors[i];
        }
    }
    return mandatePartyID;
}

int EdgeWeightSelectionPolicy::select(vector<int> neighbors, Graph &g, Agent agent)
{
    int edgePartyID = -1;
    int maxEdge =0 ;
    for(int i=0; i < neighbors.size(); i++){
        Party currentParty = g.getParty(neighbors[i]);
        int currentEdge = g.getEdgeWeight(agent.getPartyId(),i);
        if(maxEdge < currentEdge && currentParty.getState() !=  Joined) 
        {
            maxEdge = currentEdge;
            edgePartyID = neighbors[i];
        }
    }
    return edgePartyID;
}