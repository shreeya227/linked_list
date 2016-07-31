/* Program: To implement linked list
Author : Shreeya Pandey [0547]
Date	  : 31-07-2016
Ref    : Data Structures using C and C++, Chap 4*/
 #include <stdio.h>
 #include <stdlib.h>
	struct node {
 	int info;
 	struct node *next;
 };
 typedef struct node *nodeptr;
 
 nodeptr getnode();
 void freenode(nodeptr);
 void insertatfirst(nodeptr *, int);
 int deletefromfirst(nodeptr *);
 void displaylist(nodeptr);
 int check_underflow(nodeptr *);
 
 int main () {
 	nodeptr list;
 	list = NULL;
 	
 	insertatfirst(&list, 5);
 	insertatfirst(&list, 6);
 	insertatfirst(&list, 7);
 	insertatfirst(&list, 8);
 	
 	displaylist(list);
 	printf ("Deleted = %d\n", deletefromfirst(&list));
 	printf ("Deleted = %d\n", deletefromfirst(&list));
 	printf ("Deleted = %d\n", deletefromfirst(&list));
 	printf ("Deleted = %d\n", deletefromfirst(&list));
 	printf ("Deleted = %d\n", deletefromfirst(&list));
 	
 	return 0;
 }
 
 nodeptr getnode() {
 	return (nodeptr)malloc(sizeof(struct node));
 }
 
 void freenode(nodeptr p) {
 	free (p);
 }
 
 void insertatfirst(nodeptr *p, int x) {
 	nodeptr q;
 	q = getnode();
 	q->info = x;
 	q->next = *p;
 	*p = q;
 }
 
 void displaylist(nodeptr p) {
 	nodeptr ptr = p;
 	while(ptr != NULL) {
 		printf ("%d \n", ptr->info);
 	ptr = ptr->next;
 	}
 }
 
 int deletefromfirst (nodeptr *p) {
 	if (check_underflow(p)) {
		printf ("\n Linked List Underflow \n");
 		getch();
 		exit(1);
 	} else {
 		int x;
 		nodeptr q;
 		q = *p;
 		
 		*p = q->next;
 		x = q->info;
 		
 		return x;
 		
 		freenode(q);
 	}
 }
 
 int check_underflow(nodeptr *p){
 	return (*p == NULL);
 }
