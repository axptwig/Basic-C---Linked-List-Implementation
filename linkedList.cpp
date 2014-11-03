#include <iostream>
#include <string>
using namespace std;

class LinkedList{
    struct Node {
        int data;
        Node *next;
    };
public:
    LinkedList(){
        head = NULL;
    }
    void addValue(int val){
        Node *n = new Node();   
        n->data = val;    
        n->next = head;                              
        head = n; 
    } 
    void createLoop(){
        Node* tempNode = head;
        Node* cycleNode = head->next;
        while(tempNode->next != NULL){
            tempNode=tempNode->next;
        }
        tempNode->next = cycleNode;
    }  
    void hasLoop()
    {
        if(head != NULL)
        {
            Node* slowNode = head;
            Node* fastNode = head;
            while(fastNode != NULL)
            {
                slowNode = slowNode->next;
                fastNode = fastNode->next;
                if(fastNode != NULL){
                    fastNode = fastNode->next;
                }
                else{
                    cout<<"there is no cycle" << endl;
                    break;
                }
                cout << "slownode: " << slowNode->data << endl;
                cout << "fastnode: " << fastNode->data << endl;
                if(fastNode==slowNode){
                    cout << "The data of the node that creats the cycle is " << slowNode->data << endl;
                    break;
                }
            }
        }
    }   
    void middleElement(){
        Node* fastNode = head;
        Node* slowNode = head;
        if(head != NULL){ // probably should add this to all the other functions
            while(fastNode->next->next != NULL){
                slowNode = slowNode->next;
                fastNode = fastNode->next->next;
                if(fastNode->next == NULL){
                    break;
                }
            }
        cout << "the data of the middle element is " << slowNode->data << endl;
        }
    }     
    int popValue(){
        Node *n = head;
        int ret = n->data;
        head = head->next;
        delete n;
        return ret;
    }
    void printList(){
        Node* tempNode = head;
        int counter = 1;
        cout<<"head->data: " <<head->data << endl;
        while(tempNode != NULL){
            if(counter++ == 10){
                cout <<"NULL" << endl;
                return;
            }
            cout << tempNode->data << "->";
            tempNode = tempNode->next;
        }
        
    }
private:
    Node* head;
};
int main() {
    LinkedList list;
    list.addValue(5);
    list.addValue(10);
    list.addValue(15);
    list.addValue(20);
    list.addValue(25);
    list.addValue(30);
    list.addValue(35);
    //list.middleElement();
    list.createLoop();
    list.printList();
    list.hasLoop();
    return 0;
}