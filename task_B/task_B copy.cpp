#include <iostream>
#include <string.h>


int main(){

    int n;
    std::cin>>n;

    char A[n][7]={'.'};
    std::string buffer;
    for (int i=0; i<n; i++){
        std::cin>>buffer;
        if (buffer.length() == 7){
            for (int j=0; j<7; j++) {
                if (  (buffer[j]=='.') || (buffer[j]=='#') || ((j==3)&&(buffer[j]=='_') )  ) {
                    A[i][j]=buffer[j];
                } else return -1;
            }
        }
    }
   
    int m;
    std::cin>>m;

    int num=0;
    std::string side, position;

    for (int i = 0; i<m; i++){


        for (int j=0; j<3; j++){
            if (j==0) std::cin>>num;
            if (j==1) std::cin>>side;
            if (j==2) std::cin>>position;
        }
        int situation;
            if (  (side=="left")&&(position=="window")) {
                situation =1;           
            }
            if (  (side=="left")&&(position=="aisle")) {
                situation =2;           
            }
            if (  (side=="right")&&(position=="aisle")) {
                situation =3;           
            }
            if (  (side=="right")&&(position=="window")) {
                situation =4;           
            }
        bool good;
        std::string alphabet {"ABC_DEF"};
        for(int k=0; k<n; k++){
            
                good = true;
                switch (situation){

                    case 1:

                        for (int m=0; m<num; m++){
                            if (A[k][m]=='#'){good = false;}
                        }

                        if (good == true){
                            std::cout<<"Passengers can take seats:";
                            for (int m=0; m<num; m++){
                                A[k][m]='X';
                                std::cout<<' '<<k+1<<alphabet[m];
                            }
                            std::cout<<'\n';
                            break;    
                        }

                    case 2:

                        for (int m=3-num; m<3; m++){
                            if (A[k][m]=='#'){good = false;}
                        }

                        if (good == true){
                            std::cout<<"Passengers can take seats:";
                            for (int m=3-num; m<3; m++){
                                A[k][m]='X';
                                std::cout<<' '<<k+1<<alphabet[m]; 
                            }
                            std::cout<<'\n';
                            break;
                        }

                    case 3:
                        for (int m=4; m<4+num; m++){
                            if (A[k][m]=='#'){good = false;}
                        }

                        if (good == true){
                            std::cout<<"Passengers can take seats:";
                            for (int m=4; m<4+num; m++){
                                A[k][m]='X';
                                std::cout<<' '<<k+1<<alphabet[m]; 
                            }
                            std::cout<<'\n';    
                            break;
                        }

                    case 4:
                        for (int m=7-num; m<7; m++){
                            if (A[k][m]=='#'){good = false;}
                        }
                        
                        if (good == true){
                            std::cout<<"Passengers can take seats:";
                            for (int m=7-num; m<7; m++){
                                A[k][m]='X';
                                std::cout<<' '<<k+1<<alphabet[m]; 
                            }
                            std::cout<<'\n';
                            break;
                        }

                }
        if (good == true){break;}       

        }
        // Output
        if (good==true){
                for (int i1=0; i1<n; i1++){
                        for (int j=0; j<7; j++){
                            std::cout << A[i1][j];
                            if (A[i1][j]=='X'){A[i1][j]='#';}

                        }
                    std::cout<<'\n';
                }
        }else {std::cout<<"Cannot fulfill passengers requirements"<<'\n';}


            
    }
    


      
return 0;
}