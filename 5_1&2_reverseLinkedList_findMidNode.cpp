#include<bits/stdc++.h>
using namespace std;

//Reverse a linked list

class Node{
    public:
        int val;
        Node* next;

        Node(int val, Node* node=nullptr):val{val},next{node}{}
};

Node* getNewNode(int val, Node* next = nullptr){
    Node* node = new Node(val,next);
    return node;
}

void printAllNodes(Node* head){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* curr = head;
    while(curr!=nullptr){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}


//Reverse LL

//Iterative method
Node* reverseLinkedListIter(Node* head){
    Node* curr = head;
    Node* temp = nullptr;
    Node* prev = nullptr;
    while(curr->next!=nullptr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr=temp;
    }
    head = curr;
    curr->next = prev;
    return head;
}

//Recursive method
Node* recurHead = nullptr;
Node* reverseLinkedListRecursive(Node* curr){
    if(curr == nullptr) return nullptr;
    if(curr->next==nullptr){
        recurHead = curr;
        return curr;
    }
    Node* prev = reverseLinkedListRecursive(curr->next);
    prev->next = curr;
    curr->next = nullptr;
    return curr;
}

//Approach 1: Using two pointers and moving one pointer each time the counter is odd
Node* getMiddleNodeOddPointer(Node* head){
    Node* mid = head;
    Node* curr = head;
    int count = 0;
    while(curr!=nullptr){
        count++;
        if(count&1){
            mid=mid->next;
        }
        curr=curr->next;
    }
    return mid;
}

//Approach 2: Using two pointers and moving one pointer for every 2 movements of the other pointer
Node* getMiddleNodeTwoPointer(Node* head){
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    if(head!=nullptr){
        while(slow_ptr!=nullptr && fast_ptr!=nullptr){
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
        }
    }
    return slow_ptr;
}

int main(){
    Node* head = getNewNode(0);
    head->next = getNewNode(1);
    head->next->next = getNewNode(2);
    head->next->next->next = getNewNode(3);
    head->next->next->next->next = getNewNode(4);
    head->next->next->next->next->next = getNewNode(5);
    
    
    printAllNodes(head);
    //Reverse LL
    Node* newHead = reverseLinkedListIter(head);
    printAllNodes(newHead);
    reverseLinkedListRecursive(newHead);
    printAllNodes(recurHead);
    
    Node* midPtrOdd = getMiddleNodeOddPointer(recurHead);
    cout<<midPtrOdd->val<<endl;
    
    Node* mid2ptr = getMiddleNodeTwoPointer(recurHead);
    cout<<mid2ptr->val<<endl;
}