#target: dependencies
#	rule to build

# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall 
#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time

OBJS = barbarian.o blueMen.o character.o combatMain.o gameMenu.o gameValidate.o harryPotter.o medusa.o vampire.o
SRCS = barbarian.cpp blueMen.cpp character.cpp combatMain.cpp gameMenu.cpp gameValidate.cpp harryPotter.cpp medusa.cpp vampire.cpp
HEADERS = barbarian.hpp blueMen.hpp character.hpp gameMenu.hpp gameValidate.hpp harryPotter.hpp medusa.hpp vampire.hpp

fantasy: ${OBJS}
	${CXX} ${CXXFLAGS} -o fantasy barbarian.o blueMen.o character.o combatMain.o gameMenu.o gameValidate.o harryPotter.o medusa.o vampire.o

combatMain.o: combatMain.cpp ${HEADERS}
	 ${CXX} ${CXXFLAGS} -c gameMenu.cpp barbarian.cpp blueMen.cpp character.cpp combatMain.cpp gameValidate.cpp harryPotter.cpp medusa.cpp vampire.cpp

#barbarian.cpp:barbarian.o
#blueMen.cpp:blueMen.o
#character.cpp:character.o
#gameValidate.cpp:gameValidate.o
#harryPotter.cpp:harryPotter.o
#medusa.cpp:medusa.o
#vampire.cpp:vampire.o
#gameMenu.cpp:gameMenu.o
clean: ${OBJS}
	-rm *.o ${OBJS} fantasy
