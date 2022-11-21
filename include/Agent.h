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
    virtual ~Agent();
    Agent(const Agent &other);
    Agent& operator=(const Agent &other);
    Agent(Agent &&other);
    Agent& operator=(Agent &&other);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    vector<int> findMyCoalition(Simulation &);
};
