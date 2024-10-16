#include<iostream>

using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node* prev;
    Node(int data){
        this->value = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL{
public:
    int length = 0;
    Node* head = NULL;
    Node* tail = NULL;
    void insert(int data){
        Node* x = new Node(data);
        if (head == NULL){
            head = x;
            tail = x;
        }
        else {
            tail->next = x;
            x->prev = tail;
            tail = tail->next;
        }
        length++;
    }
    void display(){
        Node* temp = head;
        while (temp!=NULL){
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
    void deletePosition(int index){
        // cout<<length<<" "<<index<<endl;
        Node* temp = head;
        if (index>=length) {
            cout<<"Invalid Index"<<endl;
            return;
        }
        else {
            if (index == 0){
                // delete head
                temp = head->next;
                head->next = NULL;
                temp->prev = NULL;
                head = temp;
            }
            else if (head == tail){
                // only one element in linkedlist
                head = NULL;
                tail = NULL;
            }
            else if (index == length-1){
                // delete tail
                temp = tail->prev;
                temp->next = NULL;
                tail->prev = NULL;
                tail = temp;
            }
            else {
                // delete one element from middle of the linkedlist
                for (int i = 0; i < index-1; i++){
                    temp = temp->next;
                }
                Node* node = temp->next;
                Node* nodeNxt = node->next;
                temp->next = node->next;
                nodeNxt->prev = temp;
                node->next = NULL;
                node->prev = NULL;
            }
            length--;
        }
    }
    void deleteValue(int value){
        int index = 0;
        Node* temp = head;
        while(temp!=NULL){
            if (temp->value == value){
                deletePosition(index);
                return;
            }
            index++;
            temp=temp->next;
        }
    }
};

int main(){
    DLL list1;
    list1.insert(0);
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);
    list1.insert(50);
    list1.insert(60);
    list1.display();
    list1.deletePosition(4);
    list1.display();
    list1.deletePosition(0);
    list1.display();
    list1.deletePosition(4);
    list1.display();
    list1.deleteValue(70);
    list1.display();
}