/*
	This simple program is an implementation of a binary tree.
	Every entry in that tree will be a struct, which contains
	a key, value, left- and right child.
*/

#include <stdio.h>

typedef struct t_entry {

	int key;
	// the value to store is a string, max size is 10 chars
	char val[10];
	struct t_entry *l_child;
	struct t_entry *r_child;
} T_ENTRY;

/*
	This function inserts a value into the tree, given by 
	head.
*/
void insert(int key, char val[], T_ENTRY head) {

	
}

int main(void) {

	return 0;
}
