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
        newNote(getArg(&ctx, "--title"));
    }
    if (hasArg(&ctx, "open")) {
        openNote(getArg(&ctx, "--title"));
    }
    
    saveNotes();
    return 0;
}