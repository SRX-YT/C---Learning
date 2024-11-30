#include <iostream>
#include <queue>

template<typename T>
void printQ(std::queue<T> q) {
    std::queue<T> g = q;
    while (!g.empty()) {
        std::cout << '\t' << g.front();
        g.pop();
    }
    std::cout << "\n";
}

int main() {
    std::queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);

    std::cout << "The queue gquiz is: ";
    printQ(gquiz);

    std::cout << "\ngquiz.size(): " << gquiz.size();
    std::cout << "\ngquiz.front(): " << gquiz.front();
    std::cout << "\ngquiz.back(): " << gquiz.back();

    std::cout << "\ngquiz.pop(): ";
    gquiz.pop();
    printQ(gquiz);

    return 0;
}