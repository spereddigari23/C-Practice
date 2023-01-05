#include <iostream>
#include <cmath>

struct Node {
    int data;
    struct Node *next;
};
class LinkedList{
    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
        }
        void addNode(int data){
            Node *temp = new Node;
            temp->data = data;
            temp->next = nullptr;
            if (head==nullptr){
                head=temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
            size++;
            return;
        }
        void printList(){
            Node *temp = head;
            while(temp!=nullptr){
                std::cout<< temp->data << std::endl;
                temp = temp->next;
            }
            return;
        }
        void pushNode(int data){
            Node *t = new Node;
            t->data = data;
            t->next = head;
            head = t;
            size++;
            return;
        }
        void insertAtPosition(int data, int position){
            Node *t = new Node;
            t->data = data;
            Node *pre = new Node;
            Node *curr = new Node;
            curr = head;
            for(int i=1; i<position;i++){
                pre = curr;
                curr = curr->next;
            }
            pre->next = t;
            t->next = curr;
            size++;
            return;
        }
        int pop(){
            int retval = 0;
            Node *sec = new Node;
            sec = head->next;
            retval = head->data;
            delete head;
            head = sec;
            return retval;
        }
        int removeLast(){
            int retval = -1;
            if(head->next == nullptr){
                int retval = head->data;
                delete head;
            }else{
                Node *temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
            size--;
            return retval;
        }
        void reverseList(){
            Node *prev = nullptr;
            Node *curr = head;
            while(curr!=nullptr){
                Node *temp = curr->next;
                curr->next = prev;
                prev=curr;
                head = prev;
                curr = temp;
            }
        }
    private:
        Node *head;
        Node *tail;
        int size=0;
};

int main(){
    return 0;
}