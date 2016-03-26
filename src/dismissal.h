#ifndef INCLUDE_DISMISSALH
#define INCLUDE_DISMISSALH

#include <string>
#include <map>
#include <iostream>
#include <functional>

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
   
   class Dismissal
   {
     const std::string DISMISSAL_NotOut   = "not out"; 
     const std::string DISMISSAL_RunOut   = "run out";
     const std::string DISMISSAL_Bowled   = "b";
     const std::string DISMISSAL_LBW      = "lbw";
     const std::string DISMISSAL_Caught   = "c";
     const std::string DISMISSAL_Obstruct = "obstructing the field";
     const std::string DISMISSAL_Handled  = "handled ball";
      
     public:
      Dismissal() = delete;

     public:
      Dismissal(EDismissalType eType, const std::string& sBowler, const std::string sFielder);
      Dismissal(EDismissalType eType, const std::string& sBowler);
      Dismissal(EDismissalType eType);
      Dismissal(const Dismissal& oDis);
      Dismissal& operator=(const Dismissal& oDis);
      ~Dismissal() = default;

      inline EDismissalType Type()        const { return eType_m;    }
      inline const std::string& Bowler()  const { return sBowler_m;  }
      inline const std::string& Fielder() const { return sFielder_m; }

      friend std::ostream& operator<<(std::ostream& os, const Dismissal& dt);

     private:
      void InitialiseDismissalMap();
      std::string DismissalText() const;
      std::string NotOut() const;
      std::string Bowled() const;
      std::string LBW() const;
      std::string Caught() const;
      std::string RunOut() const;
      std::string Obstructing() const;
      std::string HandleBall() const;

      EDismissalType eType_m;
      std::string sBowler_m;
      std::string sFielder_m;
      
      typedef std::function<std::string(const Dismissal&)> DismissalStream; 
      std::map<EDismissalType, DismissalStream> DismissalDispatch_m;
   };
   
} // namespace Cricket

#endif // INCLUDE_DISMISSALH