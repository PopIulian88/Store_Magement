void addItemToList(char listName[], char productName[], char productCantitate[], char productPret[])
{
    FILE *filePointer;

    int len = strlen(productName) + strlen(productCantitate) + strlen(productPret);
    char dataToWritte[len + 3];

    strcpy(dataToWritte, productName);
    strcat(dataToWritte, " ");
    strcat(dataToWritte, productCantitate);
    strcat(dataToWritte, " ");
    strcat(dataToWritte, productPret);

    filePointer = fopen(listName, "a");

    if(filePointer == NULL)
    {
        printf("Fail to open file");
    } else {
        
        if ( strlen ( dataToWritte ) > 0 )
        {
            fputs(dataToWritte, filePointer) ;
            fputs("\n", filePointer) ;
        }
         
        fclose(filePointer) ;
    }
}