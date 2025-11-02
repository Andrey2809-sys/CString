#include "../include/str.h"

int main()
{
    string_t str1 CLEANUP;
    string_init(&str1);
    
    string_t str2 CLEANUP = string_from_cstr("Hello");
    string_t str3 CLEANUP = string_from_cstr(" World");
    
    append(&str2, &str3);
    printf("Result: %s\n", str2.data);  // Должно быть "Hello World"
    
    string_t str = string_from_cstr("hello");
    char *cstr = "hello";

    bool result = string_compare(&str, cstr);
    printf("%d\n", result); 
    
    return 0;
}