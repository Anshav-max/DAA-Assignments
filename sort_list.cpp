#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node* next;
}ListNode;

ListNode* createnode(int data){
    ListNode* temp = new ListNode();
    temp->val = data;
    temp->next = NULL;
    return temp;
}

ListNode* partition(ListNode*& p , ListNode*& r){
    ListNode* ptr = p;
    ListNode* temp = p;
    while(temp != r){
        if(temp->val <= r->val){
            swap(temp->val,ptr->val);
            ptr = ptr->next;
        }
        temp = temp->next;
    }
    swap(ptr->val,r->val);
    return ptr;
}

 void qs( ListNode*& p, ListNode*& r){
    if(p == NULL || p == r)return;


    ListNode* q = partition(p,r);
    ListNode* temp = p;

    if (q != p) {

        while (temp->next != q)
            temp = temp->next;

        qs(p, temp);
    }

    if(temp != p)qs(p,temp);

    if(q->next != NULL && q != r)qs(q->next,r);
    
}


ListNode* quick_sort(ListNode*& head){

    if(head == NULL || head->next == NULL)return head;

    ListNode* p = head;
    ListNode* r = head;

    while(r->next != NULL){
        r = r->next;
    }
    qs(p,r);
    return head;
}


int main(){
    ListNode* head = createnode(3);
    head->next = createnode(4);
    head->next->next = createnode(5);
    head->next->next->next = createnode(2);
    head->next->next->next->next = createnode(3);
    head->next->next->next->next->next = createnode(1);

    
    ListNode* temp = head;
    cout<<"BEFORE:";
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"AFTER:";
    head = quick_sort(head);
    temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }

    return 0;
}