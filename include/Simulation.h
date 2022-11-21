#pragma once

#include <vector>
#include <tuple>

#include "Graph.h"
#include "Agent.h"
#include "../include/Coalition.h"


using std::string;
using std::vector;



class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
       
    void Simulation::join_coalition(int partyId, int mandates, int coalition_partyId);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    //vector<vector<int>> coalitions;
    vector<std:: tuple< int,vector<int>>> Coalitions;


};
