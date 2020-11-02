#include <iostream>
#include<vector>

using namespace std;


int s, m;
char c[3] = {'A','B','C'};
vector<int>peg[3];


void output()
{
    int size;

    cout << '\n';
    for (int i = 0; i < 3; i++)
    {
        
        cout <<c[i] <<"=>"; 
        if (!peg[i].empty())
        {
            printf("   ");
            size = peg[i].size();
            for (int j = 0; j < size - 1; j++)
                cout << peg[i][j] << " ";

            
            cout << peg[i].back();
        }
     
        cout <<'\n';
    }
}
void solve(int n, int l, int m, int r)
{
    if (s == m)
        return;

    if (n == 1)
    {
        s++;

        peg[r].push_back(peg[l].back());
        peg[l].pop_back();
        output();
    }
    else
    {
        solve(n - 1, l, r, m);
        if (s == m)
            return;
        s++;
        
        peg[r].push_back(peg[l].back());
        peg[l].pop_back();
        output();

        solve(n - 1, m, l, r);
    }
}

int main()
{
    int n, tCase = 1;
   
    cin >> n >> m;

    while(n != 0)
    {
       
        cout << "Problem #" << tCase++ << '\n';
        s = 0;

        for (int i = n; i> 0 ; i--)

            peg[0].push_back(i);

        output();
        solve(n, 0, 1, 2);

        for (int i = 0; i < 3; i++)
            peg[i].clear();

        cout <<'\n';
        cin >> n >> m;
    }

    return 0;
}