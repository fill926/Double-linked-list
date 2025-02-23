#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int x;
	tnode *next;
	tnode *prev;//1
}*head, *tail, *curr;

void push_front(int value)
{
	//create node
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	node->x = value;
	
	if(head==NULL)//cek data awal, jika tdk ada lgsg bikin node
	{
		head = tail = node;
		node->next = NULL;
		node->prev = NULL;//2
	}
	else
	{
		node->next = head;
		head->prev = node;//3
		head = node;
		head->prev = NULL;//4
	}
}

void push_back(int value)
{
	//create node
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	node->x = value;
	
	if(head==NULL)//cek data awal
	{
		head = tail = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
		tail->next = NULL;
	}
}

void push_mid(int value, int searchKey)
{
	//create node
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	node->x = value;
	
	if(head==NULL)//cek data awal
	{
		head = tail = node;
		tail->next = NULL;
	}
	else
	{
		//struct tnode *curr = head;
		
		while(curr!=NULL)
		{
			if(curr->x == searchKey)
			{
				if(curr==tail)
				{
					push_back(value);
				}
				else
				{
					node->next = curr->next;
					curr->next = node;
				}
				break;
			}
			curr = curr->next;
		}
		if(curr==NULL)
		{
			printf("Data %d not found\n", searchKey);
		}
	}
}

void delete_front(){
	//kosong
	if(head == NULL)
	{
		printf("Kosong\n");
		return;
	}
	
	//ada isi
	else{
		//ada 1
		if(head == tail)
		{
			free(head);
			head = tail = NULL;
		}
		
		//ada bbrp
		else
		{
			tnode *curr = head;
			head = head->next;
			free(curr);
			head->prev = NULL;
		}
	}
}

void delete_back(){
	//kosong
	if(head == NULL)
	{
		printf("Kosong\n");
		return;
	}
	
	//ada isi
	else{
		//ada 1
		if(head == tail)
		{
			free(tail);
			tail = head = NULL;
		}
		
		//ada bbrp
		else
		{
			tnode *ToDel = tail;
			tail = tail->prev;
			free(ToDel);
			tail->next = NULL;
		}
	}
}

void delete_mid(int value){
	//kosong
	if(head == NULL)
	{
		printf("Kosong\n");
		return;
	}
	
	//ada isi
	if(value == head->x)
	{
		delete_head();
	}
	else if(value == tail->x)
	{
		delete_tail();
	}
	else
	{ //value ada di mid -> pop mid
		tnode *curr = head;
		
		while(curr)
		{
			
			//ketemu sama value yg mau di pop
			if(curr->x == value)
			{
				break; //stop while
			}
			curr = curr->next;
		}
		
		tnode *prevNode = curr->prev;
		tnode *nextNode = curr->next;
		
		//hubungin prevnode sama nextnode
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		free(curr);
		curr = NULL;
	}
}

void clearData()
{
	while(head!=NULL)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}

void printList()
{
	if(head==NULL)
	{
		printf("There is No Data\n");
		return;
	}
	
	//struct tnode *curr = head;
	curr = head;
	
	while(curr!=NULL)
	{
		printf("%d ", curr->x);
		curr=curr->next;
	}
}


int main()
{
	printf("PUSH DATA\n");
	
	push_front(11);
	push_back(90);
	push_front(78);
	push_back(50);
	//78 11 90 50
	//push_mid(22,90);
	//push_mid(18,78);
	
	//50 78 90 11
	//78 11 90 50
	//78 18 11 90 22 50
	//printList();getchar();
	delete_front();
	delete_back();
	
//	clearData();
	printList();getchar();
	return 0;
}
