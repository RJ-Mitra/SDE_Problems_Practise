//Flatten a linkedlist containing multiple sorted linkedlists (output should be in sorted order)


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* down;

        Node(int val, Node* next=nullptr, Node* down = nullptr){
            this->val = val;
            this->next = next;
            this->down = down;
        }
};


//merge two flattened lists recursively
Node* merge(Node* head1, Node* head2){
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;
    Node* result = nullptr;
    if(head1->val < head2->val){
        result = head1;
        result->down = merge(head1->down, head2); //if head1 is less than head2, we store head1 in result and move head1 to the next (i.e. head1->down) and compare again
    }else{
        result = head2;
        result->down = merge(head1, head2->down); //if head2 is less than head1, we store head2 in result and move head2 to the next (i.e. head2->down) and compare again
    }
    result->next = nullptr; //nullterminate the list and return the node
    return result;
}

//flatten linkedlist
Node* flatten(Node* root){
    if(root==nullptr || root->next == nullptr) return root;
    return merge(root,flatten(root->next));
}

void push(Node** head, int val){
    Node* new_node = new Node(val);
    new_node->next = nullptr;
    new_node->down = (*head);
    (*head) = new_node;
}

void printNodes(Node* head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head=head->down;
    }
    cout<<endl;
}


int main(){

    //creating multilevel LL
    /*

    5 -> 10 -> 19 -> 28 
    |    |     |     | 
    V    V     V     V 
    7    20    22    35 
    |          |     | 
    V          V     V 
    8          50    40 
    |                | 
    V                V 
    30               45 

    */
    
    Node* root = nullptr;

    push( &root, 30 ); 
    push( &root, 8 ); 
    push( &root, 7 ); 
    push( &root, 5 ); 
  
    push( &( root->next ), 20 ); 
    push( &( root->next ), 10 ); 
  
    push( &( root->next->next ), 50 ); 
    push( &( root->next->next ), 22 ); 
    push( &( root->next->next ), 19 ); 
  
    push( &( root->next->next->next ), 45 ); 
    push( &( root->next->next->next ), 40 ); 
    push( &( root->next->next->next ), 35 ); 
    push( &( root->next->next->next ), 20 ); 

    Node* head = flatten(root);
    printNodes(head);
}