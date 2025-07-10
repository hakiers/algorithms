#include "partition.h"
#include <iostream>
using namespace std;

int main() {
    int n = 100000;

    // benchmark
    auto start = std::chrono::high_resolution_clock::now();
    long long res1 = p(n);
    auto end = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time: " << time1 << " ms\n";

    return 0;
}
