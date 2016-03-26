#include "batsman.h"

using namespace Cricket;

Batsman::Batsman(const std::string& sName, const std::string& sTeam)
  : Player(sName, sTeam)
  , bBatting_m(false)
  , bDismissed_m(false)
  , iRuns_m(0)
  , iBallsFaced_m(0)
  , oDismissal_m(EDismissalType::ENotOut)
{}

void Batsman::BringToCrease()
{
   bBatting_m = true;
}

void Batsman::FaceBall(int runs)
{
   iRuns_m += runs;
   iBallsFaced_m++;
}

void Batsman::Dismiss(const Dismissal& oDismissal)
{
   bBatting_m   = false;
   bDismissed_m = true;
   oDismissal_m = oDismissal;
}

double Batsman::StrikeRate() const
{
   double dStrikeRate = ((double)iRuns_m / iBallsFaced_m) * 100;
}
