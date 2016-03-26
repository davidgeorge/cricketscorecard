#ifndef INCLUDE_BALLH
#define INCLUDE_BALLH

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
} // namespace Cricket

#endif // INCLUDE_BALLH