#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "ordenacao.cpp"

int main() {
    std::ifstream file("testes/caso01/exemplo-30000-1.txt");

    if (!file.is_open()) {
        std::cerr << "Error to open file." << std::endl;
        return 1;
    }

    int size;
    file >> size;

    std::vector<int> array(size);

    for (int i = 0; i < size; ++i) {
        file >> array[i];
    }

    file.close();

    auto start = std::chrono::high_resolution_clock::now();

    insercao(array.data(), size);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}