CXX = g++
CXXFLAGS = -Wall

proj4: Game.o Area.o Hero.o Enemy.o Creeper.o Mandarin.o Mannequin.o Weapon.o Plank.o Chainsaw.o Shotgun.o proj4.cpp
	$(CXX) $(CXXFLAGS) Game.o Area.o Hero.o Enemy.o Creeper.o Mandarin.o Mannequin.o Weapon.o Plank.o Chainsaw.o Shotgun.o proj4.cpp -o proj4

Game.o: Game.h Game.cpp Area.h Hero.h Enemy.h Weapon.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Area.o: Area.h Area.cpp
	$(CXX) $(CXXFLAGS) -c Area.cpp

Hero.o: Hero.h Hero.cpp Weapon.h Plank.h Chainsaw.h Shotgun.h
	$(CXX) $(CXXFLAGS) -c Hero.cpp

Enemy.o: Enemy.h Enemy.cpp Creeper.h Mandarin.h Mannequin.h
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

Creeper.o: Creeper.h Creeper.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Creeper.cpp

Mandarin.o: Mandarin.h Mandarin.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Mandarin.cpp

Mannequin.o: Mannequin.h Mannequin.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Mannequin.cpp

Weapon.o: Weapon.h Weapon.cpp Plank.h Chainsaw.h Shotgun.h
	$(CXX) $(CXXFLAGS) -c Weapon.cpp

Plank.o: Plank.h Plank.cpp Weapon.h
	$(CXX) $(CXXFLAGS) -c Plank.cpp

Chainsaw.o: Chainsaw.h Chainsaw.cpp Weapon.h
	$(CXX) $(CXXFLAGS) -c Chainsaw.cpp

Shotgun.o: Shotgun.h Shotgun.cpp Weapon.h
	$(CXX) $(CXXFLAGS) -c Shotgun.cpp

clean:
	rm *.o
	rm *~

run:
	./proj4 proj4_map1.txt

run1:
	./proj4 proj4_map2.txt

val:
	valgrind ./proj4 proj4_map1.txt

val1:
	valgrind ./proj4 proj4_map2.txt

submit:
	cp Game.h Game.cpp Area.h Area.cpp Hero.h Hero.cpp Enemy.h Enemy.cpp Creeper.h Creeper.cpp \
	Mandarin.h Mandarin.cpp Mannequin.h Mannequin.cpp Weapon.h Weapon.cpp Plank.h Plank.cpp Chainsaw.h Chainsaw.cpp \
	Shotgun.h Shotgun.cpp proj4.cpp ~/cs202proj/proj4
