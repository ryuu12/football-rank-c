#include <stdio.h>
#include <stdlib.h>

int main(void)
{
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
    return 0;
	//Langsung aja simpen kodenya di sini yak -Rayhan
	
}
