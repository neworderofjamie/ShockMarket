.PHONY: all clean

all: shock_market

shock_market: Main.o Market.o
	@$(CXX) $(LDFLAGS) Main.o Market.o -o shock_market

Main.o: Main.cpp
	@$(CXX) -c $(CXXFLAGS) Main.cpp -o Main.o

Market.o: Market.cpp
	@$(CXX) -c $(CXXFLAGS) Market.cpp -o Market.o

clean:
	@rm -f *.o shock_market
