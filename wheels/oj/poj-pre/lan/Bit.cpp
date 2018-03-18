//
// Created by martin on 17-12-16.
//
#include <bitset>
#include <iostream>
#include <climits>

int popcount(int n) {
    std::bitset<sizeof(int) * CHAR_BIT> b(n);
    return b.count();
}

int main() {
    std::cout << popcount(1000000);
}
