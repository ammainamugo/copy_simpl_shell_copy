#include "main.h"

/**
 * set_mem - fills memory with constant byte
 * @p: pointer to the memory area
 * @byte: byte to fill *p with
 * @b: amount of bytes to fill
 * Return: pointer to memory area
 */
char *set_mem(char *p, char byte, unsigned int b)
{
	unsigned int a;

	for (a = 0; a < b; a++)
		p[a] = byte;
	return (p);
}

/**
 * free_str - frees string of strings
 * @p_st: string of strings
 */
void free_str(char **p_st)
{
	char **s = p_st;

	if (!p_st)
		return;
	while (*p_st)
		free(*p_st++);
	free(s);
}

/**
 * free_p - frees pointer and NULLs address
 * @p: address of pointer to free
 * Return: 1 if freed, otherwise 0.
 */
int free_p(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}


/**
 * re_alloc - reallocates a block of memory
 * @p: pointer to previous mallocated block
 * @size: byte size of previous block
 * @size_new: byte size of new block
 * Return: pointer to new block
 */
void *re_alloc(void *p, unsigned int size, unsigned int size_new)
{
	char *r;

	if (!p)
		return (malloc(size_new));
	if (!size_new)
		return (free(p), NULL);
	if (size_new == size)
		return (p);

	r = malloc(size_new);
	if (!r)
		return (NULL);
	size = size < size_new ? size : size_new;
	while (size--)
		r[size] = ((char *)p)[size];
	free(p);
	return (r);
}
