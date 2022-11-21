#pragma once

class SelectionPolicy {
     public:
        virtual int select(std::vector<int> , Graph &, Agent, vector<int>) = 0;
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