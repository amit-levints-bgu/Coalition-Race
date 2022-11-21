#pragma once
#include <vector>

class JoinPolicy {
    public:
        virtual void join_coalition(std::vector<int> offers , Simulation &s, int my_id)=0;
        virtual LastOfferJoinPolicy* clone()=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        void join_coalition(std::vector<int> offers , Simulation &s, int my_id);
        LastOfferJoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
        public:
        void join_coalition(std::vector<int> offers , Simulation &s, int my_id);
        LastOfferJoinPolicy* clone();
};