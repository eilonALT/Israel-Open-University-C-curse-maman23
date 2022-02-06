/*
    ---------------------------------------------------- Maman: 23 ----------------------------------------------------------
  ------------------------------------------------------ Name: Eilon Alter --------------------------------------------------
 ------------------------------------------------------- ID: 208500603 -----------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;
    int i;

    int n = atoi(argv[1]); /* get n from args */

    FILE *file;
    int fileSize;

    if (argc < 3)
    { /*not enough args */
        printf("There are not enough arguments!!!\n");
        return (1);
    }

    for (i = 2; i < argc; i++)
    {
        file = fopen(argv[i], "r");

        if (file == NULL)
        { /* if file not found */
            printf("%s: Could not find the requsted file file\n", argv[i]);
            continue;
        }

        fseek(file, 0, SEEK_END);
        fileSize = ftell(file);

        if (fileSize < n)
        { /* if file chars is less than n */
            printf("%s: There are not enough chars in this file\n", argv[i]);
            fclose(file);
            continue;
        }

        fseek(file, n - 1, SEEK_SET);
        c = fgetc(file);
        printf("%s: %d \n", argv[i], c);
        fclose(file);
    }
    return (0);
}