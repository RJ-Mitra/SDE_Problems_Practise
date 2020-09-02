//Rotate linkedlist from from a given position k

//E.g. 1 2 3 4 5 and k = 3. Output 4 5 1 2 3
//Approach: Get the kth node. Get the first node after k. Get the last node of the list.
//Null terminate kth node (setting it as the last node). set k+1th node as head. set next of last node as old head.


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val, Node* next=nullptr){
            this->val = val;
            this->next = next;
        }
};

class LinkedList{
    public:
        Node* head;
        int size;
        
        LinkedList(){
            head=nullptr;
            size=0;
        }

        Node* getNewNode(int val, Node* next = nullptr){
            Node* node = new Node(val,next);
            return node;
        }

        ~LinkedList(){
            delete head;
        }
        
        
        void insertFront(int val){
            if(head==nullptr){
                head = getNewNode(val);
                size++;
                return;
            }
            Node* curr = getNewNode(val);
            curr->next = head;
            head = curr;
            size++;
        }
        
        void insertVal(int val){
            if(head==nullptr){
                head = getNewNode(val);
                size++;
                return;
            }
            Node* curr = head;
            while(curr->next!=nullptr){
                curr=curr->next;
            }
            curr->next = getNewNode(val);
            size++;
            return;
        }

        void deleteNode(int val){
            if(head==nullptr) return;
            Node* curr = head;
            Node* prev = nullptr;
            while(curr->next!=nullptr || curr->val!=val){
                prev = curr;
                curr=curr->next;
            }
            if(curr->val == val){
                prev->next = curr->next;
                delete curr;
                curr=nullptr;
            }
            return;
        }

        int getSize(){
            if(head==nullptr) return 0;
            Node* curr = head;
            int count = 0;
            while(curr!=nullptr){
                curr=curr->next;
                count++;
            }
            return count;
        }

        void printList(){
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

        void rotate(int k){
            if(k>=size) return; //if k is greater than or equal to list size, no use of rotation
            Node* curr = head;
            Node* kthNode = nullptr; //to store the kth node (which will become the last node of the list post rotation)
            Node* kPlus1Node = nullptr; //to hold k+1th node (which will become the first node of the list post rotation)
            int count = 1; //counter starts from one since we are not using 0 based counting
            while(curr!=nullptr && count<k){
                curr=curr->next;
                count++;
            }
            kthNode = curr; //we get kth node
            kPlus1Node = curr->next; //we get k+1 node
            while(curr->next!=nullptr) curr=curr->next; //we continue with curr till we get the last node
            curr->next = head; //set next of last node as the old head node
            head = kPlus1Node; //set k+1 node as new head node
            kthNode->next = nullptr; //null terminate list with kthnode which is the new last node
        }
};

int main(){
    LinkedList l1;
    l1.insertVal(10);
    l1.insertVal(20);
    l1.insertVal(30);
    l1.insertVal(40);
    l1.insertVal(50);
    l1.insertVal(60);
    l1.insertVal(70);
    l1.insertVal(80);

    int k = 5;

    cout<<"Before rotation: \n";
    l1.printList();

    l1.rotate(k);

    cout<<"\n\nAfter rotation: \n";
    l1.printList();
}