#include "../include/Party.h"
#include "../include/JoinPolicy.h"
using std::vector;

// constructor
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(0), party_offers()
{
}

// destructor
 Party::~Party(){
    if(mJoinPolicy){
        delete mJoinPolicy;
    }
 }

// copy constructor
 Party::Party(const Party &other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), timer(other.timer), party_offers(){
    if(this != &other){
        for(int offer: other.party_offers){
            party_offers.push_back(offer);
        }
    }
 }

// copy assigmnet operator
Party& Party::operator=(const Party &other){
    if(this != &other){
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        *mJoinPolicy = (*(other.mJoinPolicy));
        timer = other.timer;
        for(int offer: other.party_offers){
            party_offers.push_back(offer);
        }
    }
    return *this;
}

// move constructor
 Party::Party(Party &&other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), timer(other.timer), party_offers(){
    if(this != &other){     
        other.mJoinPolicy = nullptr;
    }
}

// move assigment operator
Party& Party::operator=(Party &&other){
    if(mJoinPolicy) delete mJoinPolicy;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
    return *this;
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

vector<int> Party::getMyOffer()
{
    return party_offers;
}

void Party::step(Simulation &s)
{
    if(mState == Waiting){
        mState = CollectingOffers;
    } else if (timer < 3 && mState == CollectingOffers){
        timer++;
    } else if (timer == 3 && mState == CollectingOffers){
        mJoinPolicy->join_coalition(party_offers, s, mId);
        mState = Joined;
    }
}

void Party::offer(int party_id)
{
    party_offers.push_back(party_id);
    mState = CollectingOffers;
}