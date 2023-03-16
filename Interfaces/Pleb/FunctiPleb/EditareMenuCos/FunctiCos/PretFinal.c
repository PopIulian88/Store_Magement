
double pretFinal(char listaCurenta[])
{
    int count = 0;
    double contorPretFinal = 0.0;

    FILE *filePointer;

    char data[100];
    filePointer = fopen(listaCurenta, "r");

    if(filePointer == NULL)
    {
        printf("Fail to open file");
    }else{
        while(fgets(data, 100, filePointer))
        {
            if(count > 0) // Trecem de cazu BACK
            {
                char *oldName = strtok(data, " ");
                char *oldCantitate = strtok(NULL, " ");
                char *oldPret = strtok(NULL, "\n");

                contorPretFinal += atof(oldPret);
            }
            count++;
        }
        fclose(filePointer);
    }

    return contorPretFinal;
}