
#include <iostream>
using namespace std;

int main(){

    int T;
    int L, W, H;

    cin >> T;

    int i = 1;
    
    while (T){
     
        cin >> L >> W >> H;
       
        if(L <=20 && W <= 20 && H <= 20) {
        cout << "Case " << i << ": good\n";
        }
        else {
        cout << "Case " << i << ": bad\n";
        }
      i++;
      T--;
    }
   return 0;
}
