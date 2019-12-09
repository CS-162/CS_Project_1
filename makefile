CC = g++ -std=c++11
exe_file = proj1_app
$(exe_file): attack.o monster.o hunter.o main.o
	$(CC) attack.o monster.o hunter.o main.o -o $(exe_file)
attack.o: attack.cpp attack.h
	$(CC) -c attack.cpp
monster.o: monster.cpp monster.h
	$(CC) -c monster.cpp
hunter.o: hunter.cpp hunter.h
	$(CC) -c hunter.cpp
main.o: main.cpp monster.h hunter.h
	$(CC) -c main.cpp

clean:
	rm -f *.out *.o $(exe_file)