#include "scan.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void scan_path(const char *root, Database *db) {
    struct stat st; // File status information

    // Get file status
    if (lstat(root, &st) == -1) {
        fprintf(stderr, "Error: lstat('%s') failed: %s\n", root, strerror(errno));
        return;
    }

    if (S_ISDIR(st.st_mode)) {
        // It's a directory, open it
        DIR *dir = opendir(root);
        if (!dir) {
            fprintf(stderr, "Error: opendir('%s') failed: %s\n", root, strerror(errno));
            return;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            // Skip "." and ".." entries
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Construct the full path for the entry
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", root, entry->d_name);

            // Recursively scan the entry
            scan_path(path, db);
        }

        closedir(dir);
    } else if (S_ISREG(st.st_mode)) {
        // It's a regular file, add to database
        Entry e = {0};
        // Extract directory and file name from the path
        const char *last_slash = strrchr(root, '/');
        if (last_slash) {
            size_t dir_len = last_slash - root;
            if (dir_len >= sizeof(e.dir)) dir_len = sizeof(e.dir) - 1;
            strncpy(e.dir, root, dir_len);
            e.dir[dir_len] = '\0';
            strncpy(e.file, last_slash + 1, sizeof(e.file) - 1);
        } else {
            // No directory part in the path
            strncpy(e.file, root, sizeof(e.file) - 1);
        }

        db_add(db, e);
    } else {
        // Not a regular file or directory; ignore other types (symlinks, devices, etc.)
        fprintf(stderr, "Warning: '%s' is not a regular file or directory; skipping.\n", root);
    }

}