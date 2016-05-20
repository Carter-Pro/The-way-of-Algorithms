
#include <iostream>

using namespace std;

struct ListNode
{
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(nullptr) { }
};

class DeleteDuplicatesList1 {
public:
     // delete the later duplicate element
     ListNode* deleteDuplicatesList1(ListNode* head) {

          //attention to null point
          if (head == nullptr) {
               return head;
          }
          ListNode* p1 = head;
          ListNode* p2 = p1->next;

          while (p2) {
               if (p1->val == p2->val) {
                    p1->next = p2->next;
                    delete(p2);
               } else {
                    p1 = p1->next;
               }
               p2 = p1->next;
          }
          return head;
     }

     // delete the pervious duplicate element
     ListNode* deleteDuplicatesList2(ListNode* head) {
          ListNode dummy(-1);
          dummy.next = head;

          ListNode *pPre = &dummy;
          ListNode *pCur = head;
          ListNode *pNext;

          while (pCur) {
               pNext = pCur->next;
               while (pNext && (pCur->val == pNext->val)) {
                    pPre->next = pNext;
                    delete pCur;
                    pCur = pNext;
                    pNext = pCur->next;
               }

               pPre = pCur;
               pCur = pNext;
          }
          return dummy.next;
     }
};

int main(int argc, char *argv[])
{
     ListNode* l = new ListNode(0);

     ListNode* p;

     p = l;
     p->next = new ListNode(1);
     p = p->next;
     p->next = new ListNode(1);
     p = p->next;
     p->next = new ListNode(2);
     p = p->next;
     p->next = new ListNode(3);
     p = p->next;
     p->next = new ListNode(3);
     p = p->next;
     DeleteDuplicatesList1 test;
     p = test.deleteDuplicatesList2(l->next);

     while (p) {
          cout << p->val << "\n";
          p = p->next;
     }
     return 0;
}

