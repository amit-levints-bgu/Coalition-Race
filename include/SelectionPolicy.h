#pragma once

class SelectionPolicy {
     public:
        virtual int select(vector<int> , Graph &, Agent) = 0;
        virtual ~SelectionPolicy() {};
 };

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        virtual int select(vector<int> , Graph &, Agent);
        virtual ~MandatesSelectionPolicy();
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
     public:
        virtual int select(vector<int> , Graph &, Agent);
        virtual ~EdgeWeightSelectionPolicy();
 };