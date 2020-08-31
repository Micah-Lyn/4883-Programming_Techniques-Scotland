#include <iostream>
using namespace std;

int main(){
    
    string Op;
    int account;
    int K, T; 

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
