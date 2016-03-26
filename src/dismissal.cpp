#include "dismissal.h"

using namespace Cricket;

Dismissal::Dismissal(EDismissalType eType)
  : Dismissal(eType, "", "")
{}

Dismissal::Dismissal(EDismissalType eType, const std::string& sBowler)
  : Dismissal(eType, sBowler, "")
{}

Dismissal::Dismissal(EDismissalType eType, const std::string& sBowler, const std::string sFielder)
  : eType_m(eType)
  , sBowler_m(sBowler)
  , sFielder_m(sFielder)
{}

namespace Cricket
{
   std::ostream& operator<<(std::ostream& os, const Dismissal& oDismissal)
   {
      // TODO
      return os;
   }   
}
