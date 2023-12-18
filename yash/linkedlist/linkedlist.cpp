#include <iostream>
using namespace std;

class llnode{

	public:
		int value;
		llnode* next;

		llnode(int n){
			this-> value = n;
			this-> next = NULL;
		}

};

void insertathead(llnode* &head,int data){
	llnode* temp2 = new llnode(data);
	temp2->next = head;
	head = temp2;

}
void print(llnode* head){
	while(head!=NULL){cout<<head->value<<" ";head=head->next;}
	cout<<endl;
}

void insertattail(llnode* &tail,int data){

	llnode* temp = new llnode(data);
	tail-> next = temp;
	tail = temp;



}


void insertinmiddle(llnode* &head, int position, int data){
	llnode* temp = new llnode(data); 
	llnode* temp2 = head;
	int count = 1;
	while(count<position){
		temp2 = temp2->next;
		count++;
	}
	temp->next = temp2->next;
	temp2->next = temp;

}

llnode* rev(llnode* &head){

	llnode* prev = NULL;
	llnode* curr = head;
	llnode* nex;

	while(curr!=NULL){

		nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;


	}
	return prev;



}



int main(){
	llnode* temp = new llnode(5);
	llnode* head = temp;
	llnode* tail = temp;
	insertathead(head,1);
	insertattail(tail,7);
	insertathead(head,2);
	insertinmiddle(head,3,12);
	insertattail(tail,10);
	print(head);
	llnode* reve = rev(head);
	print(reve);
}
