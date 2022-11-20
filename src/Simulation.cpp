#include "../include/Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    for (Agent agent: mAgents) {
        vector<int> vec;
        vec.push_back(agent.getPartyId());
        coalitions.push_back(vec);
    }
}

void Simulation::step()
{
    for (Party p: mGraph.getParties()){
        p.step(*this);
    }
    for (Agent a: mAgents){
        a.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

void Simulation::join_coalition(int join_partyId, int join_party_mandates, int coalition_partyId) 
{
    // TODO implement this method
    // create new agent and insert to Agent vector
    // insert the partyId to coallition
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return coalitions;
}
