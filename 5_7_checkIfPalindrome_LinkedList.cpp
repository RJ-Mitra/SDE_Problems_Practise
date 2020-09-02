//Check if LL is palindrome

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
        
        //function to find if a linked list is a palindrome

        //Approaches:
        //1. Using stacks: Push each element into a stack during 1st traversal. During 2nd traversal, pop each element from stack and compare. If all elements are matching, the list is a palindrome
        //2. Reversing the LL: Reverse the 2nd half of the LL and compare it with the 1st half
        //3. Using a recursive function: Using tail recursion, go the the end of the list and compare head with tail. With each match, return back and keep changing left to the next element

        //func to reverse the LL
        void reverseLL(Node** head){
            Node* prev = nullptr;
            Node* curr = *head;
            Node* temp = nullptr;
            while(curr!=nullptr){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr=temp;
            }
            *head=curr;
        }

        bool compareLists(Node* head1, Node* head2){
            Node* temp1 = head1;
            Node* temp2 = head2;
            while(temp1!=nullptr && temp2!=nullptr){
                if(temp1->val == temp2->val){
                    temp1=temp1->next;
                    temp2=temp2->next;
                }else{
                    return false;
                }
            }
            if(temp1 == nullptr && temp2 == nullptr) return true;
            return false;
        }

        bool isPalindrome(){
            bool result = true;
            Node* fast_ptr = head;
            Node* slow_ptr = head;
            Node* prev_slow_ptr = head;
            Node* second_half = nullptr;
            Node* midnode = nullptr; //to handle list with odd number of elements
            if(head!=nullptr && head->next!=nullptr){
                while(fast_ptr!=nullptr && fast_ptr->next!=nullptr){
                    fast_ptr=fast_ptr->next->next;
                    prev_slow_ptr = slow_ptr;
                    slow_ptr=slow_ptr->next;
                }
                if(fast_ptr!=nullptr){ //if fast_ptr is not null, number of nodes are odd because fast ptr moves by 2, else even
                    midnode=slow_ptr;
                    slow_ptr = slow_ptr->next;
                }
                second_half = slow_ptr;
                prev_slow_ptr->next = nullptr; //null terminating the 1st list
                reverseLL(&second_half); //reversing the 2nd half of the linked list
                result = compareLists(head,second_half);
                reverseLL(&second_half);
                if(midnode!=nullptr){
                    prev_slow_ptr->next = midnode;
                    midnode->next = second_half;
                }else{
                    prev_slow_ptr->next = second_half;
                }
            }
            return result;
        }
        
        //Recursive approach

        bool isPalindromeRecur(Node** left, Node* right){
            if(right == nullptr) return true;
            bool isP = isPalindromeRecur(left,right->next);
            if(isP==false) return false;
            bool isP1 = (right->val == (*left)->val);
            *left = (*left)->next;
            return isP1;
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
                size--;
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
};

int main(){
    LinkedList oddList;
    oddList.insertFront(1);
    oddList.insertFront(2);
    oddList.insertFront(3);
    oddList.insertFront(2);
    oddList.insertFront(1);

    oddList.printList();

    LinkedList evenList;
    evenList.insertVal(1);
    evenList.insertVal(2);
    evenList.insertVal(3);
    evenList.insertVal(3);
    evenList.insertVal(2);
    evenList.insertVal(1);

    evenList.printList();

    cout<<"Odd list: "<<oddList.isPalindromeRecur(&oddList.head, oddList.head)<<endl;
    cout<<"Even list: "<<evenList.isPalindromeRecur(&evenList.head, evenList.head)<<endl;

    cout<<"Is palindrome Oddlist: "<<oddList.isPalindrome()<<endl;
    cout<<"Is palindrome Evenlist: "<<evenList.isPalindrome()<<endl;

}