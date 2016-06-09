#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {};
};

void print(ListNode* head) {
    if (head->next == nullptr)
        return;
    ListNode *p = head->next;
    while (p) {
        if (p->next == nullptr) {
            cout << p->val << endl;
        } else {
            cout << p->val << "->" ;
        }
        p = p->next;
    }
}
ListNode* initList() {
    int value = 0;
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    while (cin >> value) {
        if (value == -1)
            break;
        ListNode *newNode = new ListNode(value);
        p->next = newNode;
        p = p->next;
    }
    return head;
}

void reverse(ListNode* head) {
    if (head->next == nullptr) {
        return;
    }
    ListNode *last = head->next;
    ListNode *p = last;
    ListNode *next = p->next;
    
    while (next) {
        head->next = next;
        last->next = next->next;
        next->next = p;
        p = head->next;
        next = last->next;
    }
}

bool isPalindrome(ListNode *head) {
    if (head->next == nullptr) {
        return true;
    }
    // find mid
    ListNode *begin = head;
    ListNode *end = head;
    while (end->next != nullptr) {
        end++;
    }
    ListNode *slow = begin;
    ListNode *fast = begin;
    ListNode *mid;
    
    while (fast != nullptr && fast->next != nullptr) {
        
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow;
    // reverse listnode
    reverse(mid);
    

    
    auto front = begin->next;
    auto behind = mid->next;

    while(behind) {
        if (front->val != behind->val)
            break;

        front++;
        behind++;
    }
    if (front >= mid)
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    ListNode *head = initList();
    if (isPalindrome(head))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    return 0;
}
