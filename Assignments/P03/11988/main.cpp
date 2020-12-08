//http://www.cplusplus.com/forum/beginner/106288/
//https://www.tutorialspoint.com/check-if-a-string-contains-a-sub-string-in-cplusplus#:~:text=This%20find()%20method%20returns,will%20return%20string%3A%3Anpos.

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main()
{

  string strLine;

  stack<string> value;

  queue<char> thisQueue;

  while (getline(cin, strLine))
  {

    char str = 'Y';
    string tempStr = "";

    while (!value.empty())
      value.pop();

    while (!thisQueue.empty())
      thisQueue.pop();

    for (int i = 0; i < strLine.length(); i++)
    {

      if (strLine.at(i) == '[')
      {
        str = 'N';
      }

      if (str == 'N')
      {
        if (strLine.at(i) == ']')
        {
          if (tempStr != "")
            value.push(tempStr);
          tempStr = "";
          str = 'Y';
        }

        else
        {
          if (strLine.at(i) == '[')
          {
            if (tempStr != "")
              value.push(tempStr);
            tempStr = "";
            str = 'N';
          }
          else
          {
            tempStr += strLine.at(i);
          }
        }
      }
      else
      {
        if (strLine.at(i) != '[' && strLine.at(i) != ']')
          thisQueue.push(strLine.at(i));
      }
    }
    if (str == 'N')
      value.push(tempStr);
    tempStr = "";

    while (!value.empty())
    {
      cout << value.top();
      value.pop();
    }

    while (!thisQueue.empty())
    {
      cout << thisQueue.front();
      thisQueue.pop();
    }

    tempStr = "";

    cout << '\n';
  }
}
