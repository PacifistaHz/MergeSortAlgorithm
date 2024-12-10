#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int D[], int enkckindis, int orta, int enbykindis);
void bolum(int D[], int enkckindis, int enbykindis);
void printArray(int D[], int size);

int main() {
    int i, N;
    printf("MERGE SORT ALGORITMASI\n");
    printf("Kac adet sayi uretilecek: ");
    scanf("%d", &N);
    int *dizi = (int *)malloc(N * sizeof(int));
    srand(time(0));
    printf("Dizi Elemanlari: ");
    for (i = 0; i < N; i++) {
        dizi[i] = rand() % 100;
        printf("%d ", dizi[i]);
    }
    bolum(dizi, 0, N-1);
    printf("\nSiralanmis Dizi Elemanlari: ");
    printArray(dizi, N);
    free(dizi);
    return 0;
}

void bolum(int D[], int enkckindis, int enbykindis) {
    int orta;
    if(enkckindis < enbykindis) {
        orta = (enkckindis + enbykindis) / 2;
        bolum(D, enkckindis, orta);
        bolum(D, orta + 1, enbykindis);
        mergeSort(D, enkckindis, orta, enbykindis);
    }
}

void mergeSort(int D[], int enkckindis, int orta, int enbykindis) {
    int i, m, k, l;
    int boy = enbykindis - enkckindis + 1;
    int *temp = (int *)malloc(boy * sizeof(int));
    l = enkckindis;
    i = 0; // temp dizisinin başlangıcı
    m = orta + 1;

    while((l <= orta) && (m <= enbykindis)) {
        if(D[l] <= D[m]) {
            temp[i] = D[l];
            l++;
        } else {
            temp[i] = D[m];
            m++;
        }
        i++;
    }
    while(l <= orta) { // Kalan elemanları ekle
        temp[i] = D[l];
        l++;
        i++;
    }
    while(m <= enbykindis) { // Kalan elemanları ekle
        temp[i] = D[m];
        m++;
        i++;
    }
    for(i = 0, k = enkckindis; k <= enbykindis; i++, k++) {
        D[k] = temp[i];
    }
    free(temp);
}

void printArray(int D[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");
}
