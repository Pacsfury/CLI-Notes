#include <stdio.h>
#include "../include/style.h"
#include "../include/status.h"
#include "../include/argc.h"
#include "../include/noteManager.h"

int main(int argc , char *argv[]) {
    loadNotes();

    ARGS_CONTEX ctx = { argc, argv };
    args_init(&ctx, argc, argv);

    if (hasArg(&ctx, "new")) {
        char *title = getArg(&ctx, "--title");
        if (title != NULL) {
            newNote(title);
        } else {
            logError("Error: Missing --title argument.\n");
        }
    }
    
    if (hasArg(&ctx, "open")) {
        char *title = getArg(&ctx, "--title");
        if (title != NULL) {
            openNote(title);
        } else {
            logError("Error: Missing --title argument.\n");
        }
    }
    
    if (hasArg(&ctx, "edit")) {
        char *title = getArg(&ctx, "--title");
        char *cont = getArg(&ctx, "--cont");
        
        if (title != NULL && cont != NULL) {
            editNote(title, cont);
        } else {
            logError("Error: Missing --title or --cont arguments.\n");
        }
    }
    
    if (hasArg(&ctx, "delete")) {
        char *title = getArg(&ctx, "--title");
        if (title != NULL) {
            deleteNote(title);
        } else {
            logError("Error: Missing --title argument.\n");
        }
    }

    if (hasArg(&ctx, "list")) {
        listNotes();
    }

    saveNotes();
    freeNoteManager();
    return 0;
}
