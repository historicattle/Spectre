#pragma once
#include<vector>
#include<string>

using namespace std;

class Compilation{
    public:
        Compilation init();
        void compilationRenderer();
        void writeConfig(string compiler, vector<string> flags, string srcPath, string outputDir);
};