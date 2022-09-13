#include <iostream>
#include <string.h>
int CheckPossibility(int A[], int n) {
    for (int i=n-1; i>0; i--){
        if (A[i]<A[i-1]){
            //std::cout<<"Unsortable"<<'\n';
            std::cout << -1 << '\n';
            return -1;
        }    
    }
return 0;
}

int main() {
    int n;
    //std::cout <<"Insert number of tanks."<<'\n';
    std::cin >> n;
    if ((n<1)|| (n>100000)) {
        std::cout << -1 << '\n';
        return -1;
    }
    if(n==1) {
        std::cout<<0;
        return 0;
    }
    int A[100000]={0};

    int buffer = 0;
    for (int i=0; i<n; i++){
        //std::cout <<"Insert volume in tank "<< i+1 << '.'<<'\n';
        std::cin >> buffer;
        //buffer = 10000*(i+1);
        if ((buffer>1000000000)||(buffer<1)) {
            std::cout << -1 << '\n';
            return -1;
        } else {
            A[i]=buffer;
        }
    }

    if (CheckPossibility(A,n)==0) {
        int counter= A[n-1]-A[0];

       /* for (int i=n-1; i>0; i--){
            counter = counter + A[i]-A[i-1];
        }*/

        std::cout << counter << '\n';
    }
return 0;
}
