all:
	make playertest
	make dismissaltest

playertest:
	g++ -std=c++11  src/player.cpp src/batsman.cpp src/dismissal.cpp test/playertest.cpp -o playertest

dismissaltest:
	g++ -std=c++11  src/dismissal.cpp test/dismissaltest.cpp -o dismissaltest

clean:
	rm playertest
	rm dismissaltest

runtests:
	./playertest
	./dismissaltest
