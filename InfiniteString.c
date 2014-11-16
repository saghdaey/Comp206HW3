
//question 3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DELIM " \n"

//#define ENGLISH
#define FRENCH

//CREATE A LINKED LIST OF NODES
//using struct to create a node: value stored at the node is a word (character array called val), node also has pointer to the next node.  
struct entryList 
{
	char val[100]; 
	struct entryList *next; 
}; 


char inputLine[200]; //made this char array larger than the one called value in case user inputted more than 1 word

typedef struct entryList listOfItems;

int main(int argc, char* argv())
{
	//initializing pointers to our linked list
	listOfItems *head=NULL;
	listOfItems *current;
	listOfItems *prev=NULL;
	
	#ifdef ENGLISH
		printf("Welcome to the infinite string storage program. \n");
	#else
		printf("Bienvenue au programme de mise en memoire de chaine infinie. \n");
	#endif

	while(1)
	{
	
	#ifdef ENGLISH
		printf("Wassup cutie. Please write a single word, yo.\n");
	#else
		printf("Bonjour hi mon cher. Ecrivez un seul mot, s'il vous plait \n");
	#endif
	
		fgets(inputLine, sizeof(inputLine), stdin); //get input from keyboard and stores in character array
	
		char *token=strtok(inputLine, DELIM); //tokenize inputLine to  get 1st word
	
		//if user typed ***END*** word, print everything previously entered
		if(strcmp(token, "***END***")==0) 
		{
			current=head; //start at 1st node of linked list
			while(current!=NULL) //loop in while until the value of each node has been printed 
			{
				printf("%s ", current->val); 
				current=current->next; //move on to next entry in linked list
			}
			printf("\n");
			break; //once all entries printed, break out of infinite while (outer while loop)
		}
	
		else //if user didn't print END, add word they typed in to the linked list
		{
			current=(listOfItems *)malloc(sizeof(listOfItems)); //allocate space for a new word, point current to this space
			if(head==NULL) //the 1st time the user inputs a word, head will have been null so point head to space allocated by malloc
			{
				head=current; 
			}
			
			if(token!=NULL) //if token is not null, copy user's input into the node so node's value becomes this word
			{
				strcpy(current->val, token);  
			}
				
			if(prev!=NULL)
			{
				prev->next=current; //create pointer between end of linked list (so from prev) to new node pointed to by current
			}
			
			prev=current; //previous always points to the last node in our linked list after our program runs for 1 line of user input
		}	
	
	}
	return 0;
}
