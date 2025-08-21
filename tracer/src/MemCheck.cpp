#include <iostream>
#include <cstdlib>
#include <fstream>
#include <regex>

void parseMemCheck();

int main() {
	system("./RunMemcheck.sh");

	std::ifstream file("../output/MemcheckOut.log");
	if (!file.is_open()) {
		std::cerr << "Error opening valgrind memcheck log file." << std::endl;
		return 1;
	}

}

//TODO: 
// 1. Illegal read/write
// 2. Using uninitialized values
// 3. Illegal frees

void parseMemCheck() {
	std::ifstream memcheck("../output/MemcheckOut.log");
	std::string line;

	std::smatch rwmatch;
	std::smatch uninitmatch;
	std::smatch illegalfreematch;

	while (std::getline(memcheck, line)) {
		//if(std::regex_match())
	}
	
}