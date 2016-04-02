#include "over.h"

#include <algorithm>
#include <numeric>

using namespace Cricket;

Over::Over()
  : bComplete_m(false)
{}

Over::Over(const Over& oOver)
{
   *this = oOver; 
}

Over& Over::operator=(const Over& oOver)
{
   if (this != &oOver)
   {
      this->oBalls_m    = oOver.oBalls_m;
      this->bComplete_m = oOver.bComplete_m;   
   }
   return *this;
}

void Over::AddBall(const Ball& oBall)
{
   if (!bComplete_m)
      oBalls_m.push_back(oBall);
     
   bComplete_m = (LegalDeliveries() == BALLS_PER_OVER);
}

short Over::LegalDeliveries() const
{
   short sLegalDeliveries = 0;
   std::for_each(begin(oBalls_m), end(oBalls_m), [&](const Ball& oBall)
   {
      if (oBall.LegalDelivery())
         sLegalDeliveries++;
   });
   return sLegalDeliveries;
}

bool Over::IsOverComplete() const
{
   return bComplete_m;
}

int Over::Runs() const
{
   int runs = 0;
   for (auto ball : oBalls_m)
   {
      runs += ball.Runs();
   }
   return runs;
}

int Over::Wickets() const
{
   int wickets = 0;
   std::for_each(begin(oBalls_m), end(oBalls_m), [&](const Ball& oB)
   {
      if (oB.BallType() == EBallType::EWicket)
      {
         wickets++;
      }
   });
   return wickets;
}

bool Over::IsMaiden() const
{
   return IsOverComplete() && Runs() == 0;   
}

namespace Cricket
{
   std::ostream& operator<<(std::ostream& os, const Over& oOver)
   {
      std::for_each(begin(oOver.oBalls_m), end(oOver.oBalls_m), [&](const Ball oB) { os << oB << " "; });
      return os;
   }
}
