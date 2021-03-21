SRCS=$(shell find $(PWD) -name \*.cpp)
OBJS=$(SRCS:%.cpp=%.o)

CC=g++
OPT=-03
CPPFLAGS=-std=c++11

TARGET=net

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(CPPFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CPPFLAGS)

.PHONY: clean
clean:
	$(RM) -rf $(TARGET)
	$(RM) -rf $(OBJS)