#include "Party.h"
#include "../include/JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    timer = 0;
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
    if(mState == Waiting){
        mState = CollectingOffers;
    } else if (timer < 3 && mState == CollectingOffers){
        timer++;
    } else if (timer = 3 && mState == CollectingOffers){
        mJoinPolicy->join_coalition(party_offers, s, mId);
        mState = Joined;
    }
}

void Party::offer(int party_id)
{
    party_offers.push_back(party_id);
}