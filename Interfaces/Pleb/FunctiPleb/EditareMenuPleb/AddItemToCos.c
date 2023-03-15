

void addItemToCos(char listName[], char productName[], char productCantitate[], char productPret[])
{
    //Cautam in fisier daca mai exista un produs cu acest nume
    int count = 0, corect = 0, flag = 1; 

    FILE *pointer;
    char data[100];
    pointer = fopen(listName, "r");

    if(pointer == NULL)
    {
        printf("Fail to open file");
    }else{
        while(fgets(data, 100, pointer) && flag)
        {
            char oldSir[100000]; // functia va returna un sir, linia actuala
            getPositionInfo(listName, count, oldSir);

            char *oldName = strtok(oldSir, " ");
            char *oldCantitate = strtok(NULL, " ");
            char *oldPret = strtok(NULL, "\n");

            if(strcmp(productName, oldName) == 0) // daca gasim un nume identic nu e ok
            {
                corect = count;

                int intProductCantitate = atoi(productCantitate); 
                float floatProductPret = atof(productPret);

                intProductCantitate += atoi(oldCantitate);  //adaugam cate erau deja in cos la cate vrem sa adaugam
                floatProductPret += atof(oldPret);

                sprintf(productCantitate, "%d", intProductCantitate);
                sprintf(productPret, "%.2f", floatProductPret);
                flag = 0;
                count--; //deoarece creste pe urmatoarea linie
            }
            count++;
        }
        fclose(pointer);
    }

    if(corect > 0) //cazul in care gasim nume identic
    {
        deleteItemFromList(listName, count);// stergem din lista elementul pe care vrem sa il adaugam       
    }

    addItemToList(listName, productName, productCantitate, productPret);

}