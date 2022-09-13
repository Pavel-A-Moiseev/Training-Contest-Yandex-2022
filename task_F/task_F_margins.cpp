#include <iostream>

class Photo
{
private:
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int leftCut = 0;
    int rightCut = 0;
    int upperCut = 0;
    int lowerCut = 0;
    int initArea = (x2-x1)*(y2-y1);
    int newArea = initArea;

    
public:
    Photo(){
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
        leftCut = 0;
        rightCut = 0;
        upperCut = 0;
        lowerCut = 0;
        initArea = (x2-x1)*(y2-y1);
        newArea = initArea; 
    };
    Photo(int x11, int y11, int x22 , int y22){
        x1 = x11;
        y1 = y11;
        x2 = x22;
        y2 = y22;
        leftCut = 0;
        rightCut = 0;
        upperCut = 0;
        lowerCut = 0;
        initArea = (x2-x1)*(y2-y1);
        newArea = initArea; 

    };

    void FnewArea (Photo old, Photo actual){
        if (old.leftCut<abs(actual.x1)){old.leftCut = abs(actual.x1);} else {old.leftCut = abs(old.x1);}
        if (old.rightCut<actual.x2){old.rightCut = actual.x2;} else {old.rightCut = old.x2;}
        if (old.lowerCut<abs(actual.y1)){old.lowerCut = abs(actual.y1);} else {old.lowerCut = abs(old.y1);}
        if (old.upperCut<actual.y2){old.upperCut = actual.y2;} else {old.upperCut = old.y2;}

        newArea = initArea - ((old.upperCut+old.lowerCut)*(old.leftCut+old.rightCut));
    }
    
    void getNewArea(){
        std::cout<<newArea<<'\n';
    }
};





int main(){

//Input
    
    int n = 0;
    std::cin >> n;
    if ((n<1)|| (n>300000)) {
        std::cout << -1 << '\n';
        return -1;
    }

    Photo mas[n];
    int x1, y1, x2, y2;

    for (int i = 0; i<n; i++){
        std::cin>>x1;
        std::cin>>y1;
        std::cin>>x2;
        std::cin>>y2;

        mas[i] = Photo(x1, y1,  x2,  y2);
        for (int j=i-1; j>=0; j--){
            mas[j].FnewArea(mas[j], mas[i]);
        }

    }

//Output
    for (int i=0; i<n; i++){
        mas[i].getNewArea();
    }

return 0;
}