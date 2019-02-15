#include <iostream>
#include <ctime>
#include "benchmark/libbench.hpp"

using namespace std;
using namespace bench;

// Constructor:
Benchmark::
Benchmark() {}

// Destructor:
Benchmark::
~Benchmark() {}

// Procedur section:
void Benchmark::
cpu_time_start() {
    this -> cpuTimeStart = clock();
}

void Benchmark::
cpu_time_stop() {
    this -> cpuTimeEnd = clock();
}

void Benchmark::
print_cpu_time() {
    cout << 
    "CPU time: " <<
    (cpuTimeEnd - cpuTimeStart) / (double) CLOCKS_PER_SEC <<
    " seconds " << 
    endl;
}








