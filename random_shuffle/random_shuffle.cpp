// random_shuffle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <array>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>


#include "random_shuffle.h"

int main()
{
    std::random_device rd;
    std::mt19937 rand_gen(rd());

    std::cout << "std::shuffle 0!\n";
    std::array<int, 10> a0 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::shuffle(a0.begin(), a0.end(), rand_gen);
    std::copy(a0.begin(), a0.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n\n";

    std::cout << "random shuffle 1!\n";
    std::array <int, 10> a1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    random_shuffle::v1::shuffle(a1.begin(), a1.end());
    std::copy(a1.begin(), a1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n\n";

    std::cout << "random shuffle 2!\n";
    std::array <int, 10> a2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    random_shuffle::v2::shuffle(a2.begin(), a2.end(), std::rand);
    std::copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n\n";

    std::cout << "random shuffle 3!\n";
    std::array <int, 10> a3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    random_shuffle::v3::shuffle(a3.begin(), a3.end(), rand_gen);
    std::copy(a3.begin(), a3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n\n";

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
