#include<iostream>
using namespace std;


class node{
	public:
		int val;
		node* next;


		node(int a){
			this->val = a;
			this->next = NULL;
		}

};

void insertathead(node* &head,int value){
	node* temp = new node(value);
	temp->next = head;
	head = temp;

}

void print(node* head){
	while(head!=NULL){
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

node* reverse(node* &head){

	node* prev = NULL;
	node* curr = head;

	while(curr!=NULL){
		node* next = curr->next;

		curr->next = prev;

		prev=curr;
		curr=next;

	}
	return prev;


}

<<<<<<< Updated upstream
}



node* recrev(node* &head){




=======
node* recrev(node* &head){

	if(head->next==NULL || head==NULL){
		return head;
	
	}	
	
	node* chhota = recrev(head->next);
	head->next->next = head;
	head->next = NULL;
	return chhota;
>>>>>>> Stashed changes

}


<<<<<<< Updated upstream
=======


>>>>>>> Stashed changes
int main(){

	node* ll = new node(5);
	node* head = ll;

	insertathead(head,4);
	insertathead(head,3);
	insertathead(head,2);
	insertathead(head,1);

	print(head);
//	head=reverse(head);
//	print(head);
	print(recrev(head));
}
