#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    char *my_string = (char *)malloc(15 * sizeof(char));

    if (my_string == NULL)
    {
        printf("There was a problem allocating memory\n");
        return 1;
    }

    strcpy(my_string, "Hello,World");

    printf("Malloc result string ! : %s\n",my_string);

    free(my_string);

    return 0;
}