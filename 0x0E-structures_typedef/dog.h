#ifndef DOG_H
#define DOG_H

/**
 * struct dog - dog structure with the following props
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Description: assign a name, age and owner to a dog object
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
