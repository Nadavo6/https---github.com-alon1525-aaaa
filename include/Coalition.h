#pragma once

#include <vector>


using std::vector;
class Party;
class Simulation;
class Agent;

class Coalition
{
public:
    Coalition(Agent firstAgent);
    void addParty(Party &party,Simulation &s);
    void addOfferedParty(int partyId);
    bool hasBeenOffered(int party);
    int getTotalMandates();
    int getCoalitionId();
    vector<int> coalitionList;
private:
    int totalMandates;
    vector<int> offeredParties;
    int selectionPolicy;
    int coalitionId;
};