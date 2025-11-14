#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component_base.hpp>

#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>

using namespace ftxui;
using namespace std;

vector<int> parseHeap() {
    int fd = open("/tmp/tracerLogs.log", O_NONBLOCK | O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "[ERROR] Unable to open FIFO for heap parsing!\n");
        return {};
    }

    char buf[4096];
    int n = read(fd, buf, sizeof(buf) - 1);
    if (n <= 0) {
        close(fd);
        return {};
    }

    buf[n] = '\0';
    string data(buf);

    vector<int> result;

    close(fd);
    return result;
}

int main() {
    float frg = 0.0f;
    std::vector<int> heap_values = {1, 2, 3, 2, 1};

    auto graph_lambda = [&](int x, int width) {
        std::vector<int> out;
        out.reserve(width);

        if (heap_values.empty()) {
            for (int i = 0; i < width; i++) {
                out.push_back(0);
            }
            return out;
        }

        for (int i = 0; i < width; i++) {
            out.push_back(heap_values[i % heap_values.size()]);
        }
        return out;
    };

    auto nextBtn = Button("Next", [&] {});
    auto stopBtn = Button("Stop", [&] {});

    auto layout = Container::Vertical({
        stopBtn,
        nextBtn
    });

    auto renderer = Renderer(layout, [&] {
        auto fragmentation_element = gauge(frg);
        auto heapGraph_element = graph(graph_lambda);

        return vbox(
            text("SPECTRE") | bold | center,
            separator(),
            hbox(
                vbox(
                    text("Fragmentation:"),
                    fragmentation_element,
                    separator(),
                    text("Heap Graph:"),
                    heapGraph_element | flex
                ) | flex
            )
        );
    });

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(renderer);
    return 0;
}