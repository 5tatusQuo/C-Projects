#ifndef SCAN_H
#define SCAN_H

#include "db.h"

// Recursively scan path (file or directory)
// Add any detections into db
void scan_path(const char *root, Database *db);

#endif