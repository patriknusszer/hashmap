// hashtest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <any>
#include "hashmap.h"
#include "debugmalloc.h"

using namespace std;

int main()
{
    hashmap hm = hashmap();
    hm["key"] = "value";
    hm["akatsuki"] = "naruto36";
    hm["key2"] = "value54";
    char const* s = any_cast<char const*>(hm["key2"]);
    hm["akatsuki3"] = "naruto345";
    hm["key3"] = "value65";
    s = any_cast<char const*>(hm["akatsuki"]);

    hm["akatsuki5"] = "naruto536";
    s = any_cast<char const*>(hm["key3"]);

    hm.del("key");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
