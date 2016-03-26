#ifndef INCLUDE_OVERH
#define INCLUDE_OVERH

#include "ball.h"
#include <vector>

namespace Cricket
{

   class Over
   {
      const short BALLS_PER_OVER = 6;
      
     public:
      Over(const Over&) = delete;
      Over& operator=(const Over&) = delete;
      
     public:
      Over();
      ~Over() = default;

      void AddBall(const Ball& oBall);
      short LegalDeliveries() const;
      bool IsOverComplete() const;
      bool IsMaiden() const;
      int Runs() const;

     private:
      std::vector<Ball> oBalls_m;
      bool bComplete_m;
   };
   
} // namespace Cricket

#endif // INCLUDE_OVERH