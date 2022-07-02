CXX = g++
CXXFLAGS = -std=c++14 -MMD
OBJECTS = controller.o drinks.o item.o main.o mains.o menu.o menuViewer.o sides.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = restaurant

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}
