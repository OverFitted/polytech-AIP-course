#include <cstring>
#include <iostream>

#include "String.h"

void sort(String** arr, size_t size);
String* find_max(String** arr, size_t size);

int main() {
    auto** arr = new String*[200];
    char symb;
    int size;

    try {
        std::cout << "Enter array size:\n";
        std::cin >> size;
        if (std::cin.peek() == '.' || std::cin.peek() == ',' || std::cin.fail()) {
            throw std::runtime_error("size input failure");
        }
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return -1;
    }

    for (int i = 0; i < size; i++) {
        std::cout << "Enter new string: ";
        auto* str = new String();
        std::cin >> *str;
        arr[i] = str;
    }

    std::cout << std::endl;

    std::cout << "Enter symbol to search for\n";
    std::cin >> symb;
    std::cout << "Searching for " << symb << "..." << std::endl;

    for (int i = 0; i < size; i++) {
        if (arr[i]->rfind(symb) != -1) {
            std::cout << "Found " << symb << " on (index) " << arr[i]->rfind(symb) << " in " << *arr[i] << std::endl;
        }
    }

    std::cout << std::endl;

    std::cout << "Sorting array..." << std::endl;

    sort(arr, size);

    std::cout << "Sorted array is:\n" << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << *arr[i] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Biggest string is: " << *find_max(arr, size);
}

void sort(String** arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            if (arr[j - 1]->compare(*arr[j]) > 0) {
                String* temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

String* find_max(String** arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            if (arr[j - 1]->get_len() < arr[j]->get_len()) {
                String* temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr[size - 1];
}
