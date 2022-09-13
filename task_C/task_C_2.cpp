#include <iostream>
#include <vector>
#include <cmath>

int* qsortRecursive(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
    }
return mas;
}




int findDist (int* sortedA, int n, int k){
    int dist = 0;

    for (int i=0; i<k+1; i++){
        dist += sortedA[i];
    }

return dist;
}


int main(){
  //Input
    int n;
    std::cin >> n;
    if ((n<2)|| (n>300000)) {
        std::cout << -1 << '\n';
        return -1;
    }

    int k;
    std::cin >> k;
    if ((k<1)|| (k>n-1)) {
        std::cout << -1 << '\n';
        return -1;
    }

    int A[n]={0};

    int buffer = 0;
    for (int i=0; i<n; i++){
        std::cin >> buffer;
        if ((buffer>1000000000)||(buffer<1)) {
            std::cout << -1 << '\n';
            return -1;
        } else {
            A[i]=buffer;
        }
    }
  
    for (int i = 0; i<n; i++){

        int buffer_i = A[i];
        int copy[n];
        for (int j =0; j<n; j++){
            copy[j] = abs(A[j] - buffer_i); 
        }

        int* sortedA = qsortRecursive(copy, n); //quickSort (copy, 0, n-1);
        
       // std::cout<<'\n';
       // for (int j = 0; j<n; j++){
       //     std::cout<< sortedA[j]<< ' ';
       // }
        //std::cout<<'\n';
        std::cout << findDist(sortedA, n, k)<< ' ';
    }

 
    



return 0;
}