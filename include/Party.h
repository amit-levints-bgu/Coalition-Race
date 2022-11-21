#pragma once
#include <string>
#include <vector>

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    virtual ~Party();
    Party(const Party &other);
    Party& operator=(const Party &other); 
    Party(Party &&other);
    Party& operator=(Party &&other);

    State getState() const;
    void setState(State state);
    int getMandates() const;
    std::vector<int> getMyOffer();
    void step(Simulation &s);
    const string &getName() const;
    void offer(int partyid);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    std::vector<int> party_offers;
};
