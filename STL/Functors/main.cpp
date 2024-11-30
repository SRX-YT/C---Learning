#include <bits/stdc++.h>
#include <iostream>

int increment(int x) { return (x+1); }

class incrementExample {
private:
    int num;
public:
    incrementExample(int n) : num(n) {}

    int operator()(int arr_num) const {
        return num + arr_num;
    }
};

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    std::transform(arr1, arr1+n1, arr1, increment);

    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int to_add = 5;

    std::transform(arr2, arr2+n2, arr2, incrementExample(to_add));

    for (int i = 0; i<n1; i++) {
        std::cout<<arr1[i]<<" ";
    }

    std::cout<<"\n";

    for (int i = 0; i<n2; i++) {
        std::cout<<arr2[i]<<" ";
    }

    return 0;
}