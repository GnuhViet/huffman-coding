#include <iostream>
#include "header/DeCoding.h"
#include "header/EnCoding.h"
#include "header/FileHandle.h"

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

    EnCoding test1(msg);
    DeCoding test2(test1.getCodedString(), test1.getRoot());


    cout << "bang ma: "<< endl;
    map<char, string> table = test1.getTable();
    for (auto & it : table)
        cout << it.first << ": " << it.second << endl;
    cout << "coded msg: " << test1.getCodedString() << endl;
    cout << "encoded msg: " << test2.getDeCodedString() << endl;

    if (test1.getCodedString() == res)
        cout << "encode dung" << endl;

    if (msg == test2.getDeCodedString())
        cout << "decode dung" << endl;


    FileHandle::StringWriter("resource/output.txt", res);
    cout << "chuoi tu file: " << FileHandle::StringReader("resource/output.txt");

    FileHandle::TreeWriter("resource/tree.dat", test1.getRoot());
    TreeNode *testRoot = FileHandle::TreeReader("resource/tree.dat");

    cout << "\nroot tu file:         ";inOrder(testRoot);
    cout << "\nroot tu chuong trinh: "; inOrder(test1.getRoot());
}
