#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

vector<int>peg[3];

char p[3] = { 'A','B','C' };

int runs, rNum;

void output()
{
  
    cout << '\n';

    for (int i = 0; i < 3; i++)
    {
        
        cout << p[i] << "=>";

        if (!peg[i].empty())
        {
      
            cout << "   ";
           

            for (int j = 0; j < peg[i].size() - 1; j++)
               cout << peg[i][j] << ' ';

            
            cout << peg[i].back();
        }
        cout << '\n';
    }
}


void compute(int n, int l, int m, int r)
{
    if (runs == rNum){
        return;

    }

    if (n == 1)
    {
        runs++;
        peg[r].push_back(peg[l].back());
        peg[l].pop_back();
        output();
    }
    else
    {
        compute(n - 1, l, r, m);

        if (runs == rNum){
            return;

        }
        
        runs++;
        
        peg[r].push_back(peg[l].back());
        peg[l].pop_back();

        output();

        compute(n - 1, m, l, r);
    }
}

int main()
{

    int n, tCase = 1;

    cin >> n >> rNum;

    while (n!=0)
    {
        
        cout << "Problem #" << tCase++ << '\n';

        runs = 0;

        for (int i = n; i; i--)
            peg[0].push_back(i);

        output();

        compute(n, 0, 1, 2);

        for (int i = 0; i < 3; i++)
            peg[i].clear();

       
        cout <<'\n';

        cin >> n >> rNum;
    }

    return 0;
}




