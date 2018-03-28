#target
TARGET=main
#compiler
CXX=g++
#compiling flags
CPPFLAGS=-std=c++11 -g -Wall -I.
#linking flags
LDFLAGS=-std=c++11 -g -Wall -I.

#directories
BIND=bin
SRCD=src
LIBD=lib
OBJD=obj
rm=rm -f

SRCS:=$(wildcard $(SRCD)/*.cpp)
INCS:=$(wildcard $(LIBD)/*.hpp)
OBJS:=$(SRCS:$(SRCD)/%.cpp=$(OBJD)/%.o)

$(BIND)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@
	
$(OBJS): $(OBJD)/%.o : $(SRCD)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	$(rm) $(OBJS)
	$(rm) $(BIND)/$(TARGET)