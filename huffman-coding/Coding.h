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
    map<char, string> res;
    static void addTable(map<char, string>& mp, TreeNode* node, string str);
public:
    Coding(map<char, uint> table);
    ~Coding();
    void addTable();
    map<char, string> getTable();
};
