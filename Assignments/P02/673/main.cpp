#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int num;

    string AB;

    cin >> num;

    getline(cin, AB);

    while (num--)
    {

        getline(cin, AB);

        stack<char> brace;

        if (AB.size() % 2 == 0)
        {

            for (int i = 0; i < AB.size(); i++)
            {

                if (AB[i] == '(' || AB[i] == '[')
                {
                    brace.push(AB[i]);
                }
                else if (!brace.empty())
                {

                    if (AB[i] == ']' && brace.top() == '[')
                    {
                        brace.pop();
                    }

                    if (AB[i] == ')' && brace.top() == '(')
                    {
                        brace.pop();
                    }
                }
            }

            if (brace.empty())
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
