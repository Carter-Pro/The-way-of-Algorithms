#include <iostream>
#include "ListNode.cpp"
using namespace std;


class PartitionList {
public:
     ListNode* partition(ListNode* head, int x) {
          ListNode less(0);
          ListNode big(0);

          ListNode* p = head;
          ListNode* p1 = &less;
          ListNode* p2 = &big;
          while (p) {
               if (p->val < x) {
                    p1->next = p;
                    p1 = p;
               } else {
                    p2->next = p;
                    p2 = p;
               }

               p = p->next;
          }

          p1->next = big.next;
          // important!!!
          p2->next = nullptr;

          return less.next;
     }
};

int main(int argc, char *argv[])
{
     ListNode head(0);
     ListNode *p = &head;
     int value;
     while (cin >> value && value > 0) {
          p->next = new ListNode(value);
          p = p->next;
     }
     
     PartitionList test;
     p = test.partition(head.next, 4);

     while (p) {
          cout << p->val << " ";
          p = p->next;
     }
     cout << endl;
     return 0;
}
