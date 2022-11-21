#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent();
    int getPartyId() const;
    int getId() const; 
    void step(Simulation &);
    SelectionPolicy* Agent::getPolicy();

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    vector<int> findMyCoalition(Simulation &);
};
