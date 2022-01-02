#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct { 
    char name [MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];

// Constructing hash function
unsigned int hash(char *name) {

    int i, length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for (i=0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

// Initializing hash table
void init_hash_table() {

    int i;
    
    for (i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

// Printing out hash table
void print_table() {

    int i;

    printf("Start\n");

    for (i=0; i < TABLE_SIZE; i++) {
        
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }

    printf("End\n");
}

bool hash_table_insert(person *p) {
    int i, try, index;

    if (p == NULL) return false;

    index = hash(p->name);

    for (i=0; i<TABLE_SIZE; i++) {
        try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL ||
            hash_table[try] == DELETED_NODE) 
            {
                hash_table[try] = p;
                return true;
        }
    }

    return false;
}

// Finding a person in the table by their name
person *hash_table_lookup(char *name) {

    int i, try, index; 

    index = hash(name);

    for (i=0; i<TABLE_SIZE; i++) {
        try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) {
            return false;
        }
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, MAX_NAME)==0) {
            return hash_table[try];
        }
    }

    return NULL;
}

person *hash_table_delete(char *name) {

    int i, try, index;
    person *tmp;

    index = hash(name);

    for (i=0; i<TABLE_SIZE; i++) {
        try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, MAX_NAME)==0) {
            tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }

    return NULL;
}

int main() {

    init_hash_table();
    print_table();

    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="kate", .age=27};
    person mpho = {.name="Mpho", .age=14};
    person sarah = {.name="Sarah", .age=54};
    person edna = {.name="Edna", .age=15};
    person maren = {.name="Maren", .age=25};
    person eliza = {.name="Eliza", .age=34};
    person robert = {.name="Robert", .age=1};
    person jane = {.name="Jane", .age=75};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);

    print_table();

    person *tmp = hash_table_lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("George");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    hash_table_delete("Mpho");
    tmp = hash_table_lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    print_table();

    return 0;
}

