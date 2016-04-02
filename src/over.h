#ifndef INCLUDE_OVERH
#define INCLUDE_OVERH

#include "ball.h"
#include <vector>
#include <iostream>

namespace Cricket
{

   class Over
   {
      const short BALLS_PER_OVER = 6;   
      
     public:
      Over();
      Over(const Over&);
      ~Over() = default;

      Over& operator=(const Over&);
     
      void AddBall(const Ball& oBall);
      short LegalDeliveries() const;
      bool IsOverComplete() const;
      bool IsMaiden() const;
      int Runs() const;
      int Wickets() const;

      friend std::ostream& operator<<(std::ostream& os, const Over& oOver);

     private:
      std::vector<Ball> oBalls_m;
      bool bComplete_m;
   };
   
} // namespace Cricket

#endif // INCLUDE_OVERH