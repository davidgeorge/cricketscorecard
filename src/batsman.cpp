#include "batsman.h"

using namespace Cricket;

Batsman::Batsman(const std::string& sName, const std::string& sTeam)
  : Player(sName, sTeam)
  , bBatting_m(false)
  , bDismissed_m(false)
  , iRuns_m(0)
{}

void Batsman::BringToCrease()
{
   bBatting_m = true;
}

void Batsman::AddRuns(int runs)
{
   iRuns_m += runs;  
}

void Batsman::Dismiss()
{
   bBatting_m = false;
   bDismissed_m = true;
}

bool Batsman::Batting() const
{
   return bBatting_m;
}

bool Batsman::Dismissed() const
{
   return bDismissed_m;
}

int Batsman::Runs() const
{
   return iRuns_m;
}
