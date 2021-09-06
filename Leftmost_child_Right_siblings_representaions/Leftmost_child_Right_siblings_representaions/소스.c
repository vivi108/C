#include<stdio.h>
#include<stdlib.h>

struct NODE {
	int key;
	struct NODE * leftchild;
	struct NODE * rightchild;
};
struct NODE *head = NULL;
//to save the general tree data.
struct GENERAL {
	int level;
	int key;
	int child_key;
}tree[10]= { {1,100 , 200}  ,{2,200,NULL}, {2,  75 , 25 }, {2 ,300 ,NULL }, {2,95 ,150 }, {3, 25, NULL }, { 3 , 50 , NULL }, { 3 , 30,  120 }, { 3 , 150  ,NULL },{4 , 120 , NULL} };
//want to put tree1, then enter the values.

void main() {
	void lcrs();
	lcrs();
}

//Leftmost child-right siblings representation
/*
Except for the leftmost child, all children remove the pointer with their parents.
And the right brother becomes the right child. 
These two steps allow us to create algorithms.
*/
void lcrs() {
	void preorder(struct NODE*);
	int check = 0;
	struct NODE * newnode;
	struct NODE * ptr = head, *prev = NULL;

	for (int i = 0; i < 10; i++) {
		
		newnode = (struct NODE*)malloc(sizeof(struct NODE));
		if (newnode == (struct NODE *)NULL) printf("malloc failed");

		newnode->key = tree[i].key;
		newnode->rightchild = NULL;
		newnode->leftchild = NULL;

		if (tree[i].level == 1) {
			head = newnode;
			ptr = head;
		}
		else {
			ptr->rightchild = newnode;
			ptr = newnode;
		}
	}
	
	ptr = head;
	prev = ptr;

	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (tree[i].child_key == tree[j].key && (tree[j].level - tree[i].level) == 1) {
				ptr->leftchild = ptr->rightchild;
				ptr->rightchild = NULL;
				check = 1;
				}

			}if (check == 0) ptr = ptr->rightchild;
			else {
				check = 0;
				ptr = ptr->leftchild;

			}
		}

	preorder(head);
}

	
/*
//To input the general tree
int input() {
	int i=0;/
	while (scanf_s("(%d %d %d)", &tree.level, &tree.key, &tree.child_key) == 3) {
		i++;
		printf("\ni=%d\n", i);
	}
	return i;
}*/

//parent first, left child second, right child third. Print out in this order.
void preorder(struct NODE* node) {
	if (node != NULL) {
		printf("%d ", node->key);
		preorder(node->leftchild);
		preorder(node->rightchild);
	}
}
