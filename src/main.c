#include <stdio.h>
#include "../include/style.h"
#include "../include/status.h"
#include "../include/argc.h"

int main(int argc , char *argv[]) {
         
    ARGS_CONTEX ctx = { argc, argv };
    args_init(&ctx, argc, argv);

    if (hasArg(&ctx, "new")) {
        newNote(getArg(&ctx, "--title"));
    }
    
    return 0;
}