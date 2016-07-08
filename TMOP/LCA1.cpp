#include <iostream>
#include <vector>
#include <random>
#include "tree/BinarySearchTree.h"

using namespace std;

int main(int argc, char *argv[])
{
     std::random_device rd;
     std::uniform_int_distribution<int> dis(0, 100);
     vector<int> v;
     for (int i = 0; i < 10; i++)
          v.push_back(dis(rd));

     BinarySearchTree tree;

     return 0;
}
