#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isError = 0;

struct Node {
	char name[256];
	struct Node * next;
};

void append(struct Node **head, char *data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
    strcpy(new_node->name, data);
    new_node->next = NULL;

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}


void print_list(struct Node* node)
{
	while (node != NULL) {
		printf("%s ", node->name);
		node = node->next;
	}
}

void admit(struct Node **head)
{
	struct Node* next_node = NULL;

	if(*head == NULL){
		printf("no person in the list\n");
//checks whether there is any one or not
		return;
	}

	next_node = (*head)->next;
	free(*head);

	*head = next_node;

	return;
}

void delete_Node(struct Node **head, char *data)
{

	struct Node *temp = *head;
	struct Node *prev;


	if (temp != NULL && strcmp(temp->name, data) == 0)
	{ 
        	*head = temp->next;  
        	free(temp);              
        	return;
	}
	while(temp != NULL && strcmp(temp->name, data) != 0){ 
        	prev = temp; 
        	temp = temp->next; 
    	} 
    	if (temp == NULL){ 
        	printf("you typed a false name!\n");
			isError = true;
        	return; 
    	}
    	prev->next = temp->next; 
    	free(temp); 
}
void free_space(struct Node *node) {
	while (node != NULL) {
		free(node);
		node = node->next;
	}
}


int main()
{
	struct Node *head = (struct Node*) malloc(sizeof(struct Node));
	struct Node *head2 = (struct Node*) malloc(sizeof(struct Node));
	struct Node *head3 = (struct Node*) malloc(sizeof(struct Node));
	char input[256];
	bool quit = 0;
		
	strcpy(head->name, "Turgut");
	head -> next = NULL;
 	append(&head, "Nazrin");
 	append(&head, "Nigar");
	append(&head, "Kamran");
	append(&head, "Eljan");

	print_list(head);	
	printf("\n");
	
	while(!quit)
	{
	printf("Enter a command: ");
  	scanf( "%s" , input);
  	if (strcmp(input,"quit") == 0){
		quit = 1;
		free_space(head);
	}
  	else if (strcmp(input,"admit") == 0){
		admit(&head);
		printf("\n");
	}
	else{
		delete_Node(&head, input);
        	if(!isError){
			append(&head, input);	
	   	}
		isError = 0;
	}	
	print_list(head);
	printf("\n");
	}
	return 0;
}
