#include "../include/Simulation.h"
#include <iostream> 

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), Coalitions(), AgentCounter()
{
    int max_agentId = 0;
    for (Agent agent: mAgents) {
        vector<int> vec;
        vec.push_back(agent.getPartyId());
        
        int AgentMan = mGraph.getParty(agent.getPartyId()).getMandates();
        vector<int> CoalitionParty;
        CoalitionParty.push_back(agent.getPartyId());

        std:: tuple<int,vector<int>> newCoalition;
        newCoalition = make_tuple(AgentMan,CoalitionParty);
        Coalitions.push_back(newCoalition);

        if(max_agentId < agent.getId()){
            max_agentId = agent.getId();
        }
    }
    AgentCounter = max_agentId;
}

void Simulation::step()
{
    for (Party &p: mGraph.getParties()){
        p.step(*this);
    }
    for (Agent a: mAgents){
        a.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    int countJoinedParty =0;
    for(std::tuple<int, vector<int>> T: Coalitions){
        if(std::get<0>(T)>60)
            return true;
        countJoinedParty += std::get<1>(T).size();
    }
    if(countJoinedParty == getGraph().getNumVertices())
        return true;
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getG()
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
    // create new agent and insert to Agent vector
    // insert the partyId to coallition
    AgentCounter++;
    for(Agent agent : mAgents){
        if(agent.getPartyId() == coalition_partyId){
            mAgents.push_back(Agent(AgentCounter, coalition_partyId, agent.getPolicy())); 
        }
    }
    for(std::tuple<int, vector<int>> T: Coalitions){
        for(int i: std::get<1>(T)){
            if(i == coalition_partyId){
                std::get<1>(T).push_back(join_partyId);
                std::get<0>(T) = std::get<0>(T) + join_party_mandates;
            }
        }
    }
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
