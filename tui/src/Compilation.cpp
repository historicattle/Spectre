#include <vector>
#include <iostream>
#include <string>

#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace std;

void writeConfig(string compiler, vector<string> flags, string srcPath, string outputDir);

int main() {
    using namespace ftxui;

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

        writeConfig(compiler,compileFlags,srcPath,outputDir);
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

void writeConfig(string compiler, vector<string> flags, string srcPath, string outputDir=""){
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