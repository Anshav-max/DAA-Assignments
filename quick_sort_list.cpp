#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int val;
    Node* prev;
    Node* next;
} Node;

Node* createNode(int data) {
    Node* temp = new Node();

    temp->val = data;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

Node* partition(Node* p, Node* r) {

    int pivot = r->val;

    Node* ptr = p;

    for (Node* temp = p; temp != r; temp = temp->next) {

        if (temp->val <= pivot) {

            swap(temp->val, ptr->val);

            ptr = ptr->next;
        }
    }

    swap(ptr->val, r->val);

    return ptr;
}

void qs(Node* p, Node* r) {

    if (p == NULL || r == NULL || p == r)
        return;

    Node* q = partition(p, r);


    if (q != p) {
        qs(p, q->prev);
    }

    if (q != r) {
        qs(q->next, r);
    }
}


void quickSort(Node* head) {

    if (head == NULL || head->next == NULL)
        return;

    Node* tail = head;

    while (tail->next != NULL)
        tail = tail->next;

    qs(head, tail);
}

void printForward(Node* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    Node* head = createNode(3);

    head->next = createNode(4);
    head->next->prev = head;

    head->next->next = createNode(5);
    head->next->next->prev = head->next;

    head->next->next->next = createNode(2);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = createNode(3);
    head->next->next->next->next->prev =
        head->next->next->next;

    head->next->next->next->next->next = createNode(1);
    head->next->next->next->next->next->prev =
        head->next->next->next->next;


    cout << "Before sorting: ";
    printForward(head);

    quickSort(head);

    cout << "After sorting: ";
    printForward(head);

    return 0;
}