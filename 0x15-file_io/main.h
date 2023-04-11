#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);

#endif /* MAIN_H */
