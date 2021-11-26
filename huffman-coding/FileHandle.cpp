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

TreeNode* FileHandle::TreeReader(const string &fileName) {
    TreeNode *root = nullptr;
    ifstream infile;
    infile.open(fileName.c_str(), ios::in);
    deSerialize(root, infile);
    infile.close();
    return root;
}

void FileHandle::deSerialize(TreeNode *&root, ifstream &infile) {
    char val,space;
    uint fre;
    TreeNode *node;
    queue<TreeNode*> q;

    infile >> val;
    infile >> fre;
    //infile >> space;
    root = new TreeNode(val, fre);

    q.push(root);
    while (!q.empty()) {
        node = q.front();
        q.pop();

        infile >> val;
        if (val != '$') {
            infile >> fre;
            //infile >> space;
            node->setLeft(new TreeNode(val,fre));
            q.push(node->getLeft());
        }
            //infile >> space;

        infile >> val;
        if (val != '$') {
            infile >> fre;
            //infile >> space;
            node->setRight(new TreeNode(val,fre));
            q.push(node->getRight());
        } //else
            //infile >> space;
    }
}

void FileHandle::StringWriter(const string& fileName, const string &data) {
    ofstream outfile;
    outfile.open(fileName.c_str(), ios::trunc);
    if (!outfile.is_open())
        throw "file khong ton tai";
    outfile << data;
    outfile.close();
}

void FileHandle::TreeWriter(const string &fileName, TreeNode *root) {
    ofstream outfile;
    outfile.open(fileName.c_str(), ios::out);
    serialize(root, outfile);
    outfile.close();
}

void FileHandle::serialize(TreeNode *root, ofstream &outfile) {
    TreeNode *node = nullptr;
    queue<TreeNode *> q;
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


