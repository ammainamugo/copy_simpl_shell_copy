#include "main.h"

/**
 * mem_byte - fills memory with a constant byte
 * @st: the pointer to the memory area
 * @byte: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (st) pointer to memory area
 */
char *mem_byte(char *st, char byte, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		st[a] = byte;
	return (st);
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
 * re_alloc - reallocates a block of memory
 * @ptr: pointer to previous mallocated block
 * @size: byte size of previous block
 * @size_new: byte size of new block
 * Return: pointer to new block
 */
void *re_alloc(void *ptr, unsigned int size, unsigned int size_new)
{
	char *p;

	if (!ptr)
		return (malloc(size_new));
	if (!size_new)
		return (free(ptr), NULL);
	if (size_new == size)
		return (ptr);

	p = malloc(size_new);
	if (!p)
		return (NULL);

	size = size < size_new ? size : size_new;
	while (size--)
		p[size] = ((char *)ptr)[size];
	free(ptr);
	return (p);
}
