#pragma once

#include <vector>
#include "../include/Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~Agent();

    int getPartyId() const;
    int getId() const; 
    void step(Simulation &);
    void setPartyID(int);
    void setID(int);
    SelectionPolicy* getPolicy();
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
