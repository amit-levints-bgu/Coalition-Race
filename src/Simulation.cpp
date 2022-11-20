#include "../include/Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    for (Agent agent: mAgents) {
        vector<int> vec;
        vec.push_back(agent.getId());
        
        int AgentMan = mGraph.getParty(agent.getPartyId()).getMandates();
        vector<int> CoalitionParty;
        CoalitionParty.push_back(agent.getPartyId());

        std:: tuple<int,vector<int>> newCoalition;
        newCoalition = make_tuple(AgentMan,CoalitionParty);
        Coalitions.push_back(newCoalition);
       
        // coalitions.push_back(vec);
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

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> CoalitionsID;
    for(std::tuple<int, vector<int>> T: Coalitions){
        CoalitionsID.push_back(std::get<1>(T));
    }
    return CoalitionsID;

}
