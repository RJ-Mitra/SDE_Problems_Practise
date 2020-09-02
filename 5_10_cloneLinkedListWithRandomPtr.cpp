//Copy a LinkedList with next nodes and random nodes
//The linkedlist has next nodes as well as random

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* random;

        Node(int val, Node* next=nullptr, Node* random=nullptr){
            this->val = val;
            this->next = next;
            this->random = random;
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

        Node* findNodeByVal(int val){
            Node* curr = head;
            while(curr!=nullptr){
                if(curr->val == val) return curr;
                curr=curr->next;
            }
            return nullptr;
        }

        //clone LinkedList
        LinkedList clone(){
            Node* curr = head;
            Node* temp = nullptr;
            while(curr!=nullptr){ //Inserts copy of node 1 between nodes 1 and 2 and so on...
                temp = curr->next; //stores next node of curr for linking later
                curr->next = this->getNewNode(curr->val); //inserts new cloned node to the right of old node
                curr->next->next = temp; //links new cloned node to next original node
                curr=temp; //sets curr to next original node
            }
            curr = head; //moves curr back to head node
            while(curr!=nullptr){ //setting the random pointers of cloned nodes
                if(curr->next!=nullptr){ //if next of curr node is nullptr, it is the last node
                    if(curr->random!=nullptr) curr->next->random = curr->random->next;
                    else curr->next->random = curr->random;
                }
                if(curr->next!=nullptr){
                    curr=curr->next->next;
                }else{
                    curr = curr->next;
                }
            }
            curr=head;
            Node* cloned = head->next;
            LinkedList l;
            l.head = cloned; //setting first cloned node as head of new linked list
            while(curr!=nullptr && cloned!=nullptr){ //Extracting cloned nodes
                curr->next = (curr->next!=nullptr) ? curr->next->next : curr->next;
                cloned->next = (cloned->next!=nullptr) ? cloned->next->next : cloned->next;
                curr=curr->next;
                cloned=cloned->next;
            }
            return l;
        }
};

int main(){
    LinkedList l1;
    l1.insertVal(1);
    l1.insertVal(2);
    l1.insertVal(3);
    l1.insertVal(4);
    l1.insertVal(5);
    
    l1.head->random = l1.findNodeByVal(3); //1 to 3
    l1.head->next->random = l1.findNodeByVal(1); //2 to 1
    l1.head->next->next->random = l1.findNodeByVal(5); //3 to 5
    l1.head->next->next->next->random = l1.findNodeByVal(5); //4 to 5
    l1.head->next->next->next->next->random = l1.findNodeByVal(2); //5 to 2


    cout << "Original list : \n"; 
    l1.printList(); 

    LinkedList l2 = l1.clone();

    cout << "\nCloned list : \n"; 
    l2.printList();
}