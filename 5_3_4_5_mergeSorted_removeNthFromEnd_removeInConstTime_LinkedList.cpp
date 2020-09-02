//5_3_Merge two sorted linked lists
//5_4_Remove nth Node from LL end
//5_5_Remove given LL node in O(1) time

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

        void findNthValueFromEnd(int n){
            int count = n;
            Node* head_node = head;
            if(head_node == nullptr){
                cout<<"Head node is empty"<<endl;
                return;
            }
            if(size<n){
                cout<<"List size is smaller than pos of required element"<<endl;
                return;
            }
            Node* fastNode = head_node;
            Node* slowNode = head_node;
            while(count>0){
                fastNode=fastNode->next;
                count--;
            }
            while(fastNode!=nullptr){
                fastNode=fastNode->next;
                slowNode=slowNode->next;
            }
            cout<<"Node at nth pos from end: "<<slowNode<<"\n";
            cout<<"Value of node: "<<slowNode->val<<endl;
            return;
        }

        //Remove a given node in O(1) time
        void removeNode(Node* node){
            Node* next_node = node->next; //Copy value of next_node into current node and delete the next node
            if(next_node!=nullptr){ //if next node is not a nullptr (i.e. curr node is not the last node in the list)
                node->val = next_node->val;
                node->next = next_node->next;
                delete next_node;
                next_node = nullptr;
                size--;
            }else{ //if curr node is the last node in the list, just delete the curr node
                delete node;
                node = nullptr;
                size--;
            }
        }

        //Remove nth value from the end
        void removeNthValueFromEnd(int n){
            int count = n;
            Node* head_node = head;
            Node* prev = nullptr;
            if(head_node == nullptr){
                cout<<"Head node is empty"<<endl;
                return;
            }
            if(size<n){
                cout<<"List size is smaller than pos of required element"<<endl;
                return;
            }
            Node* fastNode = head_node; //Use two pointer - fast and slow
            Node* slowNode = head_node;
            while(count>0){
                fastNode=fastNode->next; //1st move 1st pointer ahead of slow by n so that when fast pointer reaches end of list, slow pointer will be at the nth pos from end
                count--;
            }
            while(fastNode!=nullptr){
                fastNode=fastNode->next;
                prev=slowNode;
                slowNode=slowNode->next;
            }
            prev->next = slowNode->next;
            delete slowNode;
            slowNode = nullptr;
            return;
        }

        //Add two numbers represented by Linked Lists
        //E.g. 5->4->3 is 345. 5->2->3 is 325. Result = 670
        int add(LinkedList l){
            Node* this_list = head;
            Node* other_list = l.head;
            int total=0, sum=0, carry=0;
            if(this_list == nullptr || other_list == nullptr){
                return 0;
            }
            int i = 1;
            while(this_list!=nullptr && other_list!=nullptr){
                sum = this_list->val + other_list->val + carry;
                total += (sum%10)*i;
                carry = sum/10;
                this_list = this_list->next;
                other_list = other_list->next;
                i*=10;
            }
            while(this_list!=nullptr){
                sum = this_list->val + carry;
                total+=(sum%10)*i;
                carry = sum/10;
                this_list=this_list->next;
                i*=10;
            }
            while(other_list!=nullptr){
                sum = other_list->val + carry;
                total+=(sum%10)*i;
                carry = sum/10;
                other_list=other_list->next;
                i*=10;
            }
            return total;
        }

        //Merge two sorted linked lists using merged sort
        LinkedList mergeSorted(LinkedList l){
            Node* head_l = l.head;
            LinkedList mergedList;
            if(head==nullptr || head_l==nullptr){
                if(head==nullptr){
                    mergedList=l;
                    return mergedList;
                }else if(head_l==nullptr){
                    return *this;
                }else{
                    mergedList.head=nullptr;
                    return mergedList;
                }
            }
            Node* mergedCurr = nullptr;
            Node* this_head = head;
            if(this_head->val < head_l->val){
                mergedList.head=this_head;
                this_head=this_head->next;
            }else{
                mergedList.head=head_l;
                head_l=head_l->next;
            }
            mergedCurr=mergedList.head;
            while(this_head!=nullptr && head_l!=nullptr){
                if(this_head->val < head_l->val){
                    mergedCurr->next=this_head;
                    this_head=this_head->next;
                }else{
                    mergedCurr->next=head_l;
                    head_l=head_l->next;
                }
                mergedCurr=mergedCurr->next;
            }
            while(this_head!=nullptr){
                mergedCurr->next=this_head;
                this_head=this_head->next;
                mergedCurr=mergedCurr->next;
            }
            while(head_l!=nullptr){
                mergedCurr->next=head_l;
                head_l=head_l->next;
                mergedCurr=mergedCurr->next;
            }
            mergedCurr=mergedCurr->next;
            mergedCurr=nullptr;
            mergedList.printList();
            return mergedList;
        }

};


int main(){
    LinkedList l1;
    //cout<<l1.getSize()<<endl;
    
    l1.insertVal(1);
    l1.insertVal(3);
    l1.insertVal(5);
    l1.insertVal(7);
    
    cout<<l1.getSize()<<endl;
    
    // l1.insertFront(1);
    // l1.insertFront(3);
    // l1.insertFront(5);
    // l1.insertFront(7);

    l1.printList();

    cout<<"l1 Head: "<<l1.head<<" Val: "<<l1.head->val<<endl;

    LinkedList l2;
    l2.insertVal(2);
    l2.insertVal(4);
    l2.insertVal(6);
    l2.insertVal(8);

    l2.printList();

    cout<<"l2 Head: "<<l2.head<<" Val: "<<l2.head->val<<endl;
    
    //Find nth value
    l1.findNthValueFromEnd(3);

    //remove nth value
    l1.removeNthValueFromEnd(3);
    l1.printList();

    //Add

    LinkedList l3;
    l3.insertVal(4);
    l3.insertVal(1);
    l3.insertVal(3);
    l3.insertVal(2);
    l3.insertVal(6);

    LinkedList l4;
    l4.insertVal(5);
    l4.insertVal(4);
    l4.insertVal(9);

    cout<<"Sum: "<<l3.add(l4)<<endl;


    //Merge sorted lists

    LinkedList merged = l1.mergeSorted(l2);
    // merged.printList();
    
}