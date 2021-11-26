#pragma once
#include <string>
#include "TreeNode.h"

using namespace std;

class DeCoding {
private:
    string deCoded;
public:
    DeCoding(const string &codedMsg, TreeNode *root);
    string getDeCodedString();
};

