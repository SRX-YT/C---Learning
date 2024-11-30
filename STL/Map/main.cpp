#include <iostream>
#include <map>
#include <string>

int main() {
    // Init
    std::map<std::string, int> m;

    // Inserting
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;

    // Traverse
    std::map<std::string, int>::iterator it = m.begin();
    while (it != m.end()) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << "\n";
        ++it;
    }

    // Size
    std::cout << "Size of map: " << m.size() << "\n";

    return 0;
}