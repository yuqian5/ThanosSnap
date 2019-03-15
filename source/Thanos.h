#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <assert.h>

#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class Thanos {
    private:
        vector<char> *code; //where we held the code
        string fileName; // name of the file to be purged

        void loadFile(); // load file into code
        void rewriteFile(); // rewrites file base on code

    public:
        explicit Thanos(string file); // constructor
        ~Thanos(); // destructor

        void snapFinger(); // snap

};
