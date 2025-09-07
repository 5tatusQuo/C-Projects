#include "phalanx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Database mkdatabase(size_t cap) {
    Database db;
    db.cap = cap;
    db.size = 0;

    // Allocate memory for 'cap' entries
    db.entries = malloc(cap * sizeof(Entry));

    if (db.entries == NULL) {
        db.cap = 0; // allocation failed
    } else {
        memset(db.entries, 0, cap * sizeof(Entry)); // Set all bytes of entries to 0
    }

    return db;
}

void addtodb(Database *db, Entry e) {
    // if db.size is less than db.cap
    if (db->size < db->cap) {
        // Insert entry at curent size, then increment size
        db->entries[db->size++] = e;
    }

    // TODO: Do we increase cap size if we reach it?
}

void destroydb(Database *db) {
    free(db->entries);
    db->entries = NULL;
    db->cap = 0;
    db->size = 0;
}

void showdb(Database *db) {
    printf("Cap:\t%zu\nSize:\t%zu\n", db->cap, db->size);

    return;
}

int main(int argc, char *argv[]) {
    Database db;
    Entry e1, e2;

    db = mkdatabase(50000);
    showdb(&db);
    destroydb(&db);

    return 0;
}