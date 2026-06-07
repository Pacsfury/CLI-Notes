#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "../include/noteManager.h"

Vector titles;
Vector content;

void initNoteManager() {
    vec_init(&titles);
    vec_init(&content);
}

void newNote(char title[]) {
    vec_push(&titles, strdup(title));
    vec_push(&content, strdup("")); 
    printf("New note created\n");
}

void openNote(char title[]) {
    int index = vec_where(&titles, title);
    
    if (index == -1) {
        printf("Error: Note '%s' not found.\n", title);
        return;
    }

    char *noteTitle = vec_get(&titles, index);
    char *noteContent = vec_get(&content, index);

    printf("Title: %s\n", noteTitle);
    printf("Content: %s\n", noteContent);
}

void saveNotes() {
    FILE *file = fopen("notes.bin", "wb");
    if (file == NULL) {
        printf("Error: Could not save notes.\n");
        return;
    }

    int count = titles.size;
    fwrite(&count, sizeof(int), 1, file);

    for (int i = 0; i < count; i++) {
        char *t = vec_get(&titles, i);
        char *c = vec_get(&content, i);

        int t_len = strlen(t);
        int c_len = strlen(c);

        fwrite(&t_len, sizeof(int), 1, file);
        fwrite(t, sizeof(char), t_len, file);

        fwrite(&c_len, sizeof(int), 1, file);
        fwrite(c, sizeof(char), c_len, file);
    }

    fclose(file);
}

void loadNotes() {
    FILE *file = fopen("notes.bin", "rb");
    if (file == NULL) {
        return;
    }

    int count = 0;
    if (fread(&count, sizeof(int), 1, file) != 1) {
        fclose(file);
        return;
    }

    for (int i = 0; i < count; i++) {
        int t_len = 0;
        int c_len = 0;

        fread(&t_len, sizeof(int), 1, file);
        char *t_buf = malloc(t_len + 1);
        fread(t_buf, sizeof(char), t_len, file);
        t_buf[t_len] = '\0';

        fread(&c_len, sizeof(int), 1, file);
        char *c_buf = malloc(c_len + 1);
        fread(c_buf, sizeof(char), c_len, file);
        c_buf[c_len] = '\0';

        vec_push(&titles, t_buf);
        vec_push(&content, c_buf);
    }

    fclose(file);
}

void freeNoteManager() {
    for (int i = 0; i < titles.size; i++) {
        free(vec_get(&titles, i));
        free(vec_get(&content, i));
    }
    vec_free(&titles);
    vec_free(&content);
}
