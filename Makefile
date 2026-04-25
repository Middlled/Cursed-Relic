all: compile link run

compile:
	g++ -c cursed_relic.cpp -I"D:/SFML/SFML-3.1.0/include"

link:
	g++ cursed_relic.o -o CursedRelic.exe -L"D:/SFML/SFML-3.1.0/lib" -lsfml-graphics -lsfml-window -lsfml-system

run:
	./CursedRelic.exe

clean:
	rm -f *.o CursedRelic.exe