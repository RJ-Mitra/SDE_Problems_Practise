//Reverse linked list in groups of k

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

        //reverse LL in groups
        Node* reverseLLGroups(Node* head, int k){
            Node* curr = head;
            Node* prev = nullptr;
            Node* next = nullptr;
            int count = 0;
            while(curr!=nullptr && count<k){
                next = curr->next;
                curr->next = prev;
                curr=next;
                count++;
            }
            if(next!=nullptr){
                head->next = reverseLLGroups(next,k);
            }
            return prev;
        }
};