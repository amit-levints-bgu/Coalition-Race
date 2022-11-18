#pragma once

class JoinPolicy {
    public:
        static void join_policiy();
};

class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};