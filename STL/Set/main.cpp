#include <iostream>
#include <set>

template<typename T>
void printS(std::set<T> s) {
    for (auto item : s) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

template<typename T>
void printS(std::set<T, std::greater<T>> s) {
    for (auto item : s) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

int main() {
    // Init
    std::set<int> set1{};
    std::set<int> set2{6, 10, 5, 1};
    // Descending order
    std::set<int, std::greater<int>> set3{6, 10, 5, 1};

    // Adding elements
    set1.insert(40);
    set2.insert(40);
    set3.insert(40);
    set1.insert(40);
    set2.insert(40);
    set3.insert(40);

    // Assigning
    std::set<int> set4(set2.begin(), set2.end());

    // Removing
    set2.erase(set2.begin(), set2.find(10));
    set3.erase(10);

    printS(set1);
    printS(set2);
    printS(set3);
    printS(set4);

    return 0;
}