
void putBacktoList(char listName[], char productName[], char productCantitate[], char productPret[])
{
    //Cautam in fisier daca mai exista un produs cu acest nume

    int count = 0, corect = 0, flag = 1; 

    FILE *pointer;
    char data[100], cantitateFinala[100000]; //Punem un vector nou de cantitate deoarece are o problema daca folosim valorile din declaratie
    pointer = fopen(listName, "r");

    if(pointer == NULL)
    {
        printf("Fail to open file");
    }else{
        while(flag && fgets(data, 100, pointer))
        {

            char *oldNameAux = strtok(data, " ");
            char *oldCantitateAux = strtok(NULL, " ");
            char *oldPretAux = strtok(NULL, "\n");
            

            if(strcmp(productName, oldNameAux) == 0) // Cand gasim un nume identic
            {

                corect = count;
                
                int intProductCantitate = atoi(productCantitate); 
                float floatProductPret = atof(oldPretAux);

                intProductCantitate = intProductCantitate + atoi(oldCantitateAux);  //adaugam cate erau deja in cos la cate vrem sa adaugam
                //floatProductPret += atof(oldPret);

                sprintf(cantitateFinala, "%d", intProductCantitate); //copiem in cantitateFinala, cantitatea final calculata
                sprintf(productPret, "%.2f", floatProductPret);

                flag = 0;
                count--; //deoarece creste pe urmatoarea linie
            }
            count++;
        }
        fclose(pointer);
    }

    addItemToList(listName, productName, cantitateFinala, productPret); // Adaug in lista elementul

    if(corect > 0) //cazul in care gasim nume identic
    {
        deleteItemFromList(listName, count);// stergem din lista elementul pe care vrem sa il adaugam       
    }

}