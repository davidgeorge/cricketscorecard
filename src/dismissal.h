#ifndef INCLUDE_DISMISSALH
#define INCLUDE_DISMISSALH

#include <string>
#include <map>
#include <iostream>

namespace Cricket
{
   
   enum class EDismissalType
   {
       ENotOut
     , EBowled
     , ELBW
     , ECaught
     , ERunOut
     , EObstructing
     , EHandleBall
   };
   
   const std::map<EDismissalType, std::string> DismissalDescription = 
   {
        { EDismissalType::ENotOut,       "Not Out"           }
      , { EDismissalType::EBowled,       "b"                 }
      , { EDismissalType::ELBW,          "lbw"               }
      , { EDismissalType::ECaught,       "c"                 }
      , { EDismissalType::ERunOut,       "run out"           }
      , { EDismissalType::EObstructing,  "obstructing field" }
      , { EDismissalType::EHandleBall,   "handled ball"      }
   };
   
   class Dismissal
   {
     public:
      Dismissal() = delete;
      Dismissal(const Dismissal&) = delete;
      Dismissal& operator=(const Dismissal&) = delete;

     public:
      Dismissal(EDismissalType eType);
      Dismissal(EDismissalType eType, const std::string& sBowler);
      Dismissal(EDismissalType eType, const std::string& sBowler, const std::string sFielder);

      friend std::ostream& operator<<(std::ostream& os, const Dismissal& dt);

     private:
      EDismissalType eType_m;
      std::string sBowler_m;
      std::string sFielder_m;
   };
   
} // namespace Cricket

#endif // INCLUDE_DISMISSALH