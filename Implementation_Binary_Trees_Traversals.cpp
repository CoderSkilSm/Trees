#include<bits/stdc++.h> 

using namespace std; 

class node{
    public: 
       int data; 
       node* left;
       node* right; 
    node(int d){
       this -> data = d; 
       this -> left = NULL; 
       this -> right = NULL; 
    }
};

node* buildTree(node* root){
      cout << "Enter the data " << " ";
      int data; 
      cin >> data ;
      root = new node(data); 

      if(data == -1){
        return NULL; 
      }

      cout<<"Enter the data for inserting in left of "  << data << endl;
      root -> left = buildTree(root -> left); 
      cout<<"Enter the data for inserting in right of " << data << endl; 
      root -> right = buildTree(root -> right); 
      return root;  
}

void levelordertraversal(node* root){
    queue<node*>q; 
    q.push(root); 
    q.push(NULL); 
    while(!q.empty()){
        node* temp = q.front(); 
        q.pop(); 
        
        if(temp == NULL){
            cout<<endl; 
            if(!q.empty()){
                q.push(NULL); 
            }
        }
        else{
          cout<<temp -> data <<" "; 
        if(temp -> left){
            q.push(temp -> left); 
        }
        
        if(temp -> right){
            q.push(temp -> right); 
        }
        }
    }
}
void preordertraversal(node* root){
    if(root == NULL){
        return; 
    }

    cout << root -> data << " "; 
    preordertraversal(root -> left); 
    preordertraversal(root -> right); 
}

void postordertraversal(node* root){
    if(root == NULL){
        return; 
    }

    postordertraversal(root -> left); 
    postordertraversal(root -> right); 
    cout << root -> data << " "; 
}


void inordertraversal(node* root){
    if(root == NULL){
        return; 
    }
    inordertraversal(root -> left); 
    cout << root -> data <<" "; 
    inordertraversal(root -> right); 
}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }


int main(void){
    node* root = NULL; 
    //root = buildTree(root); 
   // cout<<"Printing the level order traversal " << endl;
    // levelordertraversal(root); 
    // cout<<endl;
    // cout<<"Preorder traversal is: " << endl; 
    // preordertraversal(root); 
    // cout<<endl;
    // cout << "PostOrder traversal is: " << endl; 
    // postordertraversal(root);
    // cout<<endl;  
    // cout << "Inorder traversal is: " << endl; 
    // inordertraversal(root); 
    // cout<<endl;

    buildFromLevelOrder(root);
    cout<<"The level order traversal is: " <<endl; 
    levelordertraversal(root); 
    // cout<<endl;
    return 0; 
}
