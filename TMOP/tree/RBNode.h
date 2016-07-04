#ifndef RBNODE_H
#define RBNODE_H

#define RED 0
#define BLACK 1
struct RBNode
{
     int key;
     int color;
     RBNode *left;
     RBNode *right;
     RBNode *parent;
     RBNode(int key): key(key), color(RED), left(nullptr), right(nullptr), parent(nullptr) {};
};

#endif /* RBNODE_H */

