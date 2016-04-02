all:
	make playertest
	make dismissaltest
	make overtest
	make bowlertest
   
playertest:
	g++ -std=c++11  src/player.cpp src/batsman.cpp src/dismissal.cpp test/playertest.cpp -o playertest

dismissaltest:
	g++ -std=c++11  src/dismissal.cpp test/dismissaltest.cpp -o dismissaltest

overtest:
	g++ -std=c++11  src/over.cpp src/ball.cpp test/overtest.cpp -o overtest

bowlertest:
	g++ -std=c++11  src/bowler.cpp src/ball.cpp src/over.cpp src/player.cpp test/bowlertest.cpp -o bowlertest

clean:
	rm playertest
	rm dismissaltest
	rm overtest
	rm bowlertest

runtests:
	./playertest
	./dismissaltest
	./overtest
	./bowlertest
