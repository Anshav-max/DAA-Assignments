#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}TreeNode;

TreeNode* createnode(int val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
}

void preorder(TreeNode* root){
    stack<TreeNode*>st;
    st.push(root);  //------> 1

    while(!st.empty()){  //-----> n (no of nodes)
        TreeNode* temp = st.top();  // ----> 1
        st.pop();  // -------------> 1
        if(temp->right != NULL)st.push(temp->right); // ----> 1
        if(temp->left != NULL)st.push(temp->left); // ----> 1
        cout<<temp->val<<" ";  //----> 1
    }
    cout<<endl;  //----> 1
}

void postorder(TreeNode* root){
    stack<TreeNode*>st;
    st.push(root);  // -----> 1
    vector<int>ans;
    while(!st.empty()){ // ------> n
        TreeNode* temp = st.top(); // -----> 1
        st.pop();  // -------> 1
        if(temp->left != NULL)st.push(temp->left);  //------> 1
        if(temp->right != NULL)st.push(temp->right);  // -------> 1
        ans.push_back(temp->val);  // -----> n
    }
    reverse(ans.begin(),ans.end());  //-------> n/2
    for(int i : ans)cout<<i<<" "; // ------> n
    cout<<endl;  // -------> 1
}

void inorder(TreeNode* root){
    stack<TreeNode*>st;
    TreeNode* curr = root; // ----> 1
    while(!st.empty() || curr != NULL){ // ----- n
        if(curr == NULL){
            TreeNode* temp = st.top(); // -----> 1
            cout<<temp->val<<" ";  // -----> 1
            curr = temp->right;  // -----> 1
            st.pop();  // -----> 1
        }
        else{
            st.push(curr); // -----> 1
            curr = curr->left; // -----> 1
        }
    }
    cout<<endl; //----> 1
}

int main(){
    TreeNode* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->left = createnode(6);
    root->right->right = createnode(7);
    /*
             (1)
            /   \
           (2)  (3)
          / \   /  \
        (4) (5) (6) (7)
    */
   cout<<"Preorder Traversal :"<<endl;
   preorder(root);
   cout<<"Step count F(n) = O(n)"<<endl<<endl;
   
   cout<<"Postorder Traversal :"<<endl;
   postorder(root);
   cout<<"Step count F(n) = O(n)"<<endl<<endl;
   
   cout<<"Inorder Traversal :"<<endl;
   inorder(root);
   cout<<"Step count F(n) = O(n)"<<endl;
    return 0;
}