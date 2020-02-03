#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
}; 

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* prev = prehead; 
    // struct ListNode *p, *q;
    // p = l1;
    // q = l2;
    if(l1 && l2){
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val){
            prev->next = l1;
            l1 = l1->next;
        }else{
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }    
    prev->next = l1 == NULL ? l2 : l1; 
    return prehead;
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
    insert(l1, 3);
    insert(l1, 5);
    insert(l2, 4);
    insert(l2, 6);
    insert(l2, 7);
    // 2->4->3
    // 5->6->4 
    //cout << l1->val << " " << l2->val << endl;   
    Traverse(l1);
    Traverse(l2);
    l3 = mergeTwoLists(l1, l2);
    Traverse(l3);
}