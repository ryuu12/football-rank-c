#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct userAccount
{
    char username[50];
    char password[50];
};

struct club
{
    char name[50];
    int trophy;
};

void createAccount(void);
void login(void);
void menu(void);

int main(void)
{
    int n;

    printf("Type '1' for register.\nType '2' for login.\n");
    scanf("%d", &n); fflush(stdin);

    if(n == 1)
    {
        system("cls");
        createAccount();
    }
    else if(n == 2)
    {
        system("cls");
        login();
    }
}

void createAccount()
{
    FILE *account;

    account=fopen("account.txt","w+");
    if (account == NULL)
    {
        fputs("No such file exist!", stderr);
        exit(1);
    }
    
    struct userAccount userData;

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

    printf("Login\n");
    printf("Username: "); fgets(username,50,stdin);
    printf("Password: "); fgets(password,50,stdin);

    data = fopen("account.txt","r");
    if(data == NULL)
    {
        fputs("No such data exist", stderr);
        createAccount();
    }

    while(fread(&userData, sizeof(userData),1,data));
    {
        if(strcmp(username, userData.username)==0 && strcmp(password, userData.password)==0)
        {
            printf("login success.\n");
            menu();
        }
        else
        {
            printf("Your account is not registered.\n");
            createAccount();
        }
    }
}

void menu()
{
    system("cls");

    int n;

    printf("[Football Ranking Program]\n\n");
    printf("Number of club: "); scanf("%d", &n); fflush(stdin);

    struct club c[n];

    for (int i = 0; i < n; i++)
    {
        printf("%d of %d\n", i+1, n);
        printf("Name: "); fflush(stdin); fgets(c[i].name,50,stdin);
        printf("Trophy: "); scanf("%d", &c[i].trophy); 
    }

    printf("\n[Your Data]\n");
    for (int i = 0; i < n; i++)
    {   
        printf("[%d]\n", i+1);
        printf("Name: %s\nTrophy: %d\n", c[i].name, c[i].trophy);
    }

    int x;
    printf("\nData stored successfully.\n");
    printf("Type '1' to start sorting...\n"); scanf("%d", &x);

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
                    temp = c[j];
                    c[j] = c[j+1];
                    c[j+1] = temp;
                }
                
            }
            
        }    
    }
    
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d]\n", i+1);
        printf("Name: %s\nTrophy: %d\n", c[i].name, c[i].trophy);
    }
}

