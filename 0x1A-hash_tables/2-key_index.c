#include "hash_tables.h"

/**
 * key_index - generate an index from a given key within hash table
 * @key: key of the hash table
 * @size: size of the hash table
 *
 * Return: index of the given key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
