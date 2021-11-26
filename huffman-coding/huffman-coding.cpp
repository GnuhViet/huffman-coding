#include <iostream>
#include "TreeNode.cpp"
#include "Menu.cpp"

using namespace std;

void inOrder(TreeNode *node) {
    if (node == nullptr)
        return;
    cout << node->getEle() << ": " << node->getFreq() << " ";
    inOrder(node->getLeft());
    inOrder(node->getRight());
}

int main() {
    string msg = "ABABBCBBDEEEABABBAEEDDCCABBBCDEEDCBCCCCDBBBCAAA";
    string res = "00110011110111111001011011010011001111001011011001000101001111110110010110110001110101010110011111101000000";

    Menu::primary();
}
