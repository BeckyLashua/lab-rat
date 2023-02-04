CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o utility.o Space.o Cage.o LabFloor.o Closet.o Vent.o BreakRoom.o Office.o Outside.o Game.o

SRCS = main.cpp utility.cpp Space.cpp Cage.cpp LabFloor.cpp Closet.cpp Vent.cpp BreakRoom.cpp Office.cpp Outside.cpp Game.cpp

HEADERS = utility.hpp Space.hpp Cage.hpp LabFloor.hpp Closet.hpp Vent.hpp BreakRoom.hpp Office.hpp Outside.hpp Game.hpp

VALOPTIONS = --leak-check=full --show-leak-kinds=all --track-origins=yes

final: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o final

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

val:
	valgrind ${VALOPTIONS} ./final

clean:
	rm *.o final
