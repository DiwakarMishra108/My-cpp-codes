#include<iostream>
using namespace std;
class Node{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(int d){
     this->data = d;
     this->prev = NULL;
     this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory is free for node with data"<<val<<endl;
    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}
int getlength( Node* &head){
    int len =0;
    Node* temp = head;
    while(temp!= NULL){
        len++;
        temp= temp->next;
    }
    return len;
}
void insertathead(Node* &head,int d){
    if(head==NULL){
       Node* temp = new Node(d);
       head=temp;
    }
    else{
     Node* temp = new Node(d);
     temp->next=head;
     head->prev=temp;
     head = temp;
    }
}
void insertattail(Node* &tail,int d){
    if(tail==NULL){
       Node* temp = new Node(d);
       tail=temp;
    }
    else{
        Node* temp = new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail = temp;
    }
}
void insertatposition(Node* &tail,Node* &head,int position,int d){
    // insert at first position
    if(position == 1){
        insertathead(head,d);
        return;
    }
    Node* temp = head;
    int cnt =1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    // creating new node for insertion
    Node* nodetoinsert = new Node(d);
     nodetoinsert->next = temp->next;
     temp->next->prev = nodetoinsert;
     temp->next= nodetoinsert;
     nodetoinsert->prev =temp;

    // inserting at last position
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }

}
void deletenode(Node* &head,int position){
    // delettinng first or start node
    if(position==1){
       Node* temp = head;
       temp->next->prev=NULL;
       head = temp->next;
       temp->next=NULL;

    //    memory free start node
       temp->next=NULL;
       delete temp;
    }
    else{
        // deletting any middle node or last node
        Node* curr= head;
        Node* prev= NULL;
        int cnt =1;
        while(cnt<=position){
          prev = curr;
          curr= curr->next;
          cnt++;
        }
        curr->prev =NULL;
        prev->next= curr->next;
        curr->next=NULL;
        delete curr;
    } 
}
int main(){
    Node* node1 = new Node(12);
    // cout<<node1->data;
    Node* tail= node1;
    Node* head = node1;
    print(head);
    insertathead(head,13);
    insertathead(head,14);
    insertathead(head,15);
    insertattail(tail,11);
    insertatposition(tail,head,3,52);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data;
    deletenode(head,1);
    print(head);
 return 0;
}