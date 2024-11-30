#include <iostream>
#include <vector>

/*
    Method for printing vector items
    Support multiple types by template
    For traversing can use also for(int i = 0; i < v.size(); i++);
*/
template<typename T>
void printV(std::vector<T> v) {
    for (T item : v) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

int main() {
    // Init vectors
    std::vector<int> v1{};
    std::vector<int> v2(5, 1);
    std::vector<int> v3{1, 2, 3, 4, 5};

    // Accessing elements in vector
    std::cout << v3[2] << "\n";
    std::cout << v3.at(1) << "\n";

    // Updating elements in vector
    v3[2] = 800;
    v3.at(1) = 900;

    // Inserting elements in vector
    /*
        Push back takes O(1)
        Insert takes O(n)
    */
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(4);
    v1.insert(v1.begin(), 0);

    // Deleting elements in vector
    v2.pop_back();
    v2.erase(v2.begin(), v2.end() - 2);

    // Printing vectors
    printV(v1);
    printV(v2);
    printV(v3);

    return 0;
}