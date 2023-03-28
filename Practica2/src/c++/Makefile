PROG:=main
SRCS:=main.cc

CXX:= g++ -O2 -std=c++11

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

main.o: main.cc
main: main.o
