#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vec_init(Vector *v) {
    v->size = 0;
    v->capacity = 4;
    v->data = (char **)malloc(v->capacity * sizeof(char *));
}

void vec_push(Vector *v, char *value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (char **)realloc(v->data, v->capacity * sizeof(char *)); 
    }
    v->data[v->size++] = value;
}

void vec_replace(Vector *v, int index, char *value) { 
    if (index >= 0 && index < v->size) {
        v->data[index] = value;
    }
}

void vec_free(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
