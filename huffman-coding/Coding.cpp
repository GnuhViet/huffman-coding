#include "Coding.h"

map<char, uint> Coding::buildTable(const string &msg) {
     
}

void Coding::addResTable() {
    addResTable(res, root, "");
}

void Coding::addResTable(map<char, string>& mp, TreeNode* node, string str) {
    if (node == nullptr)
        return;
    if (node->getEle() != '$')
        mp.insert(pair<char, string>(node->getEle(), str));
    addResTable(mp, node->getLeft(),  str + "0");
    addResTable(mp, node->getRight(), str + "1");
}

Coding::Coding(const string &msg)
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

    for (auto it = countTable.begin(); it != countTable.end(); ++it)
        minHeap.push(new TreeNode(it->first, it->second));
     
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        root = new TreeNode('$', left->getFreq() + right->getFreq());

        root->setLeft(left);
        root->setRight(right);

        minHeap.push(root);
    }
    addResTable();
}

Coding::~Coding() {
    delete root;
}

string Coding::getCodedString()
{
    return string();
}
