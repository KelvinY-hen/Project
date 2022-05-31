/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 9 - Tugas Besar
*Percobaan        : 3
*Hari dan Tanggal : Kamis, 28 April 2022
*Kelompok (NIM)   : A8 (18320004, 18320008, 18320013, 18320031, 18320040)
*Asisten (NIM)    : Syifa Kushirayati (18319037)
*Nama File        : hamiltonian.c
*Deskripsi        : Program akan menghitung jumlah hamilton path dan mencetak semua hamilton path yang ada
*/

#include <stdio.h>

#define boolean unsigned char
#define true 1
#define false 0

#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"
#define max_len 255

boolean hasHamiltonian = false;
int count = 0;

FILE *fp2;

void printSolution(int vertices, int p[]) {
    count++;
    for (int i = 0; i < vertices; i++) {
        printf("%d ", p[i]);
        fputc(p[i]+'0', fp2);
        fputc(' ', fp2);
    }
    printf("%d\n", p[0]);
    fputc(p[0]+'0', fp2);
    fputc('\n', fp2);
}

boolean isSafe(int vertices, int n, boolean g[vertices][vertices], int path[], int pos) {
    if (g [path[pos-1]][n] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == n)
            return false;
    return true;
}

void hamiltonianCycle(int vertices, boolean g[vertices][vertices], int* path, int pos) {
   //If all vertices are included in Hamiltonian Cycle
    if (pos == vertices) {
        if (g[ path[(sizeof(path)/sizeof(path[0]))-1] ][ path[0] ] == 1){
            printSolution(vertices, path);
            hasHamiltonian = true;
        }
    }
    for (int n = 0; n < vertices; n++) {
        if (isSafe(vertices, n, g, path, pos)) //Check if this vertex can be added to Hamiltonian Cycle
        {
            path[pos] = n;
            //recur to construct rest of the path
            hamiltonianCycle(vertices, g, path, pos+1);
            path[pos] = -1; //remove vertex if it doesn’t lead to the solution
        }
    }
}

void hamiltonianPath(int vertices, boolean g[vertices][vertices]) {
    int path[vertices];
    for (int i = 0; i < vertices; i++)
        path[i] = -1;
    
    for (int i = 0; i < vertices; i++) {
        path[0] = i;
        hamiltonianCycle(vertices, g, path, 1);
        if (hasHamiltonian == false) {
            printf("\nCycle beginning on %d vertex doesn't exist", i);
        }
    }
}

int main() {
    // Read from file
    FILE *fp;
    char c;
    int row = 0, col = 0;
    int vertices;

    char file[max_len];
    printf(GRN "\nWelcome to Hamiltonian Path" RESET);

    printf("\nHamiltonian Path means that every vertices in a graph is traversed once only.");
    printf("\n\nEnter file name: ");
    gets(file);

    fp = fopen(file, "r");

    if (fp == NULL) {
        printf("Error: file invalid!\n");
        return 0;
    }

    // Read first line to get number of vertices present
    c = fgetc(fp);
    vertices = c - '0';
    printf("%d\n", vertices);

    // Create adjacency matrix
    boolean matrix[vertices][vertices];

    // Read to skip \n
    c = fgetc(fp);

    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            row++;
            col = 0;
        } 
        else if (c != ' ' && c != ',') {
            if (c == '1') {
                matrix[row][col] = true;
            } 
            else {
                matrix[row][col] = false;
            }
            col++;
        }
    }

    fclose(fp);
    printf("Hamilton Path yang terdapat pada matrix adalah: \n");
    // Print adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    fp2 = fopen("path-output.txt", "w+");

    // Search for Hamiltonian Path
    hamiltonianPath(vertices, matrix);
    printf("\nTerdapat %d hamiltonian path\n\n", count);

    fclose(fp2);

    return 0;
}