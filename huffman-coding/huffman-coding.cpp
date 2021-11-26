#include <iostream>
#include "header/TreeNode.h"
#include "header/Coding.h"

using namespace std;

int main() {

    Coding test1("ABABBCBBDEEEABABBAEEDDCCABBBCDEEDCBCCCCDBBBCAAA");

    string res = "00110011110111111001011011010011001111001011011001000101001111110110010110110001110101010110011111101000000";

    if (test1.getCodedString() == res)
        cout << "dung" << endl;
    else
        cout << "sai" << endl;

    map<char, string> table = test1.getTable();
    for (auto & it : table)
        cout << it.first << ": " << it.second << endl;
}
