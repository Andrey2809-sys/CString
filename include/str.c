#include "str.h"

// Phase 1. Basic structure
void string_init(string_t *src)
{
    src->data = (char*)malloc(sizeof(char) * BASIC_CAPACITY);
    if (src->data == NULL) {
        perror("[ERROR] can't init string(malloc)");
        return;
    }
    src->data[0] = '\0'; 
    src->size = 0;
    src->capacity = BASIC_CAPACITY;
}

string_t string_from_cstr(const char *data)
{
    string_t str;
    size_t len = strlen(data);
    str.size = len;
    str.capacity = len + 1;
    str.data = (char*)malloc(str.capacity);

    if (str.data) {
        memcpy(str.data, data, len + 1);
    } else {
        str.size = 0;
        str.capacity = 0;
    }

    return str;
}

void string_destroy(string_t *str)
{
    if (str) {
        free(str->data);
        str->data = NULL;
        str->size = 0;
        str->capacity = 0;
    }
}


void append(string_t *dest, const string_t *src)
{
    if (dest == NULL || src == NULL || dest->data == NULL || src->data == NULL) {
        return;
    }

    if (dest->capacity < dest->size + src->size + 1) {
        size_t new_capacity = dest->size + src->size + 1;
        char *new_data = (char*)realloc(dest->data, new_capacity);
        if (new_data == NULL) {
            perror("[ERROR] can`t realloc data");
            return;
        };
        dest->data = new_data;
        dest->capacity = new_capacity;
    }

    memcpy(dest->data + dest->size, src->data, src->size);
    dest->size += src->size;
    dest->data[dest->size] = '\0';
}

int find(string_t str, char *word)
{
    if ((str.data == NULL)||(word == NULL)) return -1;

    int str_len = strlen(str.data);
    int word_len = strlen(word);
    int j;
    
    for (int i = 0; i <= str_len - word_len; i++) {
        for (j = 0; j < word_len; j++) {
            if (str.data[i + j] != word[j]) {
                break;
            }
        }
        
        if (j == word_len) {
            return i;
        }
    }
    return -1; 
}




bool string_compare(string_t *src, char *data)
{
    return strcmp(src->data, data) == 0;
}

bool string_empty(string_t *src)
{
    return ((src == NULL)||(src->size == 0)||(src->data[0] == '\0'));
}

char *string_c_str(string_t *src)
{
    return (char*)(src->data);
}

void string_clear(string_t *str)
{
    if (str && str->data) {
        str->size = 0;
        str->data[0] = '\0';
    }
}

char string_at(string_t *src, int pos)
{
    return (char)(*(src->data + pos));
}





// Some help functions
void printstr(string_t *str)
{
    printf("%s", str->data);
}

size_t string_len(string_t *str)
{
    return strlen(str->data);
}
