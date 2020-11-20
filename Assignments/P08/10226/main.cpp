#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int t;

    while (cin >> t)
    {
        getchar();
        getchar();

        string tree;
        int n = 0;

        map<string, int> rec;

        while (getline(cin, tree))
        {
            if (tree.compare("") == 0)
                break;
            rec[tree]++;
            n++;
        }
        for (map<string, int>::iterator i = rec.begin(); i != rec.end(); i++)
            cout << i->first << " " << fixed << setprecision(4) << i->second * 100.0 / n << endl;
        if (t)
            puts("");
        t--;
    }

    return 0;
}