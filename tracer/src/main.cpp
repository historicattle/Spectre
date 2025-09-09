#include "Compilation.h"
#include<iostream>
#include<cstdlib>

int main() {
	
	Compilation compilation;
	compilation.compile();

	system("RunMassif.sh");



	return 0;
}