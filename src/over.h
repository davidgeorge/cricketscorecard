#ifndef INCLUDE_OVERH
#define INCLUDE_OVERH

#include <vector>

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
     public:
      Ball() = delete;
      Ball& operator=(const Ball&) = delete;
     
     public:
      Ball(EBallType eType);
      Ball(EBallType eType, int iRuns);
      Ball(const Ball&) = default;
      ~Ball() = default;
      
      EBallType BallType() const;
      int Runs()           const;
      bool LegalDelivery() const;

     private:
      EBallType eType_m;
      int iRuns_m;
   };
   
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