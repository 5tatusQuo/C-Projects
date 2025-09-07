#include "phalanx.h"
#include <string.h>

int main(void) {
    Database db = db_make(50000);

    Entry e1 = {0}, e2 = {0};
    strcpy(e1.dir,  "documents");
    strcpy(e1.file, "notes.txt");
    strcpy(e2.dir,  "downloads");
    strcpy(e2.file, "installer.exe");

    db_add(&db, e1);
    db_add(&db, e2);
    db_show(&db);

    db_free(&db);
    return 0;
}