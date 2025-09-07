#include "phalanx.h"
#include "scan.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    Database db = db_make(50000);
    scan_path(argv[1], &db);
    db_show(&db);
    db_free(&db);

    return 0;
}