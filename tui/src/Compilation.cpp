#include "Compilation.h"

#include <vector>
#include <iostream>
#include <string>

#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

void Compilation::compilationRenderer() {
    using namespace ftxui;

    mkfifo ("/tmp/compConfig.log", 0666);
    int fd = open("/tmp/compConfig.log", O_NONBLOCK|O_WRONLY);
    if(fd!=-1){
        write(fd,"[INFO] Welcome to Spectre!\n",28);
        write(fd,"[INFO] Compilation Config FIFO Created\n",40);
    }

    string srcPath;
    string outputDir;
    vector<string> compilerOptions = { "G++", "GCC", "Clang", "Clang++" };
    vector<string> compileFlags;
    int nextFlag=0;
    int compiler_selected = 0;
    auto radiobutton = Radiobox(&compilerOptions, &compiler_selected);
    auto src=Input(&srcPath,"Enter the full path of the src file");
    auto out = Input(&outputDir, "Enter output directory path");

    bool Wall = false, Wpedantic = false, Wextra = false, Werror = false, O0 = false, march_native = false;

    auto nextBtn=Button("Next",[&]{
        if(Wall) compileFlags.push_back("-Wall");
        if(Wpedantic) compileFlags.push_back("-Wpedantic");
        if(Wextra) compileFlags.push_back("-Wextra");
        if(Werror) compileFlags.push_back("-Werror");
        if(O0) compileFlags.push_back("-O0");
        if(march_native) compileFlags.push_back("-march=native");

        string compiler = compilerOptions[compiler_selected];

        std::string buffer;
        buffer += "COMPILER=" + compiler + "\n";
        buffer += "FLAGS=";
        for (int i = 0; i < compileFlags.size(); ++i) {
            buffer += compileFlags[i];
        }
        buffer += "\n";
        buffer += "SOURCE=" + srcPath + "\n";
        buffer += "OUTPUT=" + outputDir + "\n";

        write(fd, buffer.c_str(), buffer.size());
    });

    auto checkboxes = Container::Vertical({
        Checkbox("-Wall", &Wall),
        Checkbox("-Wpedantic", &Wpedantic),
        Checkbox("-Wextra", &Wextra),
        Checkbox("-Werror", &Werror),
        Checkbox("-O0", &O0),
        Checkbox("-march=native", &march_native),
    });

    auto layout = Container::Vertical({
        Container::Horizontal({
            radiobutton,
            checkboxes,
        }),
        src,
        nextBtn
    });


    auto renderer = Renderer(layout, [&] {
        return vbox({
            text("SPECTRE") | bold | center,
            hbox({
                vbox({
                    text("Compiler Choice:"),
                    radiobutton->Render(),
                }) | border,
                vbox({
                    text("Flags:"),
                    checkboxes->Render(),
                }) | border,
            }),
            separator(),
            hbox({
                hbox({
                    text("Source: "),
                    src->Render()
                }),
                hbox({
                    text("Output Dir: "),
                    out->Render()
                }),
            }),
            nextBtn->Render()
        });
    });

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(renderer);
}

void Compilation::writeConfig(string compiler, vector<string> flags, string srcPath, string outputDir=""){
    FILE* fp;
    fp=fopen("../config/Compilation.txt","w");

    if(fp){
        fprintf(fp,"COMPILER=%s\n",compiler.c_str());
        for(string flag : flags) {
            fprintf(fp,"FLAGS=%s\n",flag.c_str());
        }
        fprintf(fp,"SOURCE=%s\n",srcPath.c_str());
        fprintf(fp,"OUTPUT=%s\n",outputDir.c_str());
    }
    fclose(fp);
}

int main(){
    Compilation C;
    C.compilationRenderer();
}