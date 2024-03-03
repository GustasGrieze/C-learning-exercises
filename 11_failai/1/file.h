// file.h
#ifndef FILE_H
#define FILE_H

#include <stdlib.h>

void saveToFile(const char* filename, const int* array, size_t size);
int* loadFromFile(const char* filename, size_t* size);

#endif // FILE_H
