#include "../include/SelectionPolicy.h"
#include "../include/Agent.h"
#include "../include/Graph.h"
#include "../include/Simulation.h"
#include <algorithm>

//TODO: add rule of 5
int MandatesSelectionPolicy::select(vector<int> neighbors, Graph &g, Agent agent, vector<int> agentCoalition)
{
    //TODO: verify if the party get offer from my colition
    int mandatePartyID = -1;
    int maxMandate =0 ;
    for(int i=0; (unsigned)i < neighbors.size(); i++){
        Party currentParty = g.getParty(neighbors[i]);
        int currentMandates = currentParty.getMandates();
        vector<int> partyOffers = currentParty.getMyOffer();
        bool getOfferFromMyCoalition = false;
        
        //check if the neighbor party have offer from my coalition
        for(int offerId:partyOffers){
            if (std::count(agentCoalition.begin(), agentCoalition.end(), offerId))
            {
                getOfferFromMyCoalition = true;
                break;
            }
        }

        //check if the party mandats are the highest 
        if(maxMandate < currentMandates && currentParty.getState() != Joined && getOfferFromMyCoalition == false) 
        {
                maxMandate = currentMandates;
                mandatePartyID = neighbors[i];
        }

    }
    return mandatePartyID;
}


MandatesSelectionPolicy* MandatesSelectionPolicy::clone()
{
    return new MandatesSelectionPolicy(*this);
}


int EdgeWeightSelectionPolicy::select(vector<int> neighbors, Graph &g, Agent agent, vector<int> agentCoalition)
{
    int edgePartyID = -1;
    int maxEdge =0 ;
    for(int i=0; (unsigned)i < neighbors.size(); i++){
        Party currentParty = g.getParty(neighbors[i]);
        int currentEdge = g.getEdgeWeight(agent.getPartyId(),i);
        vector<int> partyOffers = currentParty.getMyOffer();
        bool getOfferFromMyCoalition = false;
        
        //check if the neighbor party have offer from my coalition
        for(int offerId:partyOffers){
            if (std::count(agentCoalition.begin(), agentCoalition.end(), offerId))
            {
                getOfferFromMyCoalition = true;
                break;
            }
        }
        
        //check if the party edge are the highest
        if(maxEdge < currentEdge && currentParty.getState() !=  Joined && getOfferFromMyCoalition == false) 
        {
            maxEdge = currentEdge;
            edgePartyID = neighbors[i];
        }
    }
    return edgePartyID;
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return new EdgeWeightSelectionPolicy(*this);
}