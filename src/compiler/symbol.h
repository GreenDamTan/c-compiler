#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX_SLOTS 10000  /**> Total number of identifiers possible in memory */
#define EMPTY_SLOT -1    /**> This symbolic constant signifies empty slots in the hash map. */

typedef struct record_TAG{
	int addr;
	char type;
	char name[64];
	char *value;
	int slot;         /**> Either EMPTY_SLOT or NOT_EMPTY */
	char *scope;
}record;

typedef struct symbol_table_TAG {
	/* Public Fields */
	double load_factor;
	size_t in_use;
	size_t size;
	record *table;
	
	/* Public Methods */
} symbol_table;

/**
 */
void print_stab(symbol_table *stab);

/**
 */
symbol_table *create_stab(size_t max);

/**
 */
void stab_insert(record *rec, symbol_table *stab);

/**
 */
record *get_record(char *name, char*val, char type, int slot, char *scope);

/**
 */
void purge_record(record *rec);

/**
 */
size_t hash(char *key, size_t limit);




#endif