SRCS=WheelIO.cpp KeyQueue.cpp Player.cpp PlayerAPI.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

all: libwheel.so

testwheel: $(OBJS) testwheel.o
	g++ -g -Wall -o $@ $^ -lpthread -lwiringPi

libwheel.so: $(OBJS)
	g++ -g -Wall -shared -o $@ $^ -lpthread -lwiringPi

%.o: %.cpp
	g++ -g -Wall -c $^

clean:
	rm -f libwheel.so
	rm -f *.o
