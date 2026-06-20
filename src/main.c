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
            printf("Error: Missing --title argument.\n");
        }
    }
    
    if (hasArg(&ctx, "open")) {
        char *title = getArg(&ctx, "--title");
        if (title != NULL) {
            openNote(title);
        } else {
            printf("Error: Missing --title argument.\n");
        }
    }
    
    if (hasArg(&ctx, "edit")) {
        char *title = getArg(&ctx, "--title");
        char *cont = getArg(&ctx, "--cont");
        
        if (title != NULL && cont != NULL) {
            editNote(title, cont);
        } else {
            printf("Error: Missing --title or --cont arguments.\n");
        }
    }
    
    saveNotes();
    freeNoteManager();
    return 0;
}
