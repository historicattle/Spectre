#pragma once
#include <string>

class CpuInfo {
private:
	unsigned int numCores;
	unsigned int numThreads;
	unsigned long long int cacheSize;
	std::string vendorId;
	std::string modelName;

public:
	CpuInfo() : numCores(0), numThreads(0), cacheSize(0) {}
	void init();
	unsigned int getNumCores() const { return numCores; }
	unsigned int getNumThreads() const { return numThreads; }
	unsigned long long getCacheSize() const { return cacheSize; }
	const std::string& getVendorId() const { return vendorId; }
	const std::string& getModelName() const { return modelName; }
	static CpuInfo& getInstance() {
		static CpuInfo instance;
		return instance;
	}

};
