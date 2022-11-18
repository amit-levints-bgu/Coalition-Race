#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if (timer < 3 && mState == '1'){
        timer++;
    } else if (timer = 3 && mState == '1'){
        for(int party_id: party_offers) {
            
        }
    } else if (mState == '2'){
        
    }
}

void Party::offer(int party_id)
{
    party_offers.push_back(party_id);
}