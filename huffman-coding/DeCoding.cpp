#include "header/DeCoding.h"

DeCoding::DeCoding(const string &codedMsg, TreeNode *root) {
    deCoded = "";
    TreeNode *current = root;
    for (char x : codedMsg) {
        if (x == '0')
            current = current->getLeft();
        else
            current = current->getRight();

        if (current->isLeaf()) {
            deCoded += current->getEle();
            current = root;
        }
    }
}

string DeCoding::getDeCodedString() {
    return deCoded;
}
