#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	int y;
	struct node *next;
};

struct node *head;


struct kd_node { // (1)
	struct node *data;
	struct kd_node *left;
	struct kd_node *right;
};

struct kd_node *kd_root;

int countingnodes(struct node*);
void Sorting(struct node **, int, int);
struct node *rebuild(struct node **, int, int);
int point_search(struct kd_node *, int, int);
struct kd_node *build_tree(struct node *, int);
void insert(int, int );
void range_search(int , int , int, int );
int compare(int, int , int , int);

int arrcnt = 0;

void main() {
	insert(1, 3);
	insert(5, 14);
	insert(12, 4);
	insert(9, 15);
	insert(3, 7);
	insert(8, 12);
	insert(7, 3);

	int num = countingnodes(head);
	kd_root = build_tree(head, 0);

	if (point_search(kd_root, 5, 14) == 1) printf("(5,14) is in tree\n");
	else printf("(5,14) is not in tree\n");
	if (point_search(kd_root, 3, 7) == 1) printf("(3,7) is in tree\n");
	else printf("(3,7) is not in tree\n");
	if (point_search(kd_root, 10, 3) == 1) printf("(10,3) is in tree\n");
	else printf("(10,3) is not in tree\n");
	
	range_search(4, 6 ,4, 5);
	
	
}
int countingnodes(struct node *_head) {
	int cnt = 0;
	struct node *temp = _head;

	while (1) {
		if (temp == 0) return cnt;
		else {
			cnt++;
			temp = temp->next;
		}
	}
}
// Sort the addresses in the array in ascending order by x or y value.
void Sorting(struct node **arr, int _byX, int _size) {
	for (int j = 0; j < _size; j++) {
		for (int i = 0; i < _size - 1 - j; i++) {
			if (_byX == 1) {
				if (arr[i]->x > arr[i + 1]->x) {
					struct node *temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
			else {
				if (arr[i]->y > arr[i + 1]->y) {
					struct node *temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
	}
}

struct node *rebuild(struct node **arr, int from, int to) {
	if (from > to) return 0;

	struct node *cur = arr[from];
	cur->next = 0;
	struct node *temp = cur;
	for (int i = from + 1; i <= to; i++) {
		temp->next = arr[i];
		temp->next->next = 0;
		temp = temp->next;
	}
	return cur;
}

/*
SLL nodes are stored in array.
Gets the number of nodes in the SLL.
Put it in the array and sort it.
Determine whether to sort with respect to the x- or y-axis.
Returns the address of the generated kdtree node.
*/
struct kd_node *build_tree(struct node *sll, int _depth) {
	if (sll == 0) return 0;
	int numSLLNodes = countingnodes(sll);
	
	struct node **LLtoARR = (struct node **)malloc(sizeof(struct node *)*numSLLNodes);

	int i;
	struct node *temp = sll;
	
	for (i = 0; i < numSLLNodes; i++)
	{
		LLtoARR[i] = temp;
		temp = temp->next;
	}


	int axis = _depth % 2;
	Sorting(LLtoARR, !axis, numSLLNodes);
	int _median = numSLLNodes / 2;
	struct kd_node *cur = (struct kd_node *)malloc(sizeof(struct kd_node));

	cur->data = LLtoARR[_median];
	cur->left = build_tree(rebuild(LLtoARR, 0, _median - 1), _depth + 1, 2);
	cur->right = build_tree(rebuild(LLtoARR, _median + 1, numSLLNodes - 1), _depth + 1, 2);
	arrcnt = numSLLNodes;
	free(LLtoARR);

	return cur;

}

//return 1 if node is there, or return 0
int point_search(struct kd_node *_root, int _x, int _y) {
	struct kd_node *temp = _root;
	int axis = 0;

	while (1){
		if (temp == 0) return 0;
		if (temp->data->x == _x && temp->data->y == _y) return 1;

		if (axis == 0) { // compare x coordinates
			if (temp->data->x > _x) temp = temp->left;
			else temp = temp->right;
		}
		else { // axis =1 -> compare y coordinates
			if (temp->data->y > _y) temp = temp->left;
			else temp = temp->right;
		}

		axis = (axis + 1) % 2;//change axis
	}
}

// Add new_one to the SLL.
// Paste at the end if found, and then move to the next node if not already the end node yet.
void insert(int _x, int _y) {
	struct node *new_one = (struct node *)malloc(sizeof(struct node));
	new_one->x = _x;
	new_one->y = _y;
	new_one->next = 0;

	
	if (head == 0) {
		head = new_one;
		return;
	}
	else {
		struct node *temp = head;
		while (1) {
			if (temp->next == 0) {  
				temp->next = new_one;
				return;
			}
			else temp = temp->next;
			
		}
	}
}


 void range_search(int X, int wid, int Y, int len){
	struct node *forsave = (struct node *)malloc(sizeof(struct node));
	int Xend= X+wid;
	int Yend= Y+len;
	

	struct node **Xadd = (struct node **)malloc(sizeof(struct node *)*20);
	struct node **Yadd= (struct node **)malloc(sizeof(struct node *)*20);

	struct node **LLtoARR = (struct node **)malloc(sizeof(struct node *)*20);
	struct node *temp = head;

	for (int i = 0; i < 20; i++)
	{
		if (temp == NULL) break;
		LLtoARR[i] = temp;
		temp = temp->next;
	}
	
	int xcnt = 0, ycnt=0;
	for(int i=0; i<20; i++){
		if (LLtoARR[i] == NULL) break;
		if (compare(LLtoARR[i]->x, X, Xend, 0) == 1) {
			Xadd[xcnt] = LLtoARR[i];
			xcnt++;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (LLtoARR[i]- == NULL) break;
		if (compare(LLtoARR[i]->y, Y, Yend, 1) == 1) {
			Yadd[ycnt] = LLtoARR[i];
			ycnt++;
		}
	}
	for (int i = 0; i <20; i++) {
		if (Xadd[i] == NULL) break;
		printf("(%d, %d) ", Xadd[i]->x, (*Xadd[i]).y);
	}
	for (int i = 0; i < 20; i++) {
		if (Xadd[i] == NULL) break;
		for (int j = 0; j < 20; j++) {
			if (Yadd[j] == NULL) continue;
			if(Xadd[i]!=Yadd[j]) printf("(%d, %d) ", Yadd[i]->x, Yadd[i]->y);
		}
	}
}
int compare (int val,int low, int high, int axis){
	if (axis == 0) {
		if (val<low || val>high) return 0;
		else return 1;
	}
	else {
		if (val<low || val>high) return 0;
		else return 1;
	}
}
