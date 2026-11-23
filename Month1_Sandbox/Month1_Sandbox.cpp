#include"isEven.h"
#include <iostream>
#include<math.h>
#include<string_view>

//condition ? expression1 : expression2;
//!(x&& y) is equivalent to !x || !y
//!(x || y) is equivalent to !x && !y
//! 
//! Variables declared inside a namespace are also global variables.
//! Prefer defining global variables inside a namespace rather than in the global namespace.


int g_globalNumber{}; //global variable
double getGravity(); // taken from constants.cpp
double instantVelocity(int time, double gravity); //taken from constants.cpp

namespace Goo {

    int g_anotherGlobal{};

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

    std::cout << Foo::justFunction(5, 10)<<'\n';

    std::cout << instantVelocity(5, getGravity()) <<" instant velocity " << '\n';

    int apples{ 5 }; // local variable apples
    {
        std::cout << apples << '\n';//prints the main local variable apples
        int apples{ 10 };//defines a new apples which hides the local apples variable
        std::cout << apples << '\n';//prints the new apples variable
    }//inner apples is destroyed here

    std::cout << apples << '\n';//prints the local variable apples value

    int firstNum{};
    int largerNum{};
    int tempStore{};
    std::cout << "Enter a number: ";
    std::cin >> firstNum;
    std::cout << "Enter a larger number: ";
    std::cin >> largerNum;

    if (largerNum < Goo::g_anotherGlobal) {
        tempStore = largerNum;
        largerNum = firstNum;
        firstNum = tempStore;
        std::cout << "Swaping the values" << '\n';
        std::cout << "The smaller value is " << firstNum << '\n';
        std::cout << "The larger value is " << largerNum << '\n';
    }
   
   std::cout << "The smaller value is " << firstNum << '\n';
   std::cout << "The larger value is " << largerNum << '\n';
 

    return 0;
}