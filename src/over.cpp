#include "over.h"

#include <algorithm>
#include <numeric>

using namespace Cricket;

Ball::Ball(EBallType eType, int iRuns)
  : eType_m(eType)
  , iRuns_m(iRuns)
{}

Ball::Ball(EBallType eType)
  : Ball(eType, 0)
{}

EBallType Ball::BallType() const
{
   return eType_m;
}

int Ball::Runs() const
{
   return iRuns_m;
}

bool Ball::LegalDelivery() const
{
   return eType_m != EBallType::ENoBall && eType_m != EBallType::EWide;
}

Over::Over()
  : bComplete_m(false)
{}

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

bool Over::IsMaiden() const
{
   return IsOverComplete() && Runs() == 0;   
}
