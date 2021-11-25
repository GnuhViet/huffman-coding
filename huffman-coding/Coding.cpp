#include "Coding.h"

void Coding::addTable() {
    addTable(res, root, "");
}

void Coding::addTable(map<char, string>& mp, TreeNode* node, string str) {
    if (node == nullptr)
        return;
    if (node->getEle() != '$')
        mp.insert(pair<char, string>(node->getEle(), str));
    addTable(mp, node->getLeft(),  str + "0");
    addTable(mp, node->getRight(), str + "1");
}

Coding::Coding(map<char, uint> table)
{
    struct compare {
        bool operator()(TreeNode* l, TreeNode* r)
        {
            return (l->getFreq() > r->getFreq());
        }
    };

    TreeNode *left, *right;
    priority_queue<TreeNode*, vector<TreeNode*>, compare> minHeap;

    for (auto it = table.begin(); it != table.end(); ++it)
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
    addTable();
}

Coding::~Coding() {
    delete root;
}

map<char, string> Coding::getTable() {
    return res;
}
