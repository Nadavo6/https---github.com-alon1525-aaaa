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

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Party getParty() const;
    
    bool isOriginal;
    virtual ~Agent();//destructor
    Agent(const Agent &other);//copy constractor
    Agent(Agent&& other);
    Agent& operator=(const Agent &other);
    Agent& operator=(Agent &&other);
    queue<Party> pickingOrder;
    int getSelectionPolicy() const;
    Coalition agentCoalition = Coalition(*this);
    bool start;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Party *agentsParty; 
    
    
    
};
