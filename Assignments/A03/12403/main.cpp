#include <iostream>
using namespace std;

int main(){

    int account;
    int T, K; 

    string Op;

    cin>> T;
   while (T--) {
    
        cin >> Op;

        if(Op == "donate"){
            cin >> K;
            account = account + K;
        }
        else {
       
            cout << account << '\n';
        }
      
    }

}