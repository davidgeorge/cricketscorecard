playertest:
	g++ -std=c++11  src/player.cpp test/playertest.cpp -o playertest

clean:
	rm playertest
