#include "dictionary.h"

#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"

#include "random_string.h"
using namespace std;

int main(int argc, char** argv) {
    
    
    string buf;

    for (int j = 0; j < 5; j++) {
        Dictionary d;
        int size = pow(10, j);
        vector<string> keys;
        auto t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < size; i++) {
            buf = random_string(10);
            d.set(buf, random_string(10));
            keys.push_back(buf);
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration<double>(t2 - t1).count();
        std::cout << "-set- " << "N: " << size << ", time: " << time << std::endl;

        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < keys.size(); i++) {
            d.get(keys[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration<double>(t2 - t1).count();
        std::cout << "-get- " << "N: " << size << ", time: " << time << std::endl;
    }
    int result = Catch::Session().run(argc, argv);
    return result;
}