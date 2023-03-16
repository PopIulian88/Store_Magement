
void recreazaFisier(char numeleFisierului[])
{
    remove(numeleFisierului); //Stergem fisierul actual

    FILE *pointer;

    pointer = fopen(numeleFisierului, "w"); // Creem un nou fisier cu acelasi nume
        fprintf(pointer, "BACK\n");  // Adaugam BACK
    fclose(pointer); //Inchidem fisierul
}