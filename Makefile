SRCS=WheelIO.cpp KeyQueue.cpp Player.cpp PlayerAPI.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

all: libwheel.so

libwheel.so: $(OBJS)
	g++ -g -Wall -shared -o $@ $^ -lpthread -lwiringPi

%.o: %.cpp
	g++ -g -Wall -c $^

clean:
	rm -f libwheel.so
	rm -f *.o
