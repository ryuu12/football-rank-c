#include <stdio.h>
#include <stdlib.h>

struct data{
    char arrusername[20];
    char arrpassword[20];
}datauser[100];

int menu;

void masuk(){

    int i,end=0;
    char buff[20],tryusername[20],trypassword[20];
    FILE *datausername;
    FILE *datapassword;

    datausername=fopen("username.txt","r");
    datapassword=fopen("password.txt","r");

    i=0;
    while(fgets(buff,sizeof(buff),datausername)!=NULL){
        strcpy(datauser[i].arrusername,buff);
        i++;
        end++;
    }
    fclose(datausername);

    i=0;
    while(fgets(buff,sizeof(buff),datapassword)!=NULL){
        strcpy(datauser[i].arrpassword,buff);
        i++;
    }
    fclose(datapassword);

    printf("| = = = = = | Log in | = = = = = |\n");
    printf("username: ");
    fgets(tryusername,sizeof(tryusername),stdin);
    printf("password: ");
    fgets(trypassword,sizeof(trypassword),stdin);
    system("cls");

    i=0;
    while(i<=end+1){
        if(i>end){
            system("cls");
            printf("(ops sorry your username not found\n");
            printf("1. Try again\n");
            printf("2. Back To menu\n");
            printf("\nSelect menu: ");
            scanf("%d",&menu);
            fflush(stdin);
            system("cls");
            switch (menu) {
                case 1: masuk();
                        break;
                default: main();
            }
        }
        if(strcmp(datauser[i].arrusername,tryusername)==0){
            if(strcmp(datauser[i].arrpassword,trypassword)==0){
                usermenu();
            }
            else{
                system("cls");
                printf("(ops sorry Wrong Password)\n");
                printf("1. Try again\n");
                printf("2. Back to the Menu\n");
                printf("\nSelect Menu: ");
                scanf("%d",&menu);
                fflush(stdin);
                system("cls");
                switch (menu) {
                    case 1: masuk();
                            break;
                    default: main();
                }
            }
        }
        i++;
    }
}

void daftar(){
    char username[20];
    char password[20];
    FILE *datausername;
    FILE *datapassword;

    printf(" | = = = = = | Register | = = = = = | \n");
    datausername=fopen("username.txt","a+");
    printf("Enter username: ");
    fgets(username,sizeof(username),stdin);
    fputs(username,datausername);
    fclose(datausername);

    datapassword=fopen("password.txt","a+");
    printf("Enter Password: ");
    fgets(password,sizeof(password),stdin);
    fputs(password,datapassword);
    fclose(datapassword);
    system("cls");

    printf("(registered successfully)\n");
}

void usermenu(){
    printf("Success entered user menu\n");
    printf("1. Input Data Klub\n");
    printf("\nSelect Menu: ");
    scanf("%d",&menu);
    fflush(stdin);
    system("cls");
    switch (menu) {
        case 1: inputdata();break;
        default: usermenu();
    }
}

void inputdata(){
    int i,n;
    char nama[500];
    int tropi,jumlahanggota;
    char anggotaklub[500];
    char negara[500];
    char divisi[500];

    FILE *dataklub;

    dataklub=fopen("data_klub.txt","a");

    if(dataklub==NULL){
        printf("Data tidak ditemukan");
    }

    else{
        printf("Masukkan Banyak Klub : ");
        scanf("%d",&n);
        for(i=0;i<n;i++){
            fflush(stdin);
            printf("Masukkan Nama Klub : ");
            fgets(nama,sizeof(nama),stdin);
            fflush(stdin);
            fprintf(dataklub,"Nama Klub : %s",nama);
            printf("Masukkan jumlah Tropi : ");
            scanf("%d",&tropi);
            fprintf(dataklub,"Jumlah Tropi : %d\n",tropi);
            printf("Masukkan jumlah anggota : ");
            scanf("%d",&jumlahanggota);
            fprintf(dataklub,"Anggota :\n");
            for(i=0;i<jumlahanggota;i++){
                fflush(stdin);
                printf("Masukkan Nama Anggota : ");
                fgets(anggotaklub,sizeof(anggotaklub),stdin);
                fprintf(dataklub,"%s",anggotaklub);
            }
            printf("Masukkan Negara Asal : ");
            fgets(negara,sizeof(negara),stdin);
            fflush(stdin);
            fprintf(dataklub,"Negara Asal : %s",negara);
            printf("Masukkan Divisi Klub : ");
            fgets(divisi,sizeof(divisi),stdin);
            fflush(stdin);
            fprintf(dataklub,"Divisi : %s",divisi);
        }
        fclose(dataklub);
    }
}

int main(){
    while(1){
        printf("| = = = = = | Welcome to Football Rank | = = = = = |\n");
        printf("1. Log In");
        printf("\n2. Sign up");
        printf("\n3. Exit\n");
        printf("\nSelect Menu: ");
        scanf("%d",&menu);
        fflush(stdin);
        system("cls");
        switch (menu) {
            case 1: masuk();
                    break;
            case 3: exit(0);
            default: daftar();
        }
    }
    return 0;
}
