#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define max_len 255

int pilihan1(int* bpm, int i);
int pilihan2(char nama[max_len][max_len], int i, char* namaSiswa, int* bpm);

int main(){
    char filename[max_len];

    printf("Masukkan nama file kelas : ");
    scanf("%s", &filename);

    FILE* listbpm;
    listbpm = fopen(filename, "r");

    if (listbpm  == NULL){
         printf("Error : file invalid");
         exit(1);
     }

    char nama[max_len][max_len];
    int bpm [max_len];

    char line[max_len];
    char* token;

    int i = 0;
    
    while (fgets(line, max_len, listbpm))
    {
        token = strtok(line, ",");
        strcpy(nama[i], token);

        token = strtok(NULL, "\n");
        bpm[i] = atoi(token);

        ++i;
    }

    fclose(listbpm);
    printf("Pilihlah nomor menu dibawah ini : \n");
    printf("1. Cari siswa dengan bpm terkecil\n");
    printf("2. Cari siswa dengan nama nya\n");
    printf("3. Cari siswa dengan rentang bpm tertentu\n");
    printf("Masukkan nomor menu 1/2/3 : ");

    int pilihan;
    scanf("%d", &pilihan);

    char namaSiswa[max_len];

    if (pilihan == 1)
    {
        int index1 = pilihan1(bpm, i);
        printf("Siswa 1\n");
        printf("Nama siswa : %s\n", nama[index1]);
        printf("Bpm siswa : %d\n", bpm[index1]);
    }
    else if (pilihan == 2)
    {
        printf("Masukkan nama siswa : ");
        scanf("%s", &namaSiswa);
        pilihan2(nama, i, namaSiswa, bpm);
    }
    return 0;
}

int pilihan1(int* bpm, int i){
    int j_kecil = 0, j = 1;
    for (j = 1; j < i; j++)
    {
        if (bpm[j] < bpm[j_kecil])
        {
            j_kecil = j;
        }
    }
    return j_kecil;
}

int pilihan2(char nama[max_len][max_len], int i, char* namaSiswa, int* bpm){
    int k = 0;
    int nomor = 0;
    for (k = 0; k < i; k++)
    {
        if (strstr(nama[k],namaSiswa))
        {
            nomor++;
            printf("Siswa %d\n", nomor);
            printf("Nama siswa : %s\n", nama[k]);
            printf("Bpm siswa : %d\n", bpm[k]);
        }
    }
    return 0;
}