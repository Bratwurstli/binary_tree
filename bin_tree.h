#ifndef __BIN_TREE_H
#define __BIN_TREE_H

typedef struct t_entry {

	int key;
	// the value to store is a string, max size is 10 chars
	char val[10];
	// integer to check if an entry has a child
	int has_l;
	int has_r;
	struct t_entry *l_child;
	struct t_entry *r_child;
} T_ENTRY;

#endif
