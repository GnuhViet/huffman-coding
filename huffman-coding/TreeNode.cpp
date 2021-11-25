#include "TreeNode.h"

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

void TreeNode::setEle(char ele)
{
    this->element = ele;
}

char TreeNode::getEle()
{
    return element;
}

void TreeNode::setFreq(uint fre)
{
    this->freq = fre;
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

bool TreeNode::hasLeft()
{
    return left != nullptr;
}

bool TreeNode::hasRight()
{
    return right != nullptr;
}
