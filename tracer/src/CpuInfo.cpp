#include "CpuInfo.h"
#include<string>
#include <fstream>

void CpuInfo::init(){
    std::ifstream cpuInfoFile("/proc/cpuinfo");
    std::string line;

	while (std::getline(cpuInfoFile, line)) {
		if (line.find("cpu cores") != std::string::npos) {
			numCores = std::stoi(line.substr(line.find(":") + 1));
		}
		else if (line.find("cache size") != std::string::npos) {
			cacheSize = std::stoull(line.substr(line.find(":") + 1));
		}
		else if (line.find("model name") != std::string::npos){
			modelName = line.substr(line.find(":") + 1);
		}
		else if (line.find("vendor_id") != std::string::npos) {
			vendorId = line.substr(line.find(":") + 1);
		}
	}
}