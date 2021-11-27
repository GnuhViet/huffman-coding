#include "header/TreeNode.h"

TreeNode::TreeNode()
{
    left = right = nullptr;
}

TreeNode::TreeNode(char ele, uint fre)
{
    this->element = ele;
    this->freq = fre;
    left = right = nullptr;
}

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}

char TreeNode::getEle()
{
    return element;
}

uint TreeNode::getFreq()
{
    return freq;
}

void TreeNode::setLeft(TreeNode* left)
{
    this->left = left;
}

TreeNode* TreeNode::getLeft()
{
    return left;
}

void TreeNode::setRight(TreeNode* right)
{
    this->right = right;
}

TreeNode* TreeNode::getRight()
{
    return right;
}

bool TreeNode::isLeaf() {
    return left == nullptr && right == nullptr;
}
