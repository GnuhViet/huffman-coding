#pragma once
#include "TreeNode.h"

#include <vector>
#include <map>
#include <queue>
#include <string>

typedef unsigned int uint;

using namespace std;

class Coding {
private:
    TreeNode* root;
    string coded;
    map<char, string> res;

private:    
    map<char, uint> buildTable(const string &msg);
    void addResTable();
    static void addResTable(map<char, string>& mp, TreeNode* node, string str);
    
public:
    Coding(const string &msg);
    ~Coding();
    string getCodedString();
};
