// file.h
#ifndef FILE_H
#define FILE_H

extern int saveCount;
extern int loadCount;

void saveArrayToFile(int array[], int size, const char *filename);
void loadArrayFromFile(int array[], int size, const char *filename);

#endif // FILE_H
