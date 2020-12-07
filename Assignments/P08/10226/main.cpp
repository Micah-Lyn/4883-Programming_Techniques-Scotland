#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main()
{

    int testcases;
    
    string currTree;

    cin >> testcases;

    getline(cin, currTree);

    getline(cin, currTree);

    while (testcases--)
    {
        int treeTotal = 0;

        map<string, int> tree;

        while (true)
        {
            getline(cin, currTree);

            if (currTree == "")
            {
                break;
            }

            tree[currTree]++;
            treeTotal++;
        }

        for (map<string, int>::iterator i = tree.begin(); i != tree.end(); i++)
        {
            cout << i->first << ' ' << fixed << setprecision(4) << i->second * (100.0 / treeTotal) << '\n';
        }

        if (testcases)
        {
            cout << '\n';
        }
    }

    return 0;
}