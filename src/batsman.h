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
   };
   
} // namespace Cricket

#endif // INCLUDE_BATSMANH