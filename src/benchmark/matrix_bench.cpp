#include <iostream>
#include "benchmark/libbench.hpp"
#include "matrix/matrix.hpp"

using namespace std;
using namespace mtrx;
using namespace bench;

int main() {

    Benchmark myBench;

    Matrix A(100,100);
    Matrix B(100,100);

    myBench.cpu_time_start();

    A = A * B;

    myBench.cpu_time_stop();
    myBench.print_cpu_time();
}

