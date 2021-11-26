#include "header/FileHandle.h"

#include <queue>

string FileHandle::StringReader(const string& fileName) {
    string data;
    ifstream infile;

    infile.open(fileName.c_str(), ios::in);
    if (!infile.is_open())
        throw "file khong ton tai";

    infile >> data;
    infile.close();
    return data;
}

void FileHandle::StringWriter(const string& fileName, const string &data) {
    ofstream outfile;

    outfile.open(fileName.c_str(), ios::out);
    if (!outfile.is_open())
        throw "mo file khong thanh cong";

    outfile << data;
    outfile.close();
}

void FileHandle::TreeWriter(const string &fileName, TreeNode *root) {
    ofstream outfile;

    outfile.open(fileName.c_str(), ios::out);
    if (!outfile.is_open())
        throw "mo file khong thanh cong";

    serialize(root, outfile);
    outfile.close();
}

void FileHandle::serialize(TreeNode *root, ofstream &outfile) {
    TreeNode *node;
    queue<TreeNode *> q;

    // Level Order Traversal
    // using $ to mark nullptr
    q.push(root);
    while (!q.empty()) {
        node = q.front();
        q.pop();

        if (node == nullptr)
            outfile << "$ ";
        else {
            outfile << node->getEle() << node->getFreq() << " ";
            q.push(node->getLeft());
            q.push(node->getRight());
        }
    }
}

TreeNode* FileHandle::TreeReader(const string &fileName) {
    TreeNode *root = nullptr;
    ifstream infile;

    infile.open(fileName.c_str(), ios::in);
    if (!infile.is_open())
        throw "file khong ton tai";

    deSerialize(root, infile);
    infile.close();
    return root;
}

void FileHandle::deSerialize(TreeNode *&root, ifstream &infile) {
    char val;
    uint fre;
    TreeNode *node;
    queue<TreeNode*> q;

    //read the root node
    infile >> val;
    infile >> fre;
    root = new TreeNode(val, fre);

    // Level Order Traversal
    q.push(root);
    while (!q.empty()) {
        node = q.front();
        q.pop();

        infile >> val;
        if (val != '$') {
            infile >> fre;
            node->setLeft(new TreeNode(val,fre));
            q.push(node->getLeft());
        }

        infile >> val;
        if (val != '$') {
            infile >> fre;
            node->setRight(new TreeNode(val,fre));
            q.push(node->getRight());
        }
    }
}



