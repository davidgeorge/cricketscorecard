#include "ball.h"

using namespace Cricket;

Ball::Ball(EBallType eType, int iRuns)
  : eType_m(eType)
  , iRuns_m(iRuns)
{
   if (iRuns == 0 && eType_m == EBallType::ERun)
   {
      eType_m = EBallType::EDot;  
   }
}

Ball::Ball(const Ball& oBall)
{
   *this = oBall;
}

Ball& Ball::operator=(const Ball& oBall)
{
   if (this != &oBall)
   {
      this->eType_m = oBall.eType_m;
      this->iRuns_m = oBall.iRuns_m;
   }
   return *this;
}

Ball::Ball(EBallType eType)
  : Ball(eType, 0)
{
   if (eType_m == EBallType::EWide || eType_m == EBallType::ENoBall)
   {
      iRuns_m = 1;
   }
}

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

namespace Cricket
{
   std::ostream& operator<<(std::ostream& os, const Ball& oBall)
   {
      if (oBall.iRuns_m != 0)
      {
         os << oBall.iRuns_m;
      }
      os << oBall.BallDisplayMap.at(oBall.eType_m);
      return os;
   }   
}
