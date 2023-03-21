#include "dog.h"
#include <string.h>

/**
 * init_dog - initial a variable of type struct dog
 * @d: pointer to the struct dog
 * @name: name to initialize struct with
 * @age: age to initialize struct with
 * @owner: onwer to initialize struct with
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = strdup(name);
	d->age = age;
	d->owner = strdup(owner);
}
