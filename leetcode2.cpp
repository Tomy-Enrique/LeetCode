#include <iostream>
#include <stdlib.h> 
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3;
    l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = l1->next, *q = l2->next, *r = l3;
    int carry = 0;       //½øÎ»
    while (p != NULL && q != NULL) {
        struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->next = NULL;
        int sum = p->val + q->val + carry;
        if (sum >= 10) {
            sum = sum - 10;
            t->val = sum;
            carry = 1;
        }
        else {
            t->val = sum;
            carry = 0;
        }
        r->next = t;
        p = p->next;
        q = q->next;
        r = r->next;
    }
    while (p != NULL) {
        struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->next = NULL;
        int sum = p->val + carry;
        if (sum >= 10) {
            sum = sum - 10;
            t->val = sum;
            carry = 1;
        }
        else {
            t->val = sum;
            carry = 0;
        }
        r->next = t;
        p = p->next;
        r = r->next;
    }
    while (q != NULL) {
        struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->next = NULL;
        int sum = q->val + carry;
        if (sum >= 10) {
            sum = sum - 10;
            t->val = sum;
            carry = 1;
        }
        else {
            t->val = sum;
            carry = 0;
        }
        r->next = t;
        q = q->next;
        r = r->next;
    }
    if (carry == 1) {
        struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->next = NULL;
        int sum = carry;
        t->val = sum;
        r->next = t;
    }
    return l3;
}

struct ListNode* CreateList() {
    struct ListNode* L;
    L = (struct ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    return L;
}

void insert(struct ListNode* l, int k) {
    struct ListNode *p;
    p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    struct ListNode* t;
    t = (struct ListNode*)malloc(sizeof(struct ListNode));
    t->val = k;
    t->next = NULL;
    p->next = t;        
}

void Traverse(struct ListNode* l) {
    struct ListNode* p;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (l) {
        p = l->next;
    }
    while (p) {
        cout << p->val;
        p = p->next;
        if (p) {
            cout << "->";
        }
    }
    cout << endl;
}

int main() 
{
    struct ListNode *l1, *l2, *l3;
    l1 = CreateList();
    l2 = CreateList();
    insert(l1, 2);
    insert(l1, 4);
    insert(l1, 3);
    insert(l2, 5);
    insert(l2, 6);
    insert(l2, 4);
    // 2->4->3
    // 5->6->4    
    l3 = addTwoNumbers(l1, l2);
    Traverse(l1);
    Traverse(l2);
    Traverse(l3);
}
