//http://www.cplusplus.com/forum/beginner/106288/
//https://www.tutorialspoint.com/check-if-a-string-contains-a-sub-string-in-cplusplus#:~:text=This%20find()%20method%20returns,will%20return%20string%3A%3Anpos. 

#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int main() {

string strLine;
char str;
queue<string> thisQueue;
queue<char> thatQueue;


while (getline(cin,strLine)){

  int lineLength = strLine.size();

    bool bracket = false;
    
    string tempStr;
    for (size_t i = 0; i < lineLength; ++i)
    { 
        char ch = strLine.at(i);
        if (ch == '[') 
           bracket = true;
        
        if(bracket){
          if (ch == '['){
            if(tempStr != ""){
            thisQueue.push(tempStr);
            bracket = true;
            tempStr= "";
            }
          } 
          else if ( ch == ']'){
          if ( tempStr != ""){
           thisQueue.push(tempStr);
            bracket = false;
            tempStr = "";
          }
          }      
          else {
            tempStr += ch;
          }  
          }
        else
        if ( !bracket) {
          if(ch!='[' && ch!= ']')
           thatQueue.push(ch);
        }
     }

if(bracket){
  thisQueue.push(tempStr);
  tempStr="";
}



while (!thisQueue.empty()){
  if(thisQueue.front() != "[" && thisQueue.front() != "]")
  cout<< thisQueue.front();
  thisQueue.pop();
}

while (!thatQueue.empty()){
 if(thatQueue.front() != '[' && thatQueue.front() != ']')
  cout<< thatQueue.front();
  thatQueue.pop();

}
 cout << "\n";
}
return 0;
}


