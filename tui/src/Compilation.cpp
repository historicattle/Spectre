#include <vector>
#include <iostream>
#include <string>

#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>

int main() {
    using namespace ftxui;
    using namespace std;

    vector<string> compiler_options = { "G++", "GCC", "Clang", "Clang++" };
    int compiler_selected = 0;
    auto radiobutton = Radiobox(&compiler_options, &compiler_selected);

    bool Wall = false, Wpedantic = false, Wextra = false, Werror = false, O0 = false, march_native = false;
    auto checkboxes = Container::Vertical({
        Checkbox("-Wall", &Wall),
        Checkbox("-Wpedantic", &Wpedantic),
        Checkbox("-Wextra", &Wextra),
        Checkbox("-Werror", &Werror),
        Checkbox("-O0", &O0),
        Checkbox("-march=native", &march_native),
        });

    auto layout = Container::Horizontal({
        Container::Vertical({
            radiobutton,
        }),
        Container::Vertical({
            checkboxes,
        }),
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
            });
        });

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(renderer);
}
