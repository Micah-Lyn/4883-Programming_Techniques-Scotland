#include<iostream>
#include<stdio.h>
#include<queue>
#include<map>
#include<string>
 
using namespace std;
 
 
int main(){

      int testcases,tSize,t;

      string command;

      int scenNum = 1;
     

     
     c: cin >> testcases;

     if(testcases != 0){

     map<int, int>matchT;

  
      queue<int> team,tMates[1001];

      cout<< "Scenario #" << scenNum << '\n';

      while(testcases--){

          cin >> tSize;

          for(int i = 0 ; i<tSize ; i++){

               cin >> t;
               matchT[t] =  testcases;
          }
      }
      while(true){

             cin >> command;

             if(command.at(0)=='D'){

                   if(tMates[matchT[team.front()]].size()==1){

                         cout << tMates[matchT[team.front()]].front() << '\n';
                         tMates[matchT[team.front()]].pop();
                         team.pop();
                   }

                   else {

                      cout << tMates[matchT[team.front()]].front() << '\n';
                      tMates[matchT[team.front()]].pop();
                   }

             }
             else if(command.at(0)=='E'){

                   cin >> tSize;


                   if(!tMates[matchT[tSize]].empty()){

                         tMates[matchT[tSize]].push(tSize);

                   }
                   else
                   {   
                           team.push(tSize);
                          tMates[matchT[tSize]].push(tSize);
                   }
              }
              else {
               
                 cout << endl;
                 scenNum++;
                
                 goto c;
              }
          }
     }
     
      return 0;
}