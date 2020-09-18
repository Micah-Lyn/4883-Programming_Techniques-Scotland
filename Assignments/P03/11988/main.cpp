#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

std::string extract(const std::string& str, char beg, char end)
{
    std::size_t begPos ;
    if ( (begPos = str.find(beg)) != std::string::npos )
    {
        std::size_t endPos ;
        if ( (endPos = str.find(end, begPos)) != std::string::npos && endPos != begPos+1 )
            return str.substr(begPos+1, endPos-begPos-1) ;
    }

    return string() ;
}


int main() {

string strLine;
char str;
queue<string> thisQueue;
queue<string> thatQueue;


while (getline(cin,strLine)){

  int lineLength = strLine.size();

  string original(strLine) ;
    string temp = extract(original, '[', ']');
    if (temp != "" && temp != "[" && temp != "]"){

    thisQueue.push(temp);
    }
    bool inbracket = false;
    string outStr;
    for (size_t i = 0; i < lineLength; ++i)
    { 
        char ch = strLine.at(i);
        if (ch == '[') 
           inbracket = true;
        else
        if ( ch == ']')
           inbracket = false;
        else
        if ( !inbracket) {
          if(ch!='[' && ch!= ']')
           outStr += ch;
        }
     }
     strLine = outStr;
    thatQueue.push(strLine);



while (!thisQueue.empty()){
  cout<< thisQueue.front();
  thisQueue.pop();
}

while (!thatQueue.empty()){
  cout<< thatQueue.front();
  thatQueue.pop();

}
 cout << "\n";
}
return 0;
}


