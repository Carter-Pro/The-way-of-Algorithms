struct binaryTreeNode
{
     int key;
     int value;
     binaryTreeNode *left;
     binaryTreeNode *right;
     binaryTreeNode *parent;
     binaryTreeNode(int key, int value): key(key), value(value), left(nullptr), right(nullptr), parent(nullptr) {};
};
