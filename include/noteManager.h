#pragma once
#include <stdio.h>
#include <stdlib.h>

void initNoteManager();

void newNote(char title[]);

void openNote(char title[]);

void saveNotes();

void loadNotes();

void freeNoteManager();
