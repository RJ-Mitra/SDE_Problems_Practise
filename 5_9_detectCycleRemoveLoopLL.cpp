//Detect a cycle and remove loop from LinkedList

//Approaches
//1. Hashmap: Use hashmap to store locations of traversed nodes. If a node is getting repeated, it has a cycle
//2. Visited flag: Modify node to have a visited flag. Change flag to true for all visited nodes. If any node is found as visited, it is a cycle
//3. Visited node with temporary LL: Create a temporary node and point all visited elements to this node. If any element is found that is already pointing to temp node, it is a loop
//4. Floyd's cycle finding algo: Use two pointers to traverse the list. Slow ptr moves by 1 node, Fast pointer moves by 2. If they meet at the same node, the list has a cycle


//Using Floyd's cycle finding algorithm

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

        Node* findLastNode(){
            Node* curr = head;
            while(curr->next!=nullptr){
                curr=curr->next;
            }
            return curr;
        }

        //detect cycle in LL using Floyd's cycle detection
        bool isCyclicLL(){
            Node* slow_ptr = head;
            Node* fast_ptr = head;
            while(slow_ptr!=nullptr && fast_ptr!=nullptr&&fast_ptr->next!=nullptr){
                slow_ptr=slow_ptr->next;
                fast_ptr=fast_ptr->next->next;
                if(slow_ptr==fast_ptr) return true;
            }
            return false;
        }

        //finding cycle using a set
        Node* findCycle(){
            unordered_set<Node*> s;
            Node* curr = head;
            Node* prev = nullptr;
            while(curr!=nullptr){
                if(s.find(curr)!=s.end()){
                    return prev;
                }
                s.insert(curr);
                prev=curr;
                curr=curr->next;
            }
            return nullptr;
        }

        //remove cycle by using the set
        void removeCycle(){
            Node* curr = head;
            Node* lastNode = this->findCycle();
            if(lastNode!=nullptr){
                lastNode->next = nullptr;
            }
        }
};


int main(){
    LinkedList l;
    l.insertFront(0);
    l.insertFront(1);
    l.insertFront(2);
    l.insertFront(3);
    l.insertFront(4);
    l.insertFront(5);
    
    Node* last = l.findLastNode();
    last->next = l.head;
    // l.printList();
    cout<<l.isCyclicLL()<<endl;
    l.removeCycle();
    cout<<l.isCyclicLL()<<endl;
}