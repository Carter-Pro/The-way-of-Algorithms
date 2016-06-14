#include <iostream>
#include <vector>
#include <random>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char *argv[])
{
     std::random_device rd;
     std::uniform_int_distribution<int> dis(0,100);
     vector<int> v;
     for (int i = 0; i < 10; i++)
          v.push_back(dis(rd));
     for (auto e : v)
          cout << e << " ";
     cout << endl;
     BinarySearchTree tree;
     for (auto e : v)
          tree.insert(e, e);
     tree.inorderTreeWalk();

     for (int i = 0; i < 5; i++)
          tree.Delete(v[i]);
     tree.inorderTreeWalk();
     return 0;
}
