#include <iostream>

#include "ListNode.cpp"
using namespace std;

class DeleteDuplicatesList2 {
public:
     ListNode* deleteDuplicatesList(ListNode* head) {

          ListNode dummy(-1);
          dummy.next = head;

          ListNode *pPre = &dummy;
          ListNode *pCur = head;
          ListNode *pNext;
          bool bDup;

          while (pCur) {
               pNext = pCur->next;
               bDup = false;

               while (pNext && (pCur->val == pNext->val)) {
                    pPre->next = pNext;
                    delete pCur;
                    pCur = pNext;
                    pNext = pCur->next;
                    bDup = true;
               }

               if (bDup) {
                    pPre->next = pNext;
                    delete pCur;
               } else {
                    pPre = pCur;
               }
               
               pCur = pNext;
          }
          return dummy.next;
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

     DeleteDuplicatesList2 test;
     p = test.deleteDuplicatesList(head.next);

     while (p) {
           cout << p->val << "\n";
           p = p->next;
     }
     return 0;
}

