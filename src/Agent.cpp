#include "../include/Agent.h"
#include "../include/Simulation.h"
#include "../include/SelectionPolicy.h"
#include <algorithm>
#include <iostream> 


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent::Agent(): mAgentId(), mPartyId(), mSelectionPolicy(){}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::setID(int ID)
{
    mAgentId = ID;
}

void Agent::setPartyID(int ID)
{
    mPartyId = ID;
}

vector<int> Agent::findMyCoalition(Simulation &sim){
    vector<vector<int>> CoalitionIDs = sim.getPartiesByCoalitions();
    vector<int> AnsCoalition;
    for(vector<int> coalition: CoalitionIDs )
    {
        if (std::count(coalition.begin(), coalition.end(), mPartyId)){
            AnsCoalition=coalition;
            return AnsCoalition;
        }
    }
    return AnsCoalition;
}

void Agent::step(Simulation &sim)
{
    Graph& graph = sim.getG();

    //find all agent neighbors
    vector<int> neighbors;
    for(int i=0; i<graph.getNumVertices(); i++) {
        if (graph.getEdgeWeight(getPartyId(),i) != 0)
            neighbors.push_back(i);   
    }
   
    vector<int> myCoalition = findMyCoalition(sim);
    int partyOfferID = mSelectionPolicy->select(neighbors,graph,*this,myCoalition);
   
    //check if there is a relevanc party to sent an offer
    if(partyOfferID != -1){
        Party& partyOffer = graph.getPartyById(partyOfferID);
        partyOffer.offer(getPartyId());
    }
}

SelectionPolicy* Agent::getPolicy()
{
    return mSelectionPolicy;
}

//destractor
Agent::~Agent(){
    if(mSelectionPolicy) {delete mSelectionPolicy;}
}

//copy constractor
// Agent::Agent(const Agent &other): mAgentId(), mPartyId(), mSelectionPolicy(){
//     if(this != &other)
//     {
//         mSelectionPolicy = other.mSelectionPolicy->clone();
//         mAgentId = other.getId();
//         mPartyId = other.getPartyId();
//     }  
// }


//copy constractor
Agent::Agent(const Agent &other): mAgentId(other.getId()), mPartyId(other.getPartyId()), mSelectionPolicy(other.mSelectionPolicy->clone()){
}

//copy assignment operator
Agent& Agent::operator=(const Agent &other){
    if(this != &other)
    {
        if(mSelectionPolicy) delete mSelectionPolicy;
        *mSelectionPolicy = (*(other.mSelectionPolicy));
    }

    this->mAgentId = other.getId();
    this->mPartyId = other.getPartyId();
    return *this;
}

//move constractor
Agent::Agent(Agent &&other): mAgentId(), mPartyId(), mSelectionPolicy(){
    mSelectionPolicy = other.mSelectionPolicy;
    this->mAgentId = other.getId();
    this->mPartyId = other.getPartyId();
    other.mSelectionPolicy = nullptr;
}

//move assignment operator
Agent& Agent::operator=(Agent &&other){
    mSelectionPolicy = other.mSelectionPolicy;
    mAgentId = other.getId();
    mPartyId = other.getPartyId();
    return *this;
}