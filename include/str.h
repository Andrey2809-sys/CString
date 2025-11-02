#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CLEANUP __attribute__((cleanup(string_destroy)))

#define BASIC_CAPACITY 10

typedef struct string_t {
    char *data;
    size_t  size;
    size_t  capacity;
} __attribute__((aligned)) string_t;


// Phase 1. Basic structure
void     string_init(string_t *src);
string_t string_from_cstr(const char *data);
void     string_destroy(string_t *str);


// Phase 2. Main operations
void      append(string_t *dest, const string_t *src);
int       find(string_t str, char *word);

bool      string_compare(string_t *src, char *data);

void      string_clear(string_t *str);
char      string_at(string_t *src, int pos);

// Phase 3. Format
bool      string_empty(string_t *src);
char     *string_c_str(string_t *src);
void      string_hash(string_t *src, int key);

// Some help functions
void    printstr(string_t *str);
size_t  string_len(string_t *str);
