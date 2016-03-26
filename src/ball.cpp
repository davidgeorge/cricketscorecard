#include "ball.h"

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