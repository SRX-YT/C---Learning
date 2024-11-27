#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> names{"Tom", "Sam", "Bob", "Tim", "Sandra", "Alice"};
    std::cout << "Names: ";
    for (auto name : names) {
        std::cout << name << "\t";
    }
    std::cout << "\n";

    auto count { [names](char letter) -> int {
        int res = 0;
        for (std::string name : names) {
            if (letter == name[0]) {
                res++;
            }
        }
        return res;
    } };

    std::cout << count('T');
    return 0;
}