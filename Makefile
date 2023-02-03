CXX = c++
CFLAGS = -std=c++14
CXXSOURCE = main.cpp cmdline.cpp expr.cpp test.cpp
HEADERS = cmdline.hpp expr.hpp catch.hpp
OBJS = main.o cmdline.o expr.o test.o

msdscript: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o msdscript
	
cmdline.o: cmdline.cpp cmdline.hpp catch.hpp
	$(CXX) $(CFLAGS) -c cmdline.cpp

expr.o: expr.cpp expr.hpp catch.hpp
	$(CXX) $(CFLAGS) -c expr.cpp
	
test.o: test.cpp catch.hpp
	$(CXX) $(CFLAGS) -c test.cpp
	
main.o: main.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c main.cpp
	
clean:
	rm -f *.o *.out program

.PHONY: default
default: msdscript;

.PHONY: test
test: msdscript
	./msdscript --test
