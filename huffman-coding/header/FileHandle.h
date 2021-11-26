#pragma once
#include <fstream>
#include <string>
#include "TreeNode.h"

using namespace std;

class FileHandle {
private:
    static void serialize(TreeNode *node, ofstream &outfile);
    static void deSerialize(TreeNode *&node, ifstream &infile);
public:
    /*for en/decoding*/
    static string StringReader(const string& fileName);

    /*for decoding*/
    static TreeNode* TreeReader(const string& fileName);

    /*for encoding*/
    static void StringWriter(const string& fileName, const string& data);

    /*for decoding*/
    static void TreeWriter(const string& fileName, TreeNode *root);
};

