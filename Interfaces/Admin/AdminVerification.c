#define PASSWORD "NDDIDP"

boolean adminVerification()
{
    system("CLS");

    char incercare[10];

    printf("Password: ");
    scanf("%s", &incercare); // Citim de la tastatura posibila pasola
    
    if(strlen(incercare) == strlen(PASSWORD)) // Daca parola citita este la fel de mare 
    {                                         // ca cea corecta
        for(int i = 0; i < strlen(PASSWORD); i++) // Verificam caracter cu caracter
        {
            if(incercare[i] != PASSWORD[i]) // Daca gasim un caracter diferit => FALSE
                return FALSE;
        }
        return TRUE;    //Daca toate caracterele se potrivesc => TRUE
    }
    return FALSE;
}