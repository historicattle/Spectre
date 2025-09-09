#pragma once
#include <string>

class Compilation {
private:
	std::string compiler_name;
	std::string flags;
	std::string output_file;
	std::string source_file;

public:	
	Compilation();
	void init();
	int compile();
};