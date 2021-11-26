#pragma once
typedef unsigned int uint;
class TreeNode {
private:
	char element{};
	uint freq{};	//Frequency
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode();
	TreeNode(char ele, uint fre);
	~TreeNode();
	void setEle(char ele);
	char getEle();
	void setFreq(uint fre);
	uint getFreq();
	void setLeft(TreeNode* left);
	TreeNode* getLeft();
	void setRight(TreeNode* right);
	TreeNode* getRight();
	bool isLeaf();
};

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

bool TreeNode::isLeaf() {
    return left == nullptr && right == nullptr;
}
