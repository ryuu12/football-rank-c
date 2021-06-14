#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Base of user account structure
struct userAccount
{
    char username[50];
    char password[50];
};

//Base of club data structure
struct club
{
    char name[50];
    char country[50];
    char division[50];
    int trophy;
};

void createAccount(void);
void login(void);
void menu(void);

int main(void)
{
    int n;

    //The first menu for user to choose, wehther they want to make a new account or already have an account
    printf("Type '1' for register.\nType '2' for login.\n");
    scanf("%d", &n); fflush(stdin);

    if(n == 1)
    {
        //To create account
        system("cls");
        createAccount();
    }
    else if(n == 2)
    {
        //Directly login
        system("cls");
        login();
    }
}

void createAccount()
{
    FILE *account;

    account=fopen("account.txt","w");//It creates a new file called account.txt to store the user data
    if (account == NULL)
    {
        fputs("No such file exist!", stderr);
        exit(1);
    }
    
    struct userAccount userData;

    //Inputting the data
    printf("Register\n");
    printf("Username: "); fgets(userData.username,50,stdin); 
    printf("Password: "); fgets(userData.password,50,stdin); 
    fwrite(&userData, sizeof(userData),1,account);
    fclose(account);

    system("cls");
    main();
}

void login()
{
    char username[50], password[50];
    FILE *data;

    struct userAccount userData;

    //Inputting the data to be compared afterwards
    printf("Login\n");
    printf("Username: "); fgets(username,50,stdin);
    printf("Password: "); fgets(password,50,stdin);

    data = fopen("account.txt","r");
    if(data == NULL)
    {
        fputs("No such data exist", stderr);
        createAccount();
    }

    //Comparing the data from the input with account.txt
    while(fread(&userData, sizeof(userData),1,data));
    {
        if(strcmp(username, userData.username)==0 && strcmp(password, userData.password)==0)
        {
            printf("login success.\n");
            menu();
        }
        else
        {
            //If the user doesn't have any account stored in account.txt, they'll directed to create account page
            printf("Your account is not registered.\n");
            createAccount();
        }
    }
}

//This program main feature
void menu()
{
    system("cls");

    int n;

    printf("[Football Ranking Program]\n\n");
    printf("Number of club: "); scanf("%d", &n); fflush(stdin);

    struct club c[n];

    //Inputting all club data.
    for (int i = 0; i < n; i++)
    {
        printf("%d of %d\n", i+1, n);
        printf("Name: "); fflush(stdin); fgets(c[i].name,50,stdin);
        printf("Country: "); fgets(c[i].country,50,stdin);
        printf("Division: "); fgets(c[i].division,50,stdin);
        printf("Trophy: "); scanf("%d", &c[i].trophy); 
    }

    //Showing the data before it's sorted
    printf("\n[Your Data]\n");
    for (int i = 0; i < n; i++)
    {   
        printf("\n[%d]\n", i+1);
        printf("Name: %s\nCountry: %s\nDivision: %s\nTrophy: %d\n", c[i].name, c[i].country, c[i].division, c[i].trophy);
    }

    int x;
    printf("\nData stored successfully.\n");
    printf("Type '1' to start sorting...\n"); scanf("%d", &x); //Confirming for the data to be sorted

    //Sorting using bubble sort
    if (x == 1)
    {
        int j;
        struct club temp;

        for (int i = 0; i < n; i++)
        {
            for (j = 0; j < n-1-i; j++)
            {
                if (c[j].trophy < c[j+1].trophy)
                {
                    //Moving the data for sorting
                    temp = c[j]; 
                    c[j] = c[j+1];
                    c[j+1] = temp;
                }
                
            }
            
        }    
    }
    
    //The data after being sorted
    printf("\n");
    printf("\n[Your Data]\n");
    for (int i = 0; i < n; i++)
    {   
        printf("\n[%d]\n", i+1);
        printf("Name: %s\nCountry: %s\nDivision: %s\nTrophy: %d\n", c[i].name, c[i].country, c[i].division, c[i].trophy);
    }
}

