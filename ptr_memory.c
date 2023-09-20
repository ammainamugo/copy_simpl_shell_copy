#include "main.h"

/**
 * freeAndNullPointer - function to free a pointer memory and sets it to NULL
 * @ptr: Address of the pointer to free
 *
 * This function frees the memory allocated for the pointer pointed to by 'ptr'
 * and sets 'ptr' to NULL to avoid any dangling pointers.
 *
 * Return: 1 if the pointer was successfully freed, otherwise 0
 */

int freeAndNullPointer(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return (1);
    }
    return (0);
}
