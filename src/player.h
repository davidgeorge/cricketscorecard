#ifndef INCLUDE_PLAYERH
#define INCLUDE_PLAYERH

#include <string>

namespace Cricket
{
   class Player
   {
     public:
      Player() = delete;
      Player(const Player&) = delete;
      Player& operator=(const Player&) = delete;
      
     public:
      Player(const std::string& sName, const std::string& sTeam);
      ~Player() = default;
   
      inline const std::string& Name() const { return sName_m; }
      inline const std::string& Team() const { return sTeam_m; }

     private:
      std::string sName_m;
      std::string sTeam_m; 
   };

} // namesapce Cricket

#endif // INCLUDE_PLAYERH