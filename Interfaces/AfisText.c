#include <stdio.h>

int afisFile(char fileName[], int curentPosition)
{
    int count = 0;
    FILE *pointer;
    char data[100];
    pointer = fopen(fileName, "r");

    if(pointer == NULL)
    {
        printf("Fail to open file");
    }else{
        while(fgets(data, 100, pointer))
        {
            if(curentPosition == count)
                printf(" >> ");
            printf("%s", data);
            count++;
        }
        fclose(pointer);
    }
    return count;
}