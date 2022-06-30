CXX = g++
CXXFLAGS = -std=c++14 -MMD
OBJECTS = bishop.o board.o computer.o controller.o empty.o graphicsView.o king.o knight.o main.o pawn.o pieces.o queen.o rook.o textView.o usefulFuncs.o view.o window.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = chess

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}
