#include"isEven.h"
#include <iostream>
#include<math.h>
#include<string_view>

//condition ? expression1 : expression2;
//!(x&& y) is equivalent to !x || !y
//!(x || y) is equivalent to !x && !y

namespace Goo {
    int justFunction(int a, int b) {
        return a - b;
    }
}

std::string_view getQuantityPhrase(int num)
{
    if (num < 0)
        return "negative";
    if (num == 0)
        return "no";
    if (num == 1)
        return "a single";
    if (num == 2)
        return "a couple of";
    if (num == 3)
        return "a few";
    return "many";
}

 std::string getApplesPluralized(int number) {
     std::string expr{};
     number == 1 ? (expr = "apple") : (expr = "apples");
        
    return expr;
}

int main()
{
    // for longer nested namespaces : namespace Active = Foo;
    constexpr int maryApples{ 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    std::cout << Foo::justFunction(5, 10);

    return 0;
}