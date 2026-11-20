#include<iostream>
#include"isEven.h"

namespace Foo {
    int justFunction(int a, int b) {
        return a + b;
    }
}

constexpr bool isEven(int number) {
	return number % 2 == 0;
}