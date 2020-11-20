
#include <iostream>

 
using namespace std;

long double fibs[1000];

int main ()
{
    
    int result, i;
    long int v1, v2;


    fibs[0] = 1;
    fibs[1] = 2;

    for (int i = 2 ; i < 1000; i++)
            fibs[i] = fibs[i - 1] + fibs[i - 2];
       
         
    while(cin>> v1 >> v2)
    {
       
        if (!v1 && !v2) {
          return 0;
        
        }

        for (i = 0; i < 1000; i++)
        {
            if (v1 <= fibs[i]) 
            break;
        }

        result = 0;

        while(fibs[i] <= v2)
        {
            result++;
            i++;

        }
        cout << result << '\n';
    }
}

