#include "Compilation.h"
#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>

int Compilation::init(std::string path) {
	std::ifstream input_stream(path);
	std::string line = {};

	while(std::getline(input_stream, line)) {
		if (line.find("COMPILER") != std::string::npos) {
			compiler_name = line.substr(line.find('=') + 1);
		} else if (line.find("FLAGS") != std::string::npos) {
			flags = line.substr(line.find('=') + 1);
		} else if (line.find("OUTPUT") != std::string::npos) {
			output_file = line.substr(line.find('=') + 1);
		} else if (line.find("SOURCE") != std::string::npos) {
			source_file = line.substr(line.find('=') + 1);
		}
	}

	return compile();
}

int Compilation::compile() {
	if (compiler_name.empty() || flags.empty() || output_file.empty() || source_file.empty()) {
		std::cerr << "Compilation configuration is incomplete." << std::endl;
		return -1;
	}
	//TODO: Trim whitespace/tabs/newlines from strings
	std::string command = compiler_name + " " + flags + "-g -o " + output_file + " " + source_file;
	int status = system(command.c_str());
	return status;
}

Compilation::Compilation() {
	std::string fifopath="/tmp/compConfig.log";
	int fd = open(fifopath.c_str(), O_RDONLY);
	int status = init(fifopath);

	if(!status){
		close(fd);
	}
}