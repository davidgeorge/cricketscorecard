playertest:
	g++ -std=c++11  src/player.cpp src/batsman.cpp test/playertest.cpp -o playertest

clean:
	rm playertest
