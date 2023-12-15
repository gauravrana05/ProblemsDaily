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
		while(head!=NULL){cout<<head->value;head=head->next;}
		}

int main(){
llnode* temp = new llnode(5);
llnode* head = temp;
insertathead(head,1);

insertathead(head,2);
print(head);
}
