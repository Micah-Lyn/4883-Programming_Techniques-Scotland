#include <iostream>

using namespace std;

int main() {
  
int T, emp1, emp2, emp3;

cin>> T;

int i; 
for(i = 0; i < T; i++) {
  
  cin>> emp1 >> emp2 >> emp3;

 if((emp1 > emp2 && emp1 < emp3) || (emp1 < emp2 && emp1 > emp3))
  cout << "Case "<< i+1 << ": "<< emp1 << "\n";
 else if ((emp2 > emp3 && emp2 < emp1) || (emp2 > emp1 && emp2 < emp3))
  cout << "Case "<< i+1 << ": " << emp2 << "\n";
  else cout << "Case "<< i+1 << ": " << emp3 << "\n";
}
  return 0;
}