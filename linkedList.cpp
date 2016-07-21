#include <iostream>
#include <string>
using namespace std;
    struct Node {
        int data;
        Node *next;
    };
class LinkedList{

public:
	Node* head;
    LinkedList(){
        head = NULL;
    }
    
    LinkedList(int arr[], int size){
    	
    	
    	Node* cur = NULL;
    	for(int i=0;i<size;i++){
    		if(cur ==NULL){
    			Node* n = new Node();
    			n->data = arr[i];
    
    			cur = n;
    			this->head = cur;
    		
    		}
    		else{
    			
    			Node* n1 = new Node();
    		
    			n1->data = arr[i];
    			
    			cur->next = n1;
    			cur = n1;
    		}
    	}
    }
 	void reverse(){
 		Node* prev = NULL;
 		Node* next = NULL;
 		Node* h = head;
 		while(h)
{  			next = h->next;
 			h->next = prev;
 			prev = h;
 			h = next;
 		}
 		head = prev;
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
        while(tempNode != NULL){
            if(counter++ == 10){
                cout <<"NULL" << endl;
                return;
            }
            cout << tempNode->data << "->";
            tempNode = tempNode->next;

        }
        cout << endl;
    }
private:
    
};
LinkedList addLLs(LinkedList l1, LinkedList l2){
	LinkedList newList;
	l1.reverse();
	l2.reverse();
	Node* H = l1.head;
	Node* H2 = l2.head;
	int carry =0;

	while(H || H2){
		int sum = H->data + H2->data+carry;
		carry =0;
		if(sum >10)
		{
			carry = 1;
			sum = sum%10;
		}
		newList.addValue(sum);
		H = H->next;
		H2 = H2->next;
	}
	return newList;
}
int main() {
	int arr[] = {1,2,3,4,5};
	int arr2[] = {6,7,8,9,10};
    LinkedList llist(arr,5);
    LinkedList llist2(arr2,5);

    llist.reverse();

    LinkedList newList = addLLs(llist, llist2);
    newList.printList();
    return 0;
}
