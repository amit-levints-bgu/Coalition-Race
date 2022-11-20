#pragma once
#include <vector>

class JoinPolicy {
    public:
        virtual void join_coalition(std::vector<int> offers , Simulation &s, int my_id)=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        void join_coalition(std::vector<int> offers , Simulation &s, int my_id);
};

class LastOfferJoinPolicy : public JoinPolicy {
        public:
        void join_coalition(std::vector<int> offers , Simulation &s, int my_id);
};