/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
using namespace std;
class Node{ //self_referencing class
    public:
        int info;
        Node *next;
        Node(int info){
            this->info=info;
            next=NULL;
        }
};
class LinkedList{
    Node *start;
public:
    LinkedList(){
        start=NULL;
    }
    void addfirst(int item){
        Node *newnode=new Node(item);
        newnode->next=start;
        start=newnode;
    }
    void addlast(int item){
        Node *newnode=new Node(item);
        if(start==NULL)
            start=newnode;
        else{
            Node *ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
        }
    }
    void addafter(int numb,int item){
        Node *newnode,*ptr;
        ptr=start;
        while(ptr!=NULL && ptr->info!=numb){
            ptr=ptr->next;
        }
        if(ptr==NULL){
            cerr<<"Number not found"<<endl;
            return;
        }
        newnode=new Node(item);
        newnode->next=ptr->next;
        ptr->next=newnode;
    }
    void addbefore(int numb,int item){
        Node *newnode,*ptr,*preptr;
        preptr=NULL;
        ptr=start;
        while(ptr!=NULL && ptr->info!=numb){
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            cerr<<"Number not found"<<endl;
            return;
        }
        newnode=new Node(item);
        if(ptr==start){
            newnode->next=start;
            start=newnode;
        }
        else{
            newnode->next=ptr;
            preptr->next=newnode;
        }
    }
    void traverse(){
        Node *ptr=start;
        while(ptr!=NULL){
            cout<<ptr->info<<"\t";
            ptr=ptr->next;
        }
    }
    void delnode(int item){
        Node *newnode,*ptr,*preptr;
        preptr=NULL;
        ptr=start;
        while(ptr!=NULL && ptr->info!=item){
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            cerr<<"item not found"<<endl;
            return;
        }
        if(ptr==start){
            start=start->next;
        }
        else{
            preptr->next=ptr->next;
        }
        delete ptr;
    }
};
int main(){
    LinkedList l1;
    l1.addfirst(30);
   
     l1.traverse();
      cout<<endl;
    l1.addfirst(20); 
     l1.traverse();
      cout<<endl;
    l1.addfirst(10); 
    l1.traverse();
     cout<<endl;
    l1.addlast(40);
     l1.traverse();
      cout<<endl;
    l1.addlast(50);
     l1.traverse();
      cout<<endl;
    l1.addafter(10,15);
     l1.traverse();
      cout<<endl;
    l1.addafter(50,55);
     l1.traverse();
      cout<<endl;
    l1.addafter(30,35);
     l1.traverse();
      cout<<endl;
    l1.addbefore(10,9);
     l1.traverse();
      cout<<endl;
    l1.addbefore(15,14);
     l1.traverse();
      cout<<endl;
    l1.delnode(14);
     l1.traverse();
      cout<<endl;
    l1.delnode(9);
    l1.traverse();
	return 0;
}
