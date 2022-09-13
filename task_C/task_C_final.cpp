#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <array>
#include <iterator>


struct arr
{
    int amount;
    int ID;

    bool operator< (const arr& b) const { return amount < b.amount; }
};

/*arr* heapify(arr *arr, int n, int biggest)
{
    int largest = biggest;   
// Инициализируем наибольший элемент как корень
    int l = 2*biggest + 1; // левый = 2*i + 1
    int r = 2*biggest + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if ((l < n) && (arr[l].amount > arr[largest].amount))
        largest = l;

   // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if ((r < n) && (arr[r].amount > arr[largest].amount))
        largest = r;

    // Если самый большой элемент не корень
    if (largest != biggest)
    {
        std::swap(arr[biggest], arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
arr* heapSort(arr *arr, int n)
{
  // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
return arr;
}
*/

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
    int biggest = 0;
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
  std::sort(A, A+n);
  /*
  bool sort = true;
    //arr* sortedA = qsortRecursive (A, n, sort);
    arr* sortedA = heapSort (A, sizeof(A)/sizeof(A[0]));
*/

  //Find Dist
    arr result[n];
    int out[n];
    for (int i = 0; i<n; i++){
        result[i] = findDist(A, i, n, k);
        out[result[i].ID]=result[i].amount;
    }
    
    
    /*sort = false;
    arr* res = qsortRecursive(result, n , sort);
    for (int i=0; i<n; i++){
        std::cout<< res[i].amount<< ' ';
    }
   */ 
    for (int i=0; i<n; i++){
        std::cout<< out[i]<< ' ';
    }


return 0;
}