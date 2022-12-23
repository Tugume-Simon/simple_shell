#include "shell.h"

/**
 * _getline - reads line of characters from stream
 * up to null character and does not append newline
 * character at the end. If used in a loop, no need
 * to free memory.
 *
 * @lineptr: address of pointer to buffer that will
 * store the read string.
 * @n: size of the buffer.
 * @stream: stream
 *
 * Return: On success, number of characters that are read
 * On failure, -1.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char c;
	unsigned int i;

	if (*lineptr != NULL)
	{
		free(*lineptr);
		*lineptr = NULL;
	}
	if (stream == NULL)
		return (-1);

	*n = 1;
	i = 0;

	while ((c = getc(stream)) != '\n')
	{
		if (c == EOF)
			return (EOF);
		*lineptr = realloc(*lineptr, sizeof(char) * (i + 1));
		(*lineptr)[i] = c;
		(*n)++;
		i++;
	}
	if (i == 0)
	{
		*lineptr = realloc(*lineptr, sizeof(char) * (i + 1));
		(*lineptr)[i] = '\n';
	}

	return (*n);
}
