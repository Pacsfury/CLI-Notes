#pragma once
#include <stdio.h>
#include <stdlib.h>

void initNoteManager();

void newNote(char title[]);

void openNote(char title[]);

void editNote(char title[], char content[]);

void deleteNote(char title[]);

void listNotes();

void saveNotes();

void loadNotes();

void freeNoteManager();
