PROJECT_DIR = Navi
PROGRAM_TEST = testGame
PROGRAM_GAME = Darkwing

CXX=g++
CXXFLAGS= -std=c++11 -g -fprofile-arcs -ftest-coverage

LINKFLAGS= -lgtest

SRC_DIR = src
GAME_SRC_DIR = src/game

TEST_DIR = test

SRC_INCLUDE = include
INCLUDE = -I $(SRC_INCLUDE)

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

DOXY_DIR = docs/code

.PHONY: all
all: tests memory coverage docs static style

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o\
	*.gcov *.gcda *.gcno *.orig ???*/*.orig \
	*.bak ???*/*.bak $(PROGRAM_GAME) \
	???*/*~ ???*/???*/*~ $(COVERAGE_RESULTS) \
	$(PROGRAM_TEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR)  \
	$(DOXY_DIR)/html obj bin

$(PROGRAM_TEST): $(TEST_DIR) $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
	$(TEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)

$(PROGRAM_GAME): $(GAME_SRC_DIR) $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_GAME) $(INCLUDE) \
	$(GAME_SRC_DIR)/*.cpp $(SRC_DIR)/*.cpp

compile: $(PROGRAM_GAME)
	$(PROGRAM_GAME)

tests: $(PROGRAM_TEST)
	$(PROGRAM_TEST)

memory: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM_TEST)

coverage: $(PROGRAM_TEST)
	$(PROGRAM_TEST)
	# Determine code coverage
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	# Only show code coverage for the source code files (not library files)
	$(LCOV) --extract $(COVERAGE_RESULTS) */$(PROJECT_DIR)/$(SRC_DIR)/* -o $(COVERAGE_RESULTS)
	#Generate the HTML reports
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	#Remove all of the generated files from gcov
	rm -f *.gcda *.gcno

static: $(SRC_DIR) $(TEST_DIR)
	$(STATIC_ANALYSIS) --verbose --enable=all $(SRC_DIR) $(TEST_DIR) $(SRC_INCLUDE) --suppress=missingInclude

style: $(SRC_DIR) $(TEST_DIR) $(SRC_INCLUDE)
	$(STYLE_CHECK) $(SRC_INCLUDE)/* $(SRC_DIR)/* $(TEST_DIR)/*

docs: $(SRC_INCLUDE)
	doxygen $(DOXY_DIR)/doxyfile
