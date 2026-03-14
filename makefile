CXX = g++
CXXFLAGS = -O2 -Wall -std=c++17

OBJS = main.o Grid.o Field.o BoundaryConditions.o SpatialDiscretization.o TimeIntegrator.o Solver.o

advection1d: $(OBJS)
	$(CXX) $(CXXFLAGS) -o advection1d $(OBJS)

main.o: main.cpp Solver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Grid.o: Grid.cpp Grid.h
	$(CXX) $(CXXFLAGS) -c Grid.cpp

Field.o: Field.cpp Field.h
	$(CXX) $(CXXFLAGS) -c Field.cpp

BoundaryConditions.o: BoundaryConditions.cpp BoundaryConditions.h Field.h
	$(CXX) $(CXXFLAGS) -c BoundaryConditions.cpp

SpatialDiscretization.o: SpatialDiscretization.cpp SpatialDiscretization.h BoundaryConditions.h
	$(CXX) $(CXXFLAGS) -c SpatialDiscretization.cpp

TimeIntegrator.o: TimeIntegrator.cpp TimeIntegrator.h
	$(CXX) $(CXXFLAGS) -c TimeIntegrator.cpp

Solver.o: Solver.cpp Solver.h SpatialDiscretization.h TimeIntegrator.h
	$(CXX) $(CXXFLAGS) -c Solver.cpp

clean:
	rm -f *.o advection1d solution.dat