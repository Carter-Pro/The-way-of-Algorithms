// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <iostream>
#include <math.h>
#include "ListNode.cpp"

class Intersection
{
public:
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          int m = calcLength(headA);
          int n = calcLength(headB);
          int x;
          ListNode *a;
          ListNode *b;

          if (m > n) {
               a = headA;
               b = headB;
               x = m - n;
          } else {
               a = headB;
               b = headA;
               x = n - m;
          }

          for ( ; x > 0; --x)
               a = a->next;

          while (a) {
               if (a == b) {
                    return a;
               }
               a = a->next;
               b = b->next;
          }

          return nullptr;

     }

     int calcLength(ListNode *head) {
          int len = 0;
          ListNode *p = head;
          while (p) {
               ++len;
               p = p->next;
          }
          return len;
     }
};
