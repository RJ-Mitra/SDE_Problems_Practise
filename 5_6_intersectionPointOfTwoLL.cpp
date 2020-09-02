//Find intersection point of two LL

//Approaches:

//1. Brute force: Use two loops to check each node with all nodes in the other list. O(n^2)
//2. Mark visited nodes: Have a visited flag for each node in LL. Mark as visited when traversing one LL. While traversing other LL, return the first visited node. O(m+n) but extra space is needed.
//3. Hasing: Store the location of all visited nodes in a hashmap during traversals. If a location is already in the map, it is the intersecting node
//4. Count diff of nodes: Since the list will have same number of nodes after intersection, we take count diff of nodes. We bring the larger list at the same count as the beginning of the smaller list. Then we traverse through both lists and check if both nodes have same address



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

        //Find intersection node between current list and another list (return nullptr if no intersection)
        Node* findIntersectionNodeCounting(LinkedList l){
            int l1_size = size;
            int l2_size = l.getSize();
            int len_diff = 0;
            Node* longList_head;
            Node* shortList_head;
            if(l1_size > l2_size){
                longList_head = head;
                shortList_head = l.head;
                len_diff = l1_size - l2_size;
            }else{
                longList_head = l.head;
                shortList_head = head;
                len_diff = l2_size - l1_size;
            }
            for(int i=0;i<len_diff;++i){ //normalise the length of the larger list with the smaller one
                if(longList_head==nullptr) return nullptr;
                longList_head=longList_head->next;
            }
            while(longList_head!=nullptr && shortList_head!=nullptr){ //traverse both lists and compare
                if(longList_head == shortList_head) return longList_head; //return node if match is found
                longList_head=longList_head->next;
                shortList_head=shortList_head->next;
            }
            return nullptr; //return nullptr if no matches
        }


        Node* getNodeAddress(int val){
            Node* curr = head;
            while(curr!=nullptr){
                if(curr->val == val) return curr;
                curr=curr->next;
            }
            return nullptr;
        }

        Node* setNext(Node* node, int val){
            node=node->next;
            node->val = val;
            return node;
        }
        
        
        void insertFront(int val){
            if(head==nullptr){
                head->val = val;
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
                size--;
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
};


int main(){
    LinkedList l1;
    l1.insertVal(1);
    l1.insertVal(2);
    l1.insertVal(3);
    l1.insertVal(4);
    l1.insertVal(5);
    l1.insertVal(6);

    LinkedList l2;
    l2.insertVal(7);
    l2.insertVal(8);
    Node* common = l1.getNodeAddress(4);
    cout<<"Test intersection node: "<<common<<endl;
    Node* l2_common_node = l2.getNodeAddress(8);
    l2_common_node->next = common;

    cout<<"List 1: "<<endl;
    l1.printList();
    cout<<"List 2: "<<endl;
    l2.printList();
    Node* res_intersectionNode = l1.findIntersectionNodeCounting(l2);
    cout<<"Res intersection node: "<<res_intersectionNode<<endl;
}