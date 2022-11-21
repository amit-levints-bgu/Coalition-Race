#pragma once
#include <vector>
#include "../include/Simulation.h"

class JoinPolicy {
    public:
        virtual void join_coalition(std::vector<int> offers , Simulation &s, int my_id)=0;
        virtual JoinPolicy* clone()=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        void join_coalition(std::vector<int> offers , Simulation &s, int my_id);
        MandatesJoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
        public:
        void join_coalition(std::vector<int> offers , Simulation &s, int my_id);
        LastOfferJoinPolicy* clone();
};