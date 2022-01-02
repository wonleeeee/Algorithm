#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person { 
    char name [MAX_NAME];
    int age;
    struct person *next;
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
    person *tmp;

    printf("Start\n");

    for (i=0; i < TABLE_SIZE; i++) {
        
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t", i);
            tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }

    printf("End\n");
}

bool hash_table_insert(person *p) {

    int index;

    if (p == NULL) return false;

    index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;

    return true;
}

// Finding a person in the table by their name
person *hash_table_lookup(char *name) {

    int index; 
    person *tmp;

    index = hash(name);

    tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        tmp = tmp->next;
    }

    return tmp;
}

person *hash_table_delete(char *name) {

    int index; 
    person *tmp, *prev = NULL;

    index = hash(name);
    tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL) {
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    return tmp;
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

    // person *tmp = hash_table_lookup("Mpho");
    // if (tmp == NULL) {
    //     printf("Not found!\n");
    // } else {
    //     printf("Found %s.\n", tmp->name);
    // }

    // tmp = hash_table_lookup("George");
    // if (tmp == NULL) {
    //     printf("Not found!\n");
    // } else {
    //     printf("Found %s.\n", tmp->name);
    // }

    hash_table_delete("Jacob");
    // tmp = hash_table_lookup("Mpho");
    // if (tmp == NULL) {
    //     printf("Not found!\n");
    // } else {
    //     printf("Found %s.\n", tmp->name);
    // }

    print_table();

    return 0;
}

