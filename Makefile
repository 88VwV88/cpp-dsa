CC := gcc
CXX := g++

app: src/*
	@$(CXX) -O2 -g -Wall src/*.cxx -o ./app
test: app
	@echo "Compilation Complete!"
	@echo "---------------------"
	@./app VwV
	@echo "---------------------"
	@echo "Done!"