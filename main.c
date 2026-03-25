#include <stdio.h>
#include <string.h>
#include "container.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s run <program>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "run") == 0) {
        run_container(argv[2], &argv[2]);
    }

    return 0;
}