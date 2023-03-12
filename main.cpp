#include "sorting.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> vecs;


void reset(std::vector<int>& vec, int mode)
{
    vec.clear();
    if(mode == 0)
    {
        vec.resize(100);
        for(int i = 0; i < 100; ++i)
            vec[i] = rand();
    }
    else if(mode == 1)
    {
        vec.resize(1000);
        for(int i = 0; i < 1000; ++i)
            vec[i] = rand();
    }
    else if(mode == 2)
    {
        vec.resize(5000);
        for(int i = 0; i < 5000; ++i)
            vec[i] = rand();
        std::sort(vec.begin(), vec.end(), std::greater<int>{});
    }
    else
    {
        vec.resize(10000);
        for(int i = 0; i < 10000; ++i)
            vec[i] = rand();
    }
}
void reset_all()
{
    reset(vecs[0], 0);
    reset(vecs[1], 1);
    reset(vecs[2], 2);
    reset(vecs[3], 3);
}

int main()
{
    srand(time(0));
    vecs.resize(4);
    reset_all();
    uint16_t nvec = 0;
    std::cout << "Selection sort\n";
    for(auto& vec : vecs)
    {
        auto begin = std::chrono::high_resolution_clock::now();
        kq::selection_sort(vec.data(), vec.data() + vec.size());
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << nvec++ << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << " us ";
        std::cout << kq::is_sorted(vec.data(), vec.data() + vec.size()) << "\n";
    }
    reset_all();
    nvec = 0;
    std::cout << "Bubble sort\n"; 
    for(auto& vec : vecs)
    {
        auto begin = std::chrono::high_resolution_clock::now();
        kq::bubble_sort(vec.data(), vec.data() + vec.size());
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << nvec++ << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << " us ";
        std::cout << kq::is_sorted(vec.data(), vec.data() + vec.size()) << "\n";
    }
    reset_all();
    nvec = 0;
    std::cout << "Quick sort\n";
    for(auto& vec : vecs)
    {
        auto begin = std::chrono::high_resolution_clock::now();
        kq::quick_sort(vec.data(), vec.data() + vec.size());
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << nvec++ << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << " us ";
        std::cout << kq::is_sorted(vec.data(), vec.data() + vec.size()) << "\n";
    }
    reset_all();
    nvec = 0;
    std::cout << "Merge sort\n";
    for(auto& vec : vecs)
    {
        auto begin = std::chrono::high_resolution_clock::now();
        kq::merge_sort(vec.data(), vec.data() + vec.size());
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << nvec++ << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << " us ";
        std::cout << kq::is_sorted(vec.data(), vec.data() + vec.size()) << "\n";
    }
    reset_all();
    nvec = 0;
    std::cout << "Something sort\n";
    for(auto& vec : vecs)
    {
        auto begin = std::chrono::high_resolution_clock::now();
        //kq::random_sort(vec.data(), vec.data() + vec.size());
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << nvec++ << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << " us ";
        std::cout << kq::is_sorted(vec.data(), vec.data() + vec.size()) << "\n";
    }

    std::vector<int> random = { 5, 4, 3, 2, 1, 6, 7 };
    auto begin = std::chrono::high_resolution_clock::now();
    kq::random_sort(random.data(), random.data() + random.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << nvec++ << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << " us ";
    std::cout << kq::is_sorted(random.data(), random.data() + random.size()) << "\n";
    
    return 0;
}