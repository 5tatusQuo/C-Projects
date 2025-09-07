#include "db.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Database db_make(size_t cap) {
    Database db = {0};
    db.cap = cap;
    db.entries = malloc(cap * sizeof(Entry));
    if (!db.entries) { db.cap = 0; return db; }
    memset(db.entries, 0, cap * sizeof(Entry));
    return db;
}

void db_add(Database *db, Entry e) {
    if (db && db->size < db->cap) db->entries[db->size++] = e;
}

void db_free(Database *db) {
    if (!db) return;
    free(db->entries);
    db->entries = NULL;
    db->cap = db->size = 0;
}

void db_show(const Database *db) {
    if (!db) return;
    printf("Cap:\t%zu\nSize:\t%zu\n", db->cap, db->size);

    for (size_t i = 0; i < db->size; i++) {
        printf("%zu: %s/%s\n", i, db->entries[i].dir, db->entries[i].file);
    }
}