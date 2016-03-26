all:
	make playertest
	make dismissaltest
	make overtest

playertest:
	g++ -std=c++11  src/player.cpp src/batsman.cpp src/dismissal.cpp test/playertest.cpp -o playertest

dismissaltest:
	g++ -std=c++11  src/dismissal.cpp test/dismissaltest.cpp -o dismissaltest

overtest:
	g++ -std=c++11  src/over.cpp src/ball.cpp test/overtest.cpp -o overtest

clean:
	rm playertest
	rm dismissaltest
	rm overtest

runtests:
	./playertest
	./dismissaltest
	./overtest
