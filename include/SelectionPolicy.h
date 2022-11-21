#pragma once

class SelectionPolicy {
     public:
        virtual int select(vector<int> , Graph &, Agent, vector<int>) = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        virtual int select(vector<int> , Graph &, Agent, vector<int>);
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
     public:
        virtual int select(vector<int> , Graph &, Agent, vector<int>);
 };