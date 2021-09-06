
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RMAX 100

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	int ht;
}node;
node *insert(node *, int);
void preorder(node *);
int height(node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
int binarysearch(node*, int);

void over17under55(node *);//search and print all keys between 17 and 55 with preorder traversal
int findmax(node *); //search and  print the max key with preorder traversal
void under17(node *);// search and print all keys < 17 with preorder traversal
void forsearching(node*, int);// search the tree for keys and print the result with preorder traversal
void over55(node *);//search and print all keys >55 with preorder traversal


void main() {
	/*
	Generate 198 numbers between 1-100
Additional 17 and 55 -> total 200, leave the duplicates.
Unique of up to 45 keys from the front of the 200 list. So that you can include 17 and 55.
Capture randomly generated results with a preorder.
*/
	srand(time(NULL));
	int random_no, list[200];
	for (int i = 0; i < 198; i++) {
		random_no = 1 + (int)rand() % RMAX;
		list[i] = random_no;
	}
	list[198] = 17;
	list[199] = 55;
	
	/*
	If you operate the binary search and succeed in insert, the number of uniques increases. 
	17 and 55 are excluded from the beginning and added at the end.
	*/
	
	node *root = NULL;
	
	int x=list[0], unique=0;
	int inputpossible;
	for (int i=0; i<200; i++){
		if (unique == 43) break;
		x = list[i];
		if (x == 17 || x == 55) continue;
		else {
			inputpossible = binarysearch(root, x);
			if (inputpossible != -1) {
				root = insert(root, x);
				unique++;
			}
		}
		printf("i= %d, list[i]=%d, unique= %d\n", i, list[i], unique);
	}
	
	root = insert(root, 17);
	root = insert(root, 55);
	printf("\nPreorder sequence:\n");
	preorder(root);
	printf("\n-----------\n");

	forsearching(root, 13);
	forsearching(root, 21);
	forsearching(root, 53);
	forsearching(root, 72);
	forsearching(root, 91);
	printf("\n-----------\n");
	printf("if max key is -1 then ERROR\n");
	printf("max:%d\n", findmax(root));
	printf("\n-----------\n");
	printf("the datas under 17 : ");
	under17(root);
	printf("\n-----------\n");
	printf("the datas over 55 : ");
	over55(root);
	printf("\n-----------\n");
	printf("the datas between 17 and 55 : ");
	over17under55(root);
}

//In the case of a binary tree, the more you go to the right, the greater the value.
//Thus, the node can find the maximum value until NULL is released.
//However, the values may be mixed to match the bf in the middle, 
//so find both right and left values and compare them.
int findmax(node * tree) {
	int maxkey = -1, right, left, value;
	if (tree != NULL) {
		 value = tree->data;
		 left = findmax(tree->left);
		 right = findmax(tree->right);

		 if (left > right) maxkey = left;
		 else maxkey = right;
		 if (value > maxkey) maxkey = value;
	}
	
	return maxkey;
}
void under17(node * tree) {
	if (tree != NULL) {
		if (tree->data <17)  printf("%d ", tree->data);
		under17(tree->left);
		under17(tree->right);
	}
}
void over55(node * tree) {
	if (tree != NULL) {
		if (tree->data > 55)  printf("%d ", tree->data);
		over55(tree->left);
		over55(tree->right);
	}
}
void over17under55(node * tree) {
	if (tree != NULL) {
		if (tree->data < 55 && tree->data > 17)  printf("%d ", tree->data);
		over17under55(tree->left);
		over17under55(tree->right);
	}
}
//
void forsearching(node* root, int value) {
	if (root == NULL) printf("%d is not here\n", value);
	else if (root->data == value) printf("%d is here\n", value);
	else if (root->data > value)forsearching(root->left, value);
	else forsearching(root->right, value);
	
}

//Activate binary search to return 1, if not the number in the tree and return -1.
int binarysearch(node* root, int value){
	if (root == NULL) {
	
		return NULL;
	}
	else if (root->data == value) return -1;
	else if (root->data > value) binarysearch(root->left, value);
	else binarysearch(root->right, value);

	return 1;
}
//If the ptr value is null, create a new node, and if not null, 
//enter sequentially comparing the data value with the entered value. 
//After entering, obtain each height and BF based on it.
node * insert(node *T, int x)
{
	if (T == NULL)
	{
		T = (node*)malloc(sizeof(node));
		if (T == (node*)NULL)
		{
			printf("can't insert");
		}
		else
		{
			T->data = x;
			T->left = NULL;
			T->right = NULL;
		}
	}
	else
		if (x > T->data)		// insert in right subtree
		{
			T->right = insert(T->right, x);
			if (BF(T) == -2)
				if (x > T->right->data)
					T = RR(T);
				else
					T = RL(T);
		}
		else
			if (x < T->data)
			{
				T->left = insert(T->left, x);
				if (BF(T) == 2)
					if (x < T->left->data)
						T = LL(T);
					else
						T = LR(T);
			}

	T->ht = height(T);

	return(T);
}
//As a new node is added, +1 is added to the parent node.
int height(node *T)
{
	int lh, rh;
	if (T == NULL) return(0);

	if (T->left == NULL) lh = 0;
	else lh = 1 + T->left->ht;

	if (T->right == NULL) rh = 0;
	else rh = 1 + T->right->ht;

	if (lh > rh) return(lh);
	
	return(rh);
}

node * rotateright(node *x)
{
	node *y;
	y = x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height(x);
	y->ht = height(y);
	return(y);
}

node * rotateleft(node *x)
{
	node *y;
	y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = height(x);
	y->ht = height(y);

	return(y);
}

node * RR(node *T)
{
	T = rotateleft(T);
	return(T);
}

node * LL(node *T)
{
	T = rotateright(T);
	return(T);
}

node * LR(node *T)
{
	T->left = rotateleft(T->left);
	T = rotateright(T);

	return(T);
}

node * RL(node *T)
{
	T->right = rotateright(T->right);
	T = rotateleft(T);
	return(T);
}
//Obtain a balance factor. Left height minus right height.
int BF(node *T)
{
	int lh, rh;
	if (T == NULL) return(0);

	if (T->left == NULL) lh = 0;
	else lh = 1 + T->left->ht;

	if (T->right == NULL) rh = 0;
	else rh = 1 + T->right->ht;

	return(lh - rh);
}
//Print in order of parent, left child and right child.
void preorder(node *T)
{
	if (T != NULL)
	{
		printf("%d(Bf=%d)\n", T->data, BF(T));
		preorder(T->left);
		preorder(T->right);
	}
}
