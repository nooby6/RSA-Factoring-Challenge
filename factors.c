#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for factorizing numbers into two smaller numbers
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long n, p, q;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        n = strtoul(line, NULL, 10);
        for (p = 2; p * p <= n; p++)
        {
            if (n % p == 0)
            {
                q = n / p;
                printf("%lu=%lu*%lu\n", n, p, q);
                break;
            }
        }
    }

    free(line);
    fclose(file);
    return (0);
}
