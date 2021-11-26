#pragma once
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class Menu {
private:
    static void choice1();
    static void choice2();
    static void pause();
    static string getPath();
public:
    static void primary();
};

