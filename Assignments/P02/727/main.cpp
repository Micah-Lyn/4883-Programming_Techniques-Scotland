#include <iostream>
#include <stack>

using namespace std;

int main()
{

    int testcases;

    char optr;

    stack<char> expression;

    cin >> testcases;
    cin.ignore();

    while (testcases--)
    {
        cin.ignore();

        while (cin.peek() != '\n' && !cin.eof())
        {
            cin >> optr;
            cin.ignore();

            if (optr == '(' || optr == '+' || optr == '-' || optr == '*' || optr == '/')
            {

                if (!expression.empty())
                {
                    if (optr == '(')
                    {
                        expression.push(optr);
                    }
                    else
                    {
                        while (!expression.empty() && expression.top() != '(')
                        {
                            if ((optr == '/' || optr == '*') <= (expression.top() == '/' || expression.top() == '*'))
                            {
                                cout << expression.top();
                                expression.pop();
                            }
                            else
                            {
                                break;
                            }
                        }
                        expression.push(optr);
                    }
                }
                if (expression.empty())
                {
                    expression.push(optr);
                }
            }
            else if (optr == ')')
            {
                while (expression.top() != '(')
                {
                    cout << expression.top();
                    expression.pop();
                }
                expression.pop();
            }
            else
            {
                cout << optr;
            }
        }

        while (!expression.empty())
        {

            cout << expression.top();
            expression.pop();
        }
        cout << '\n';

        if (testcases > 0)
            cout << '\n';
    }
    return 0;
}
