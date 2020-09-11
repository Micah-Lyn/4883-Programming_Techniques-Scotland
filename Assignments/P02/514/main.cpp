#include <iostream>
#include <stack>

using namespace std;

int testcases;

void line()
{

    int coach[1000], c;
    bool t;

    stack<int> carStation;

    while (cin >> coach[0])
    {
        if (coach[0] == 0)
            break;

        while (!carStation.empty())
            carStation.pop();

        c = 1;
        t = true;

        int j = 1;

        while (j < testcases)
        {

            cin >> coach[j];
            j++;
        }

        for (int i = 0; i < testcases; i++)
        {

            if (coach[i] > c)
            {

                while (coach[i] != c)
                {

                    carStation.push(c);
                    c++;
                }
                c++;
                continue;
            }
            else if (coach[i] < c)
            {

                if (carStation.size() > 0 && carStation.top() == coach[i])
                {
                    carStation.pop();
                    continue;
                }

                t = false;
                break;
            }

            else
            {
                c++;
                continue;
            }
        }

        if (t)
        {

            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}

int main()
{

    while (cin >> testcases)
    {

        if (testcases == 0)
        {
            break;
        }

        line();

        cout << "\n";
    }
    return 0;
}
