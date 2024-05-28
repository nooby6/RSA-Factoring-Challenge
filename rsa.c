#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(unsigned long num)
{
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (unsigned long i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

/**
 * main - Entry point for RSA factorization
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

    if ((read = getline(&line, &len, file)) != -1)
    {
        n = strtoul(line, NULL, 10);
        for (p = 2; p * p <= n; p++)
        {
            if (n % p == 0)
            {
                q = n / p;
                if (is_prime(p) && is_prime(q))
                {
                    printf("%lu=%lu*%lu\n", n, p, q);
                    break;
                }
            }
        }
    }

    free(line);
    fclose(file);
    return (0);
}

