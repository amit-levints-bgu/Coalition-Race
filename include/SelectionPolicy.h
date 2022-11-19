#pragma once

class SelectionPolicy {
     public:
        virtual int select(vector<int> , Graph &, Agent) = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        virtual int select(vector<int> , Graph &, Agent);
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
     public:
        virtual int select(vector<int> , Graph &, Agent);
 };