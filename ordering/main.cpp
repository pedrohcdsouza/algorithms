#include "ordenacao.hpp"
#include <iostream>

int main() {
    int a[5] = {5, 3, 2, 4, 9};
    merge_sort(a, 0, 4);

    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
