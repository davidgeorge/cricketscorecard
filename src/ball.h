#ifndef INCLUDE_BALLH
#define INCLUDE_BALLH

#include <iostream>
#include <string>
#include <map>

namespace Cricket
{

   enum class EBallType
   {
        EDot
      , ERun
      , EWide
      , ENoBall
      , EBye
      , ELegBye
      , EWicket
   };
   
   class Ball
   {
      const std::map<EBallType, std::string> BallDisplayMap =
      {
          { EBallType::EDot,    "."  }
        , { EBallType::ERun,    ""   }
        , { EBallType::EWide,   "wd" }
        , { EBallType::ENoBall, "nb" }
        , { EBallType::EBye,    "b"  }
        , { EBallType::ELegBye, "lb" }
        , { EBallType::EWicket, "W"  }
      };

     public:
      Ball() = delete;
     
     public:
      Ball(EBallType eType);
      Ball(EBallType eType, int iRuns);
      Ball(const Ball& oBall);
      ~Ball() = default;
      
      Ball& operator=(const Ball& oBall);
      
      EBallType BallType() const;
      int Runs()           const;
      bool LegalDelivery() const;

      friend std::ostream& operator<<(std::ostream& os, const Ball& oBall);

     private:
      EBallType eType_m;
      int iRuns_m;
   };
} // namespace Cricket

#endif // INCLUDE_BALLH