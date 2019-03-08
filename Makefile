CC := g++-8
CCOPTS := -w -o ThanosSnap

main : main.cpp Thanos.h Thanos.cpp
	$(CC) $(CCOPTS) main.cpp Thanos.h Thanos.cpp

main.o: main.cpp Thanos.h
Thanos.o: Thanos.h
Thanos.o: Thanos.cpp Thanos.h
