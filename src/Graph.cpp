#include "../include/Graph.h"
#include <iostream> 

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party& Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party& Graph::getPartyById(int partyId) 
{
    return mVertices[partyId];
}

vector<Party>& Graph::getParties(){
    return mVertices;
}

// Graph& Graph::operator=(Graph other){
//     for(Party other_party:other.mVertices){
//         mVertices.push_back(other_party);
//     }
//     mEdges = other.mEdges;
//     return *this;
// }