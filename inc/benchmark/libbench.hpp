#ifndef LIBBENCH_HPP
#define LIBBENCH_HPP

#include <iostream>
#include <ctime>

namespace bench {

    class Benchmark {

        public:
            // Constructor:
            Benchmark();

            // Destructor:
            ~Benchmark();

            // Procedur section:
            void cpu_time_start();
            void cpu_time_stop();

            void print_cpu_time();


        private:
            std::clock_t cpuTimeStart;
            std::clock_t cpuTimeEnd;
    };
}

#endif 