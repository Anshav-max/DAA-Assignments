#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int val;
    struct node* left;
    struct node* right;
}node;

node* createnode(int data){
    node* temp = new node();
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
}

node* insert_val(node*& root,int data){
    if(root == NULL){
        node* temp = createnode(data);
        return temp;
    }
    
    if(root->val > data){
        root->left = insert_val(root->left,data);
    }

    else root->right = insert_val(root->right,data);
    return root;
}

node* search(node* root,int data){
    if(root == NULL || root->val == data){
        return root;
    }

    if(root->val > data)return search(root->left,data);
    return search(root->right,data);
}

void inorder(node* root){
    if(root == NULL)return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

node* smallest(node* ptr){
    while(ptr->left != NULL){
        ptr = ptr->left;
    }
    return ptr;
}

node* delete_val(node*& root, int data){
    if(data < root->val){
        root->left = delete_val(root->left,data);
    }
    else if(data > root->val){
        root->right = delete_val(root->right,data);
    }
    else{
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        else{
            node* small = smallest(root->right);
            root->val = small->val;
            root->right = delete_val(root->right,small->val);
            return root;
        }
        return root;
    }
}
int main(){
    node* root = NULL;
    
    int n;
    cout<<"enter no of nodes:"<<endl;
    for(int i = 0 ; i < n;i++){
        int x;
        cin>>x;
        root = insert_val(root,x);
    }

    inorder(root);
    cout<<endl;

    node* temp = search(root,3);
    cout<<temp<<endl;

    int y;
    cout<<"enter the number to be deleted:"<<endl;
    cin>>y;

    root = delete_val(root,y);
    inorder(root);
    return 0;
}