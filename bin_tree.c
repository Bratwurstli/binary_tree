/*
	This simple program is an implementation of a binary tree.
	Every entry in that tree will be a struct which contains
	a key, value, left- and right child.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "bin_tree.h"

/*
	This function inserts a value into the tree given by head.
*/
void insert(int key, char val[], T_ENTRY *head) {
	
	// insert left
	if (head->key > key) {
		if (!head->has_l) {
			head->has_l = 1;
			T_ENTRY *new_entry = (T_ENTRY*) malloc(sizeof(T_ENTRY));
			new_entry->key = key;
			strcpy(new_entry->val, val);
			new_entry->has_l = new_entry->has_r = 0;
			head->l_child = new_entry;
		}
		// recursion
		else {
			insert(key, val, head->l_child);
		}
	}
	// insert right
	else {
		if (!head->has_r) {
			head->has_r = 1;
			T_ENTRY *new_entry = (T_ENTRY*) malloc(sizeof(T_ENTRY));
			new_entry->key = key;
			strcpy(new_entry->val, val);
			new_entry->has_l = new_entry->has_r = 0;
			head->r_child = new_entry;
		}
		// recursion
		else {
			insert(key, val, head->r_child);
		}	
	}
}

/*
	This function prints the tree given by head.
*/
void print(T_ENTRY *head) {

	printf("%s\n", head->val);
	if (head->has_l) {
		print(head->l_child);
	}
	if (head->has_r) {
		print(head->r_child);
	}
}

/*
	This function deletes the element with the fitting key in the 
	tree given by head.
*/
void delete(int key, T_ENTRY *head) {

	// delete in left child
	if (head->key > key) {
		delete(key, head->l_child);
	}
	// delete in right child
	else if (head->key < key) {
		delete(key, head->r_child);
	}
	// delete
	else {
		T_ENTRY *t_pointer = head;
		if (head->has_r) {
			head = head->r_child;
			
		}

	}
}

int main(void) {

	// initialize tree
	T_ENTRY *head = (T_ENTRY*) malloc(sizeof(T_ENTRY));
	head->has_l = 0;
	head->has_r = 0;
	int t_empty = 1;
	int key;
	char val[10];

	int request;
	int exit = 0;
	while (!exit) {
		printf("Press 1 to insert values, 2 to print tree, or 0 to exit: ");
		scanf("%d", &request);
		switch(request) {
			case 0: exit = 1; break;
			case 1:
				printf("Enter key: ");
				scanf("%d", &key);
				printf("Enter value: ");
				scanf("%s", val);
				if (t_empty) {
					t_empty = 0;
					strcpy(head->val, val);
				}
				else {
					insert(key, val, head);
				}
				break;
			case 2: print(head); break;
		}	
	}

	return 0;
}
