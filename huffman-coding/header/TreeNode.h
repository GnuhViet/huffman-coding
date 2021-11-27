#pragma once
typedef unsigned int uint;
class TreeNode {
private:
	char element;
	uint freq;	//Frequency
	TreeNode *left;
	TreeNode *right;
public:
	TreeNode();
	TreeNode(char ele, uint fre);
	~TreeNode();
	char getEle();
	uint getFreq();
	void setLeft(TreeNode *left);
	TreeNode* getLeft();
	void setRight(TreeNode *right);
	TreeNode* getRight();
	bool isLeaf();
};

