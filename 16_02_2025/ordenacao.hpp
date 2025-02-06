#ifndef __ORDENACAO__
#define __ORDENACAO__

/*
  Função que retorna se um vetor 'a' de 't' elementos 
  está ordenado não decrescentemente

  Retorno: false Se 'a' não estiver ordenado
           true caso contrário
*/
bool ordenado(int a[], unsigned int t){ /*Função que ordena o vetor 'a' de forma não decrescente usando o método de ordenação por seleção. A ordenação é feita diretamente no vetor 'a' */
  bool sorted = true; 
  for(int i = 1; i < t; i++){
    if(a[i-1] > a[i]){
      sorted = false;
      break;
    }
  }
  return sorted;
};

void selecao(int a[], unsigned int t){ /*Função que ordena o vetor 'a' de forma não decrescente usando o método de ordenação por inserção. A ordenação é feita diretamente no vetor 'a'*/
int min, aux;
for(int i = 0; i < t-1; i++){
  min = i;
  for(int j = i+1; j < t; j++){
    if(a[j] < a[min])
      min = j;
  }
  if(a[i] != a[min]){
    aux = a[i];
    a[i] = a[min];
    a[min] = aux;
  }
}
};


void insercao(int a[], unsigned int t); /* Função que ordena o vetor 'a' de forma não decrescente usando o método de ordenação merge-sort. A ordenação é feita diretamente no vetor 'a' */
int aux[];
for(int i = 0; i < t; i++){
  aux[i] = a[i];
}
for(int i = 1; i < t; i++){
  if(a[i-1] < aux[i])
    a[i-1] = aux[i];
}


void merge_sort(int a[], unsigned int t);

#endif