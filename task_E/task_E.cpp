#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <iterator>



int main(){


//Input
    
    int n = 0;
    std::cin >> n;
    if ((n<1)|| (n>300000)) {
        std::cout << -1 << '\n';
        return -1;
    }

    char relations[n][n];
    const std::set <char> allowed {'=','<', '>','!','^','?'};
    char buffer='0'; 
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            std::cin>>buffer;
            if (allowed.find(buffer)!=allowed.end()){
                relations[i][j]=buffer;
            }
        }
    }
    
//Check
    for (int i =0;i<n;i++){
        
        if((relations[i][i]=='!')||(relations[i][i]=='^')){
            std::cout<<"No";
            return 0;
        } else relations[i][i]='=';

        for (int j =0;j<n;j++){

            //Unreal
            if ( (relations[i][j]=='<' && relations[j][i]=='^') || (relations[i][j]=='>' && relations[j][i]=='!') ||
                 (relations[j][i]=='<' && relations[i][j]=='^') || (relations[j][i]=='>' && relations[i][j]=='!') ||

                 (relations[i][j]=='=' && (relations[j][i]=='^' || relations[j][i]=='!')) ||
                 (relations[j][i]=='=' && (relations[i][j]=='^' || relations[i][j]=='!'))   )
                    {
                        std::cout<<"No";
                        return 0;
                    }
             if (relations[i][j]=='='){relations[j][i]=='=';}
             if (relations[i][j]=='?' && relations[j][i]=='<'){relations[i][j]=='>';}
             if (relations[i][j]=='?' && relations[j][i]=='>'){relations[i][j]=='<';}
        }
    }

    std::cout<<"Yes"<<'\n';

/*/ Output
    for (int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            std::cout<<relations[i][j]<<' ';
        }
        std::cout<<'\n';
    }*/
    
    


    std::set <int> vec[n];
    bool good[n]={true};
    for (int i=0; i<n; i++){
        vec[i].insert(i+1);
    }
    int counter = n;
    for(int iteration=0; iteration<2; iteration++){
        for(int i=0; i<n;i++){
            for(int j=i; j<n;j++){
                char visible = relations[i][j];
                if (relations[i][j]=='!' && iteration ==0){
                    vec[i].insert(counter++);
                    }
                if (relations[i][j]=='^' && iteration ==0){
                    vec[j].insert(counter++);
                    }
                if (relations[i][j]=='<'){
                    std::set <int> bufset = vec[i];
                    vec[j].merge(bufset);
                    }
                if (relations[i][j]=='>'){
                    std::set <int> bufset = vec[j];
                    vec[i].merge(bufset);
                    }
                if (relations[i][j]=='='){
                    vec[i].merge(vec[j]);
                    vec[j]=vec[i];
                    }
            }
        }
    }

for(int i=0; i<n;i++){
    std::cout<<vec[i].size()<< ' ';
    std::copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<'\n';
}



    


return 0;     
}