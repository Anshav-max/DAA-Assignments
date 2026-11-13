#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node* next;
}ListNode;

ListNode* createnode(int data){
    ListNode* temp = new ListNode;
    temp->val = data;
    temp->next = NULL;
}
// MERGING TWO LIST:
ListNode* merge(ListNode*& headA , ListNode* &headB){
    ListNode* temp = headA;
    if(headA == NULL){
        return headB;
    }

    while(headB != NULL){
        

        while(temp->next != NULL && temp->next->val <= headB->val){
            temp = temp->next;
        }
        if(temp->val > headB->val){
            ListNode* temp2 = createnode(headB->val);
            headB = headB->next;
            temp2->next = headA;
            headA = temp2;
            temp = headA;
        }

        else{
            ListNode* temp2 = headB;
            headB = headB->next;
            temp2->next = temp->next;
            temp->next = temp2;
            temp = temp->next;
        }
    }
    return headA;
}


ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if(n == 0)return NULL;
    if(n == 1)return lists[0];
    ListNode* headA = lists[0];

    for(int i = 1 ; i < n;i++){
        ListNode* headB = lists[i];
        headA = merge(headA, headB);
    }
    return headA;
}


int main(){
    
    return 0;
}