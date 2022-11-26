#include "Coalition.h"
#include "Party.h"
#include "Simulation.h"
#include <algorithm>


Coalition::Coalition(int partyId, SelectionPolicy *mselectionPolicy) : coalitionList(1,partyId),totalMandates(0),offeredParties(),selectionPolicy(mselectionPolicy->whichPolicy()),coalitionId(partyId)
{

}

Coalition::Coalition(const Coalition &other): coalitionList(other.coalitionList),totalMandates(other.totalMandates),offeredParties(other.offeredParties),selectionPolicy(other.selectionPolicy),coalitionId(other.coalitionId){}

int Coalition::getTotalMandates()
{
    return totalMandates;
}

int Coalition::getCoalitionId()
{
    return coalitionId;
}

void Coalition::addMandates(int mandates)
{
    totalMandates = totalMandates + mandates;
}

void Coalition::addParty(Party &party,Simulation &sim)
{
    party.closeState();
    coalitionList.push_back(party.getmId());
    totalMandates = totalMandates + party.getMandates();
    sim.addAgent(party.getmId());
//     if (selectionPolicy == 1)
//     {
//         Agent newAgent = Agent(party.getmId(),party.getmId(),new MandatesSelectionPolicy);
//         newAgent.start = false;
//         std::vector<std::pair<int,int>> neighboors = sim.getGraph().getNeighbors(sim.getParty2(newAgent.getPartyId()));  
//         int neighboorSize = neighboors.size(); 
//         for (int i = 1; i < neighboorSize; i++)
//         {
//             std::pair<int,int> value = neighboors[i];
//             while (i>0 && (newAgent.getSPType())->Choose(sim.getParty2(value.second),sim.getParty2(neighboors[i-1].second),value.first,neighboors[i-1].first).getmId() != value.second)
//             {
//                 neighboors[i] = neighboors[i-1];
//                 i=i-1;
//             }
//             neighboors[i] = value;
            
//         }
//         for(int i=(neighboorSize-1);i>=0;i--)
//         {
//             newAgent.pickingOrder.push(neighboors[i].second);
//         }
//         sim.getAgentsList().push_back(newAgent);

//     }
//     else
//     {
//         Agent newAgent = Agent(party.getmId(),party.getmId(),new EdgeWeightSelectionPolicy);
//         newAgent.start = false;
//         std::vector<std::pair<int,int>> neighboors = sim.getGraph().getNeighbors(sim.getParty2(newAgent.getPartyId()));  
//         int neighboorSize = neighboors.size(); 
//         for (int i = 1; i < neighboorSize; i++)
//         {
//             std::pair<int,int> value = neighboors[i];
//             while (i>0 && (newAgent.getSPType())->Choose(sim.getParty2(value.second),sim.getParty2(neighboors[i-1].second),value.first,neighboors[i-1].first).getmId() != value.second)
//             {
//                 neighboors[i] = neighboors[i-1];
//                 i=i-1;
//             }
//             neighboors[i] = value;
            
//         }
//         for(int i=(neighboorSize-1);i>=0;i--)
//         {
//             newAgent.pickingOrder.push(neighboors[i].second);
//         }
//         sim.getAgentsList().push_back(newAgent);
//     }
    
    
    
}

void Coalition::addOfferedParty(int partyId)
{
    offeredParties.push_back(partyId);//if we have time we can make it more efficient by doing a binary search and sorting the vector
}

bool Coalition::hasBeenOffered(int partyId)
{
    if(std::find(offeredParties.begin(),offeredParties.end(),partyId) != offeredParties.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}