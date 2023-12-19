CXX := g++
CXXGLAGS := -O2 -g -Wall -stdc++=20

app: src/*
	@$(CXX) $(CXXFLAGS) src/*.cxx -o ./app
test: app
	@echo "Compilation Complete!"
	@echo "---------------------"
	@./app VwV
	@echo "---------------------"
	@echo "Done!"
memtest: app
	@echo "---------------------"
	@valgrind --track-origins=yes -s ./app
	@echo "---------------------"

.PHONY: test memtest