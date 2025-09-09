#include<vector>
#include<iostream>
#include<string>

#include<ftxui/screen/screen.hpp>
#include<ftxui/dom/elements.hpp>
#include<ftxui/component/component.hpp>
#include<ftxui/component/component_options.hpp>
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include<ftxui/dom/elements.hpp>

int main() {
	using namespace ftxui;
	using namespace std;

	vector<string> compilerChoice = { "G++","GCC","Clang","Clang++"};
	int compilerChoice = 0;

	vector<string> flagChoice = { "-Wall","-Wpeadntic","-Wextra","-Werror","-O0","-march=native" };
	bool Wall, Wpeadntic, Wextra, Werror, O0, march_native ;
	Wall = Wpeadntic = Wextra = Werror = O0 = march_native = false;

	auto radiobutton = Radiobox(&compilerChoice, &compilerChoice);
	auto checkbox = Checkbox(&flagChoice, &Wall, &Wpeadntic, &Wextra, &Werror, &O0, &march_native);

	auto layout = Container::Vertical({
		Container::Horizontal({Renderer[]{return text("SPECTRE") | bol | center}}),
		Conatiner::Horizontal({
			Container::Vertical({
				radiobutton,
				}) | border,
			Container::Vertical({checkbox}) | border,
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
					checkbox->Render(),
					}) | border,
				}),
			});
		});

	auto screen = ScreenInteractive::Fullscreen();
	screen.Loop(renderer);
}