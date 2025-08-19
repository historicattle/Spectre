#pragma once

class Compilation {
private:
	std::string compiler_name;
	std::string flags;
	std::string output_file;
	std::string source_file;
	Compilation() {}

public:	
	void init() {}
	int compile() {}
}