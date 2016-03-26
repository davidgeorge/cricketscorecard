#include "dismissal.h"

using namespace Cricket;

Dismissal::Dismissal(EDismissalType eType, const std::string& sBowler, const std::string sFielder)
  : eType_m(eType)
  , sBowler_m(sBowler)
  , sFielder_m(sFielder)
{
   InitialiseDismissalMap();
}

Dismissal::Dismissal(EDismissalType eType, const std::string& sBowler)
  : Dismissal(eType, sBowler, "")
{}

Dismissal::Dismissal(EDismissalType eType)
  : Dismissal(eType, "", "")
{}

Dismissal::Dismissal(const Dismissal& oDis)
{
   *this = oDis;
}

Dismissal& Dismissal::operator=(const Dismissal& oDis)
{
   if (&oDis != this)
   {
      this->eType_m    = oDis.eType_m;
      this->sBowler_m  = oDis.sBowler_m;
      this->sFielder_m = oDis.sFielder_m;
      InitialiseDismissalMap();
   }
 
   return *this;
}

void Dismissal::InitialiseDismissalMap()
{
   DismissalDispatch_m[EDismissalType::ENotOut]      = std::bind(&Dismissal::NotOut, this);
   DismissalDispatch_m[EDismissalType::EBowled]      = std::bind(&Dismissal::Bowled, this);
   DismissalDispatch_m[EDismissalType::ELBW]         = std::bind(&Dismissal::LBW, this);
   DismissalDispatch_m[EDismissalType::ECaught]      = std::bind(&Dismissal::Caught, this);
   DismissalDispatch_m[EDismissalType::ERunOut]      = std::bind(&Dismissal::RunOut, this);
   DismissalDispatch_m[EDismissalType::EObstructing] = std::bind(&Dismissal::Obstructing, this);
   DismissalDispatch_m[EDismissalType::EHandleBall]  = std::bind(&Dismissal::HandleBall, this);
}

std::string Dismissal::DismissalText() const
{
   std::string sDismissalText;
   auto func = DismissalDispatch_m.find(eType_m);
   if (func != DismissalDispatch_m.end())
   {
      sDismissalText = (func->second)(*this);
   }
   return sDismissalText;
}

std::string Dismissal::NotOut() const
{
   return DISMISSAL_NotOut;
}

std::string Dismissal::Bowled() const
{
   return DISMISSAL_Bowled + " " + sBowler_m;
}

std::string Dismissal::LBW() const
{
   return DISMISSAL_LBW + " " + sBowler_m;
}

std::string Dismissal::Caught() const
{
   return DISMISSAL_Caught + " " + sFielder_m + " " + DISMISSAL_Bowled + " " + sBowler_m;
}

std::string Dismissal::RunOut() const
{
   return DISMISSAL_RunOut + " " + sFielder_m;
}

std::string Dismissal::Obstructing() const
{
   return DISMISSAL_Obstruct + " " + DISMISSAL_Bowled + " " + sBowler_m;
}

std::string Dismissal::HandleBall() const
{
   return DISMISSAL_Handled + " " + DISMISSAL_Bowled + " " + sBowler_m;
}

namespace Cricket
{
   std::ostream& operator<<(std::ostream& os, const Dismissal& oDismissal)
   {
      os << oDismissal.DismissalText();
      return os;
   }   
}
