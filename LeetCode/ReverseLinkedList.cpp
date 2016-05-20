#include <iostream>
#include "ListNode.cpp"
using namespace std;

class ReverseLinkedList {
public:
     ListNode* reverseLinkedList(ListNode* head, int m, int n) {
          ListNode* Head = new ListNode(0);
          Head->next = head;
          ListNode* start = Head;
          int i;
          for (i = 0; i < m-1; i++) {
               start = start->next;
          }

          ListNode* p1 = start->next;
          ListNode* p2 = p1->next;

          for ( ; i < n-1; i++) {
               p1->next = p2->next;
               p2->next = start->next;
               start->next = p2;

               p2 = p1->next;
          }

          return Head;
     }
};

int main(int argc, char *argv[])
{
     ListNode* head = new ListNode(0);
     ListNode* p = head;
     int i;
     for (i = 1; i <=5; i++) {
          ListNode* current = new ListNode(i);
          p->next = current;
          p = current;
     }
     ReverseLinkedList test;
     p = test.reverseLinkedList(head->next, 2, 4)->next;
     while (p) {
          cout << p->val << "\n";
          p = p->next;
     }
     return 0;
}

