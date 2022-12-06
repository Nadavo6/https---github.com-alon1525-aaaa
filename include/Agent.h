#pragma once
#include <vector>
#include "SelectionPolicy.h"
#include "Coalition.h"
#include "Party.h"
#include <queue>

using namespace std;
class Simulation;
class Coalition;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent();
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Party getParty() const;
    virtual ~Agent();//destructor
    Agent(const Agent &other);//copy constractor
    Agent(Agent&& other);//move copy constuctor
    Agent& operator=(const Agent &other);//assignment operator
    Agent& operator=(Agent &&other);//move assignment operator
    std::queue<int> pickingOrder;
    int getSelectionPolicy() const;
    SelectionPolicy* getSPType() const;
    std::vector<std::pair<int, int>> neighbors;
    bool start;
    Coalition agentsCoalition;
    Coalition &getAgentCoalition();

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    
    
    
};
