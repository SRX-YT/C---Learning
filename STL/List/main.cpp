#include <iostream>
#include <list>

/*
    Method for printing list items
    Support multiple types by template
    For traversing can use also for(int i = 0; i < l.size(); i++);
*/
template<typename T>
void printL(std::list<T> l) {
    for (T item : l) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

int main() {
    // Init
    std::list<char> l1{'h', 'e', 'l', 'l', 'o'};
    std::list<char> l2{'w', 'o', 'r', 'l', 'd'};

    // Accessing
    std::cout << l1.front() << "\n";
    std::cout << l1.back() << "\n";

    // Size
    std::cout << l1.size() << "\n";
    std::cout << l1.empty() << "\n";
    l1.resize(10, 'a');

    // Changing
    l1.assign(4, 'a');
    l1.swap(l2);

    // Adding
    l2.push_back('o');
    l2.push_front('w');
    auto iter1 = l2.cbegin();
    l2.insert(iter1, 'i');

    // Removing
    l1.clear();
    l2.pop_back();
    l2.pop_front();
    l2.erase(iter1);

    // Printing
    printL(l1);
    printL(l2);

    return 0;
}