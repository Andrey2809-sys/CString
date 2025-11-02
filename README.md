# Simple String Library for C

A easy-to-use string library for C programming language.

## What it does

- 🚀 Lightweight - only basic string functions
- 🛡️ Safe memory with auto-cleanup
- 📚 Simple API - easy to learn
- 🔧 Works with normal C strings

## Quick Start

main.c:

#include "include/str.h"
#include <stdio.h>

int main() {
    // Auto memory cleanup
    CLEANUP string_t str = string_from_cstr("Hello");
    
    CLEANUP string_t world = string_from_cstr(" World");
    append(&str, &world);
    
    printstr(&str); // "Hello World"
    
    return 0;
    // Memory freed automatically!
}

# Build commands
- `make clean` - clean build
- `make` - compile  
- `make run` - run examples
