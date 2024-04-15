#include<stdio.h>
#include<stdlib.h>


typedef struct n{
	int elem;
	struct n* LC;
	struct n* RC;
}*BST , tree;

void insert(BST* Tr, int elem);
void display(BST tr);
int member(BST tr , int elem);
void deleteNode(BST *tr , int elem);

int main(void){
	
	BST root = NULL;
	
	insert(&root, 5);
	insert(&root, 0);
	insert(&root, 6);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 1);
	insert(&root, 8);
	insert(&root, 4);
	insert(&root, 7);
	
	
	display(root);
	
	int delElem = 5;
	printf("\nDelete %d", delElem);
	deleteNode(&root , delElem);
	printf("\n");
	
	display(root);
	printf("\n");	
	int elem = 30;
	if(member(root,elem)){
		printf("Element %d found\n", elem);
	}
	else{
		printf("Element %d is not Found\n", elem);
	}
	
	
	return 0;
}
int member(BST Tr , int elem){
	BST trav;
		for(trav = Tr; trav != NULL && trav->elem != elem;){
			trav = trav->elem < elem ? trav->LC : trav->RC;
		}
		
	return trav != NULL ? 1 : 0;
} 	
void display(BST tr){
	

	if(tr != NULL){
		display(tr->LC);
		printf("%d ",tr->elem);
		display(tr->RC);
	}
}
void insert(BST* Tr, int elem){
	
	BST newnode = (BST)calloc(1, sizeof(tree));
	BST *trav;
	if(newnode != NULL){		
		for(trav = Tr; *trav != NULL && (*trav)->elem != elem;){
			trav = (*trav)->elem < elem ? &(*trav)->LC : &(*trav)->RC;
		}
		
		if(*trav == NULL){
			*trav = newnode;
			newnode->elem = elem;
		}
		else{
			printf("The Element is already existed\n");
		}
	}
}
void deleteNode(BST *tr , int elem){
	
	BST *trav;
	BST temp;
	
	for(trav = tr ; *trav != NULL && (*trav)->elem != elem ; ){
		trav = (*trav)->elem < elem ? &(*trav)->LC : &(*trav)->RC;
	}
	if(*trav != NULL ){
		temp = *trav;
		if((*trav)->LC == NULL){
			*trav = temp->RC;
		}
		else if((*trav)->RC == NULL){
			*trav = temp->LC;
		}
		else{
			//this is for finding the successor / predecessor 
			
			for(temp = (*trav)->RC ; temp->LC != NULL ; temp = temp->LC){}
			(*trav)->elem = temp->elem;	
			(*trav)->RC = temp->RC;
			
		}
		free(temp);
		
	}
	
}