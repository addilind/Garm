#include <cstdio>
#include <stdexcept>

int main() {
    try {
        std::printf("Garm - built " __DATE__ " " __TIME__ "\n");

        return 0;
    }
    catch(std::exception ex) {
        std::fprintf(stderr, "\n! Uncaught exception:\n%s\n", ex.what());
        return -1;
    }
    catch(...) {
        std::fprintf(stderr, "\n! Uncaught non-std exception!\n");
        return -1;
    }
}