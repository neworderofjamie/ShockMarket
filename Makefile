OBJECTS = Main.o Market.o

.PHONY: all clean

all: shock_market

shock_market: $(OBJECTS)
	@$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	@$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	@rm -f *.o shock_market
