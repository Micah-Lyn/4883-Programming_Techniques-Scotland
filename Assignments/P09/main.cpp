#include<iostream>
#include<cstdio>

using namespace std;
 
int main(){

   int tcase; 
   int i,j,k;

  int bLine = 0;
 
    cin >> tcase;

    while (tcase--){

        int snumM,slengthN ;
        
        cin >> slengthN;
        cin >>snumM;
 
        char **acVal = new char *[snumM + 1];
       
        int *cnt= new int[snumM + 1];
 
        for (i = 0; i < snumM; i++){
            
            acVal[i] = new char[slengthN + 1];
          
            cin>> acVal[i];

            cnt[i] = j = 0;

            for (; j < slengthN; j++){
                for (k = j + 1; k < slengthN; k++){

                    if (acVal[i][j] > acVal[i][k])
                        
                        cnt[i]++;
                }
            }
        }
 
       
        for (i = 0; i < snumM - 1; i++){
            for (j = 0; j < snumM - i - 1; j++){

                if (cnt[j] > cnt[j+1]){   
                    swap(cnt[j], cnt[j+1]);
                    swap(acVal[j], acVal[j+1]);

                }
            }
        }
 
       
        if (bLine) 
          cout << '\n';

        bLine = 1;
 
        for (i = 0; i < snumM; i++)
            cout << acVal[i] << '\n';
    }
    return 0;
}