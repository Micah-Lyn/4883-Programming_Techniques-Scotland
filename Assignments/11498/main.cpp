#include <iostream>
using namespace std;

int main() {

int K; // test case
int N, M; // coordinates of division points
int X, Y; // coordinates of residence

while(cin>> K){

  if (K != 0) {

   cin>> N >> M;

   int i = 0;

   while(i < K) {

     cin >> X >> Y;

      
      if(X > N && Y > M ) {
        cout<<"NE\n";
      }
      else if(X < N && Y < M) {                  
         cout<<"SO\n";
      }
      else if (X < N && Y > M) {
         cout<<"NO\n";
      }        
      else if(X > N && Y < M) {
          cout<<"SE\n";
      }
      else {
        cout<<"divisa\n";
      }

     i++;
   }
  }
}
return 0;
}

