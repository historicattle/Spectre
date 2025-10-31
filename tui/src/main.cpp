#include<Compilation.h>

#include <ftxui/component/component.hpp>
#include <sys/stat.h>
#include <fcntl.h>

using namespace ftxui;

int main(){
    Compilation C;

    auto stack=Container::Stacked({
        
    });
}

void commSetup(){
    mkfifo("/tmp/tracerLogs.log",0666);
    mkfifo("/tmp/compConfig.log",0666);

    // open("/tmp/tracerLogs.log", O_NONBLOCK|O_RDONLY);
    // open("/tmp/compConfig.log",O_NONBLOCK|O_WRONLY);
}