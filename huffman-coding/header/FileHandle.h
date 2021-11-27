#pragma once
#include <fstream>
#include <string>
#include "TreeNode.h"

using namespace std;

class FileHandle {
private:
    /*serialize binary tree using Level Order Traversal method*/
    static void serialize(TreeNode *node, ofstream &outfile);

    /*serialize binary tree using Level Order Traversal method*/
    static void deSerialize(TreeNode *&node, ifstream &infile);

public:
    /*write a string to file*/
    static void StringWriter(const string &fileName, const string &data);

    /*write a tree to file*/
    static void TreeWriter(const string &fileName, TreeNode *root);

    /*read a string from file*/
    static string StringReader(const string &fileName);

    /*read a tree from file*/
    static TreeNode* TreeReader(const string &fileName);
};

