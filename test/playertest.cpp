#include "../testframework/xpunitest.h"
#include "../src/player.h"
#include "../src/batsman.h"
#include "../src/dismissal.h"

using namespace Cricket;

XpUnitTest(BatsmanStrikeRateTest, "Testing the Batsman's strike rate")
{
   Batsman steveWaugh("Steve Waugh", "Australia");
   // Score 100 runs in 100 balls
   steveWaugh.BringToCrease();
   for (int i = 0; i < 100; i++) { steveWaugh.FaceBall(1); }
   XpAssertEqual("Expecting a strike rate of 100", 100.00, steveWaugh.StrikeRate());
   
   Batsman glennMcGrath("Glenn McGrath", "Australia");
   glennMcGrath.BringToCrease();
   for (int i = 0; i < 10; i++) { glennMcGrath.FaceBall(1); }
   for (int i = 0; i < 90; i++) { glennMcGrath.FaceBall(0); }
   XpAssertEqual("Expecting a strike rate of 10", 10.00, glennMcGrath.StrikeRate());
   
   Batsman adamGilchrist("Adam Gilchrist", "Australia");
   adamGilchrist.BringToCrease();
   for (int i = 0; i < 10; i++) { adamGilchrist.FaceBall(2); }
   adamGilchrist.FaceBall(6);
   adamGilchrist.FaceBall(6);
   XpAssertEqual("Expecting a strike rate of 266.66", 266.66, glennMcGrath.StrikeRate());
}

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
