#include <iostream>
#include <stdlib.h> 
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* CreateList(int k) {
    struct ListNode* L;
    L = (struct ListNode*)malloc(sizeof(ListNode));
    L->val = k;
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
    p = l;
    while (p) {
        cout << p->val;
        p = p->next;
        if (p) {
            cout << "->";
        }
    }
    cout << endl;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* q;
    q = head;
    if(q && q->next){
        while (k--)
        {
            int len = 2;
            q = head;
            while (q->next->next)
            {
                q = q->next;
                len++;
            }
            struct ListNode* temp = q->next;
            q->next = NULL;
            temp->next = head;
            head = temp;  
            if(k > len){
                k = k % len; 
            }
        }
        
    }
    return head;
}

int main() 
{
    struct ListNode *l1, *l2, *l3;
    l1 = CreateList(1);
    insert(l1, 2);
    insert(l1, 3);
    insert(l1, 4);
    insert(l1, 5);
    l1 = rotateRight(l1, 2);
    Traverse(l1);
}
           