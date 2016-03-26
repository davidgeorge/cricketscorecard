#include "../testframework/xpunitest.h"
#include "../src/player.h"
#include "../src/batsman.h"
#include "../src/dismissal.h"

using namespace Cricket;

XpUnitTest(BatsmanTest, "Testing the Batsman")
{
   std::string sName = "Steve Waugh";
   std::string sTeam = "Australia";
   Batsman batsman(sName, sTeam);
   
   XpAssertEqual("Test batsman's name is set", sName, batsman.Name());
   XpAssertEqual("Test batsman's team is set", sTeam, batsman.Team());
   XpAssertEqual("Test batsman has is not batting", false, batsman.Batting());
   XpAssertEqual("Test batsman's is not dismissed", false, batsman.Dismissed());
   XpAssertEqual("Test batsman has scored no runs", 0, batsman.Runs());
   XpAssertEqual("Test batsman has faced no balls", 0, batsman.BallsFaced());
   
   batsman.BringToCrease();
   XpAssertEqual("Test batsman is now batting", true, batsman.Batting());
   XpAssertEqual("Test batsman's is not dismissed", false, batsman.Dismissed());

   batsman.FaceBall(0);
   XpAssertEqual("Test batsman has scored no runs", 0, batsman.Runs());
   XpAssertEqual("Test batsman has faced a ball", 1, batsman.BallsFaced());
   batsman.FaceBall(2);
   XpAssertEqual("Test batsman has scored runs", 2, batsman.Runs());
   XpAssertEqual("Test batsman has faced balls", 2, batsman.BallsFaced());
   batsman.FaceBall(4);
   XpAssertEqual("Test batsman has scored runs", 6, batsman.Runs());
   XpAssertEqual("Test batsman has faced balls", 3, batsman.BallsFaced());
   
   for (int i = 0; i < 120; i++) { batsman.FaceBall(0); }
   XpAssertEqual("Test batsman has faced balls", 123, batsman.BallsFaced());
   
   Dismissal oDismissal(EDismissalType::EBowled, "Steve Waugh");
   batsman.Dismiss(oDismissal);
   XpAssertEqual("Test batsman is no longer batting", false, batsman.Batting());
   XpAssertEqual("Test batsman's has been dismissed", true, batsman.Dismissed());
}

XpUnitTest(PlayerTest, "Creating the base player class")
{
   std::string sName = "Steve Waugh";
   std::string sTeam = "Australia";
   Player player(sName, sTeam);
   
   XpAssertEqual("Test name is set", sName, player.Name());
   XpAssertEqual("Test team is set", sTeam, player.Team());
}

XPUNIT_MAIN("TestPlayer")
