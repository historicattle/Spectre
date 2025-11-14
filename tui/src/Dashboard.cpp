// #include "Dashboard.h"

#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include <fcntl.h>
#include <fstream>
using namespace std;

void Dashboard::init(){

}

int main(){
    using namespace ftxui;

    int fd=open("/tmp/tracerLogs.log", O_NONBLOCK|O_RDONLY);
    // int fdTui=open("/tmp/compConfig.log",O_NONBLOCK|O_WRONLY);

    if(fd==-1){
        fprintf(stderr,"[ERROR] Failed to open the tracerLog FIFO!\n");
    }

    float frg;

    auto heapGraph = graph({

    });

    auto nextBtn=Button("Next", [&]{});
    auto stopBtn=Button("Stop",[&]{});

    auto fragmentation = gauge(frg);

    auto Layout=Container::Vertical({
        stopBtn,
        nextBtn
    });

    auto renderer = Renderer([&]{
        return vbox({
            text("SPECTRE"),
            separator(),
            hbox({
                // heapGraph->Render(),q
                vbox({
                    fragmentation->Render(),

                })
            })
        });
    });

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(renderer);
}

vector<int,int> parseHeap(){
    // Logs will be like: [ALLOC] <addr> <val>

    int fd=open("/tmp/tracerLogs.log", O_NONBLOCK|O_RDONLY);
    if (fd==-1)
    {
        fprintf(stderr,"[ERROR] Unbale to open FIFO for heap parsing!\n[SIG] Now exitting!\n");
    }
    
    string buffer;
    string line=getline(fd,buffer);
}