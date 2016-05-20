#include <iostream>
#include <string>
#include "ListNode.cpp"
using namespace std;

class AddTwoNumbers {
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode* head = new ListNode(0);
          ListNode* p = head;
          ListNode* p1 = l1;
          ListNode* p2 = l2;

          int val;
          int sum;
          int flag = 0;

          while (p1 && p2) {
               sum = p1->val + p2->val + flag;
               val = sum % 10;
               flag = sum / 10;
               ListNode *current = new ListNode(val);
               p->next = current;
               p = current;

               p1 = p1->next;
               p2 = p2->next;
          }

          ListNode* n = p1 ? p1 : p2;

          while (n) {
               sum = n->val + flag;
               val = sum % 10;
               flag = sum / 10;
               ListNode *current = new ListNode(val);
               p->next = current;
               p = current;
               n = n->next;
          }

          if (flag != 0) {
               p->next = new ListNode(flag);
          }
          return head->next;
     }
};

int main(int argc, char *argv[])
{
     ListNode* l1 = new ListNode(0);
     ListNode* l2 = new ListNode(0);

     ListNode* p;

     p = l1;
     p->next = new ListNode(2);
     p = p->next;
     p->next = new ListNode(4);
     p = p->next;
     p->next = new ListNode(3);


     p = l2;
     p->next = new ListNode(5);
     p = p->next;
     p->next = new ListNode(6);
     p = p->next;
     p->next = new ListNode(4);

     AddTwoNumbers test;
     p = test.addTwoNumbers(l1->next, l2->next);

     while (p) {
          cout << p->val << "\n";
          p = p->next;
     }
     return 0;
}


