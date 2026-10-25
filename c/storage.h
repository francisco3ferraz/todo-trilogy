#ifndef STORAGE_H
#define STORAGE_H

#include "todo.h"

int storage_load(TODO *todos);
int storage_save(TODO *todos, int numTODOS);

#endif
