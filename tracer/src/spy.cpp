// compile with g++ -fPIC -shared -o spy.so spy.cpp -ldl
#define _GNU_SOURCE
#include <dlfcn.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static void* (*real_malloc)(size_t size) = nullptr;
static void (*real_free)(void* ptr) = nullptr;

static void* stackBase = (void*)0x7ffdf0000000;
static size_t maxStackSize=0;

extern "C" void* malloc(size_t size) {
    if (!real_malloc) {
        real_malloc = (void* (*)(size_t))dlsym(RTLD_NEXT, "malloc");
    }

    int stackPtrEstimate;
    void* currStackPtr = (void*)&stackPtrEstimate;
    size_t currentStackUsage = (size_t)((char*)stackBase - (char*)currStackPtr);
    if (currentStackUsage > maxStackSize) {
        maxStackSize = currentStackUsage;
        fprintf(stderr, "New max stack size: %zu bytes\n", maxStackSize);
    }

    void* ptr = real_malloc(size);
    fprintf(stderr, "malloc(%zu) = %p\n", size, ptr);
    return ptr;
}

extern "C" void free(void* ptr) {
    if (!real_free) {
        real_free = (void (*)(void*))dlsym(RTLD_NEXT, "free");
    }
    fprintf(stderr, "free(%p)\n", ptr);
    real_free(ptr);
}