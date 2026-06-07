#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "../include/noteManager.h"

Vector titles;
Vector content;

void initNoteManager() {
    vec_init(&titles);
    vec_init(&content);
}

void newNote(char title[]) {
    vec_push(&titles, title);
    vec_push(&content, "");
    printf("New note created\n");
}
