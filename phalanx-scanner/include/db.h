#ifndef DB_H
#define DB_H
#include <stdint.h>
#include <stddef.h>

typedef char Dir[64];  // Define Dir as an array of 64 signed 8-bit integers (for directory name/path).
typedef char File[32];

typedef struct s_entry {
    Dir dir;   // A string buffer (64 bytes).
    File file;
} Entry; // Define a struct type s_entry, then typedef it to Entry.

typedef struct s_database {
    Entry *entries;  // Pointer to a dynamically allocated array of Entry objects.
    size_t cap;
    size_t size;
} Database;

Database db_make(size_t cap);
void db_add(Database *db, Entry e);
void db_free(Database *db);
void db_show(const Database *db);

#endif