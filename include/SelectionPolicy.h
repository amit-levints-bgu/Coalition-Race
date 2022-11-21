#pragma once
#include <vector>
#include "../include/Graph.h"
#include "../include/Agent.h"

class SelectionPolicy {
     public:
<<<<<<< HEAD
        virtual int select(std::vector<int> , Graph &, Agent, std::vector<int>) = 0;
=======
        virtual int select(std::vector<int> , Graph &, Agent, vector<int>) = 0;
>>>>>>> master
        virtual SelectionPolicy* clone() =0 ;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        int select(std::vector<int> , Graph &, Agent, vector<int>);
        MandatesSelectionPolicy* clone();
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
     public:
        int select(std::vector<int> , Graph &, Agent, vector<int>);
        EdgeWeightSelectionPolicy* clone();
 };