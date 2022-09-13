#include <iostream>
#include <string.h>
#include <cmath>

struct arr
{
    int amount;
    int ID;
};

arr* qsortRecursive(arr *mas, int size, bool ehm) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    arr mid = mas[size / 2];

    //Делим массив
    do {
        if(ehm==true){
            //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
            //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
            while(mas[i].amount < mid.amount) {
                i++;
            }
            //В правой части пропускаем элементы, которые больше центрального
            while(mas[j].amount > mid.amount) {
                j--;
            }
        } else {
            while(mas[i].ID < mid.ID) {
                i++;
            }
            while(mas[j].ID > mid.ID) {
                j--;
            }

        }
        //Меняем элементы местами
        if (i <= j) {
            arr tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1, ehm);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i, ehm);
    }
return mas;
}





arr findDist (arr* sortedA, int i, int n, int k){
    arr result;
    int dist = 0;
    int buffer_i = sortedA[i].amount;
    int leftGap = 1;
    int rightGap = 1;
    for (int j = 0; j<k; j++){
        if ((i-leftGap>=0)&&(i+rightGap<n)){
            if (abs(sortedA[i-leftGap].amount - buffer_i)<=abs (sortedA[i+rightGap].amount - buffer_i)){
                dist += abs(sortedA[i-leftGap].amount - buffer_i);
                leftGap++;
            } else{
                dist += abs(sortedA[i+rightGap].amount - buffer_i);
                rightGap++;
            }
        } else {
            if (i-leftGap>=0){
                dist += abs(sortedA[i-leftGap].amount - buffer_i);
                leftGap++;
            } else{
                dist += abs(sortedA[i+rightGap].amount - buffer_i);
                rightGap++;
            }
        }
    }    
result.amount = dist;
result.ID = sortedA[i].ID;
return result;
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

    arr A[n]={0};

    int buffer = 0;
    for (int i=0; i<n; i++){
        std::cin >> buffer;
        if ((buffer>1000000000)||(buffer<1)) {
            std::cout << -1 << '\n';
            return -1;
        } else {
            A[i].amount=buffer;
            A[i].ID=i;
        }
    }
  // Sorting
  bool sort = true;
    arr* sortedA = qsortRecursive (A, n, sort);

  //Find Dist
    arr result[n];
    for (int i = 0; i<n; i++){
        result[i] = findDist(sortedA, i, n, k);
    }
    sort = false;
   arr* res = qsortRecursive(result, n , sort);
    for (int i=0; i<n; i++){
        std::cout<< res[i].amount<< ' ';
    }
    



return 0;
}