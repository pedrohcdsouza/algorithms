#include "ordenacao.cpp"
#include <iostream>

int main() {
    int a[10] = {2,8,5,7,3,6,4,9,1,10};
    std::cout << ordenado(a, 10);
    merge_sort(a, 0, 10);
    std::cout << ordenado(a, 10);

    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << " ";
    }

    return 0;
}
