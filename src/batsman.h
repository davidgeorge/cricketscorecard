#ifndef INCLUDE_BATSMANH
#define INCLUDE_BATSMANH

#include "player.h"

namespace Cricket
{
   
   class Batsman : public Player
   {
      public:
       Batsman() = delete;
       Batsman(const Batsman&) = delete;
       Batsman& operator=(const Batsman&) = delete;
      
      public:
       Batsman(const std::string& sName, const std::string& sTeam);
       ~Batsman() = default;

       void BringToCrease();
       void ScoreRuns(int runs);
       void Dismiss();

       inline bool Batting()   const { return bBatting_m;   }
       inline bool Dismissed() const { return bDismissed_m; }
       inline int Runs()       const { return iRuns_m;      }

      private:
       bool bDismissed_m;
       bool bBatting_m;
       int iRuns_m;
   };
   
} // namespace Cricket

#endif // INCLUDE_BATSMANH