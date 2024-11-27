#include <stdio.h>
#include <iostream>
#include <string>

void do_operation(int a, int b, int (*f)(int, int));

int main() {
    [](){printf("Hello Lambda!\n");} ();

    auto test1 { [](){printf("Test1\n");} };
    test1();

    auto test2 { [](const std::string& text){printf("%s\n", text);} };
    test2("test2");

    [](const std::string& text){printf("%s\n", text);} ("test3");

    auto sum1 { [](int a, int b){return a + b;} };
    int result = sum1(2, 4);
    printf("%i\n", result);

    auto sum2 { [](int a, int b) -> double {return a + b;} };
    result = sum2(10, 6);
    printf("%i\n", result);

    auto minus{ [](int a, int b){return a - b;} };
    auto multiply{ [](int a, int b){return a * b;} };
    do_operation(10, 2, minus);
    do_operation(3, 5, multiply);

    do_operation(6, 2, [](int a, int b){return a / b;});

    auto add = [](auto a, auto b){return a + b;};
    printf("%i\n", add(1, 1));
    printf("%f\n", add(1.1, 1.1));
    std::string hello{"hello"};
    std::string world{"world"};
    printf("%s\n", add(hello, world));

    auto print = [](const auto& value){std::cout<<value<<"\n";};
    print("hello");
    print(2.2);
    print(2);
    print(&hello);

    return 0;
}

void do_operation(int a, int b, int (*f)(int, int)) {
    printf("%i\n", f(a, b));
}