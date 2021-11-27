#include "header/EnCoding.h"

map<char, uint> EnCoding::buildTable(const string &msg) {
     map<char, uint> mp;

     char *check = new char[msg.length()];
     check[0] = msg[0];
     int n = 1; // length of check array

     for (int i = 1; i < msg.length(); i++) {
         int count = 0;
         for (int j = 0; j < n; j++) {
             if (msg[i] == check[j])
                 count++;
         }
         if (count == 0) {
             check[n] = msg[i];
             mp.insert(pair<char, uint>(check[n], 0));
             n++;
         }
     }

     delete[] check;

     for (char x : msg)
         mp[x] ++;

     return mp;
}

void EnCoding::addResTable() {
    addResTable(res, root, "");
}

void EnCoding::addResTable(map<char, string> &mp, TreeNode *node, const string &str) {
    if (node == nullptr)
        return;
    if (node->getEle() != '#')
        mp.insert(pair<char, string>(node->getEle(), str));
    addResTable(mp, node->getLeft(),  str + "0");
    addResTable(mp, node->getRight(), str + "1");
}

EnCoding::EnCoding(const string &msg)
{
    map<char, uint> countTable;
    countTable = buildTable(msg);

    struct compare {
        bool operator()(TreeNode* l, TreeNode* r)
        {
            return (l->getFreq() > r->getFreq());
        }
    };

    TreeNode *left, *right;
    priority_queue<TreeNode*, vector<TreeNode*>, compare> minHeap;

    for (auto & it : countTable)
        minHeap.push(new TreeNode(it.first, it.second));
     
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        root = new TreeNode('#', left->getFreq() + right->getFreq());

        root->setLeft(left);
        root->setRight(right);

        minHeap.push(root);
    }
    addResTable();

    coded = "";
    for (char x : msg)
        coded += res[x];
}

EnCoding::~EnCoding() {
    delete root;
}

string EnCoding::getCodedString() {
    return coded;
}

TreeNode* EnCoding::getRoot() {
    return root;
}

map<char, string> EnCoding::getTable() {
    return res;
}
