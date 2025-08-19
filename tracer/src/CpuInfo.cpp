#include "CpuInfo.h"
#include<iostream>
#include<string>

void CpuInfo::init(){
	std::ifstream cpuInfoFile("/proc/cpuInfo");
	std::string line;

	while (std::getline(cpuInfoFile, line)) {
		if (line.find("processor") != std::string::npos) {
			numCores = std::stoi(line.substr(line.find(":") + 1));
		}
		else if (line.find("cache size") != std::string::npos) {
			cacheSize = std::stoll(line.substr(line.find(":") + 1));
		}
		else if (line.find("model name") != std::string::npos){
			modelName = line.substr(line.find(":") + 1);
		}
		else if (line.find("vendor_id") != std::string::npos) {
			vendorId = std::stoi(line.substr(line.find(":") + 1));
		}
		else if()
	}
}