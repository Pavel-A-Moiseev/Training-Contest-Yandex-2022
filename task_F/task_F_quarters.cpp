#include <iostream>
#include <set>
#include <utility>
#include <cmath>

using namespace std::rel_ops;

struct Str_HW
{
    uint64_t height;
    uint64_t width;
    __uint128_t area;

    bool operator< (const Str_HW& b) const { return height < b.height; }
    bool operator== (const Str_HW& b) const { return height == b.height; } 

    Str_HW() {
        height=0;
        width=0;
        area=0;
    }

};



class Photo
{
private:

    

    
   
public:

Str_HW Q[4];
uint64_t totalArea;

    Photo(){
        for (int i=0; i<4; i++){
            Q[i].height=0;
            Q[i].width=0;
            Q[i].area=0;
        }
    };



    Photo(int x11, int y11, int x22 , int y22){
        

        Q[0].height = y22;
        Q[0].width = x22;

        Q[1].height = y22;
        Q[1].width = abs(x11);

        Q[2].height = abs(y11);
        Q[2].width = abs(x11);

        Q[3].height = abs(y11);
        Q[3].width = x22;

        checkExistance();
        baseArea();
        FtotalArea();
       
    };

    void checkExistance(){
        for (int i=0; i<4; i++){
            if (Q[i].height==0){
                Q[i].width=0;
            }
            if (Q[i].width==0){
                Q[i].height=0;
            }
    }
        
    };  

    void baseArea (){
        for (int i=0; i<4; i++){
            Q[i].area = Q[i].height*Q[i].width;
        }
    };

    void FtotalArea(){
        totalArea = 0;
        for(int i=0; i<4; i++){
            totalArea+=Q[i].area;
        }
    };

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
    
    int64_t x1,x2,y1,y2;
    for (int i = 0; i<n; i++){

        std::cin>>x1;
        std::cin>>y1;
        std::cin>>x2;
        std::cin>>y2;

        mas[i] = Photo(x1, y1,  x2,  y2);
    }

    Str_HW empty = Str_HW();
    for (int j=0; j<4; j++){ //Quarters

        std::multiset <Str_HW> The_Set={empty};
        for (int i = n-1; i>=0; i--){ // Pick a photo
            std:: multiset <Str_HW> :: reverse_iterator it=The_Set.crbegin();

            if (mas[i].Q[j].area != 0){ 
                int deletedWidth = 0;
                for (; it != The_Set.crend(); it++) { //Go upstairs

                    Str_HW buf = *it;

                    if (buf.height>mas[i].Q[j].height){buf.height=mas[i].Q[j].height;} // Cut buf with height and width of a base Photo
                    if (buf.width>mas[i].Q[j].width){buf.width=mas[i].Q[j].width;}

                    if (buf.width>deletedWidth){
                        mas[i].Q[j].area -= buf.height*(buf.width-deletedWidth);
                        deletedWidth =buf.width;    
                    }

                    if (mas[i].Q[j].area==0 || deletedWidth==mas[i].Q[j].width || mas[i].Q[j].height==0){break;}
                    
                }

            }

            if (j==3) {mas[i].FtotalArea();}
            The_Set.insert(mas[i].Q[j]);
        }
    }
//Output

    for (int i=0; i<n; i++){
        std::cout<<mas[i].totalArea<<'\n';
    }
return 0;
}