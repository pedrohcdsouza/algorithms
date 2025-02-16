#include "ordenacao.hpp"

bool ordenado(int a[], unsigned int t){
if(t==0 || t==1){
    return true;
}
for(unsigned int i = 0; i < t - 1; i++){
    if(a[i] > a[i + 1]){
    return false;
    }
}
return true;
};

void selecao(int a[], unsigned int t){
int min, aux;
for(unsigned int i = 0; i < t - 1; i++){
    min = i;
    for(unsigned int j = i + 1; j < t; j++){
    if(a[j] < a[min]){
        min = j;
    }
    }
    if(a[i] != a[min]){
    aux = a[i];
    a[i] = a[min];
    a[min] = aux;
    }
    }
}

void insercao(int a[], unsigned int t){
unsigned int i, j;
int x;
for (i = 1; i < t; ++i) {
    x = a[i];
    j = i - 1;
    while (j < t && a[j] > x) {
        a[j + 1] = a[j];
        if (j == 0) break;
        --j;
    }
    a[j + 1] = x; 
    }
}

void merge(int a[], int i1, int j1, int i2, int j2) {
int* temp = new int[(j1 - i1 + 1) + (j2 - i2 + 1)];
int i = i1, j = i2, k = 0;

while (i <= j1 && j <= j2) {
    if (a[i] < a[j]) {
        temp[k++] = a[i++];
    } else {
        temp[k++] = a[j++];
    }
}

while (i <= j1) {
    temp[k++] = a[i++];
}

while (j <= j2) {
    temp[k++] = a[j++];
}

for (i = i1, k = 0; i <= j2; ++i, ++k) {
    a[i] = temp[k];
}

delete[] temp;
}

void merge_sort(int a[], int primeiro, int ultimo) {
if (primeiro < ultimo) {
    int meio = (primeiro + ultimo) / 2;
    merge_sort(a, primeiro, meio);
    merge_sort(a, meio + 1, ultimo);
    merge(a, primeiro, meio, meio + 1, ultimo);
    }
}
