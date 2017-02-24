#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};
void print(Node *head) {
	int counter = 1;
	while(head!=NULL) {
		cout<<"Node " <<counter++<<" "<<head->data<<endl;
		head =head->next;
	}
}
void add(Node *head, int data) {
	while(head->next != NULL ) {
		head = head->next;
	}
	head->next = (struct Node *) malloc(sizeof(struct Node ));
	head->next->data = data;
} 

int length(Node *head) {
	int len = 0;
	while(head!=NULL) {
		len++;
		head = head->next;
	}
	return len;
}
Node* reverse(Node *head) {
	Node *pre = NULL;
	Node *next = NULL;
	while(head!=NULL) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}
bool is_palindrome(Node * head) {
	int len = length(head);
	bool answer = true;
	int temp = len / 2;
	int temp1= temp;
	Node *firstNode = head;
	while(temp--) {
		firstNode = firstNode->next;
	}
	if(len %2 !=0) {
		firstNode = firstNode->next;
	}
	Node *lastNode = reverse(firstNode);
	Node *endNode = lastNode;
	Node *startNode = head;
	for(int i = 0; i< temp1; i++) {
		if(startNode->data != lastNode->data) {
			answer = false;
			break;
		}
		startNode = startNode->next;
		lastNode = lastNode->next;
	}
	reverse(endNode);	
	return answer;
}


int main() {

	Node *head = (struct Node *) malloc(sizeof(struct Node ));
	head->data = 3;
	add(head,5);
	add(head, 6);
	add(head, 5);
	add(head, 3);
//	print(head);
	cout<<is_palindrome(head)<<endl;
//	print(head);
	return 0;
}
