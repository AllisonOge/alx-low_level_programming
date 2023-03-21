#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - creates a new dog struct
 * @name: name of new dog
 * @age: age of new dog
 * @owner: owner of new dog
 *
 * Return: pointer to new dog struct if no errors otherwise NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ptrDog;

	/* allocate memory for new dog */
	ptrDog = malloc(sizeof(dog_t));
	if (ptrDog == NULL)
		return (NULL);

	/* allocate memory for name and owner strings */
	ptrDog->name = strdup(name);
	if (ptrDog->name == NULL)
	{
		free(ptrDog);
		return (NULL);
	}

	ptrDog->age = age;

	ptrDog->owner = strdup(owner);
	if (ptrDog->owner == NULL)
	{
		free(ptrDog->name);
		free(ptrDog);
		return (NULL);
	}

	return (ptrDog);
}
