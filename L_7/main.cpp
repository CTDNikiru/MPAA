#define CATCH_CONFIG_RUNNER

#include "../catch.hpp"

#include "bruteforce.h"
#include "sha256.h"
#include <iostream>
using namespace std;

std::string random_string(int size) {
    std::string result;
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    auto random_char = [&]() { return alphabet[rand() % alphabet.size()]; };
    std::generate_n(std::back_inserter(result), size, random_char);
    return result;
}

int main(int argc, char* argv[]) {

    
    for (int passSize = 1; passSize < 4; passSize++) {
        auto t1 = std::chrono::high_resolution_clock::now();
        int alphSize = passSize * 50;
        bruteforce(sha256(random_string(passSize)), random_string(alphSize), passSize);

        auto t2 = std::chrono::high_resolution_clock::now();

        double time = std::chrono::duration<double>(t2 - t1).count();
        cout << "password size: " << passSize << " alphabet size: " << alphSize << " time: " << time << "\n";
    }
    int result = Catch::Session().run(argc, argv);
    return result;
}