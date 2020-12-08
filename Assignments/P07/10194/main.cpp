#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

struct team{
	string name;
  int win = 0, tie= 0, loss = 0;
	int gScore, gAgainst;
	
};


bool compare(struct team A, struct team B){

	int playA, playB;

	playA = A.win * 3 + A.tie;
	playB = B.win * 3 + B.tie;

	if (playA > playB) {
  	return true;

  }

  
	if (playB > playA)	{
    return false;

  }

  
	if (A.win > B.win){
  	return true;
  }


	if (A.win < B.win) {
    	return false;

  }

	if (A.gScore - A.gAgainst> B.gScore - B.gAgainst){
    	return true;

  }

	if (A.gScore - A.gAgainst<B.gScore - B.gAgainst){
    	return false;

  }

	if (A.gScore > B.gScore){	
    return true;

  }

	if (A.gScore < B.gScore) {
    	return false;

  }

	playA = A.win + A.tie + A.loss;

	playB = B.win + B.tie + B.loss;


	if (playA > playB) {
    	return false;

  }

	if (playA < playB){
    	return true;

  }

	for (int i = 0;; i++){ 

		char a = A.name[i];

		char b = B.name[i];

		if (a >= 'A'&& a <= 'Z')
    	a += 32;

		if (b >= 'A'&& b <= 'Z')
    	b += 32;

		if (a == '\0'){
      	return true;
    }

		if (b == '\0'){	
      return false;

    }

		if (a > b) {	
      return false;

    }

		if (a < b){	
      return true;

    }

	}
}


int main(){

	int tNum;

	cin >> tNum;
	
  getchar();

	while (tNum--){

		struct team cTeams[30];

		string tName;

		getline(cin, tName);

		int numTeam;

		cin >> numTeam;

		getchar();

		for (int i = 0; i < numTeam; i++){

			getline(cin, cTeams[i].name);

			cTeams[i].gAgainst = 0;
			cTeams[i].gScore = 0;
			cTeams[i].loss = cTeams[i].tie = cTeams[i].win = 0;
		}

    int gameNum; 
		cin >> gameNum;

		getchar();

		for (int j = 0; j < gameNum; j++){

			int a, AS = 0, BS = 0;

			string TA, TB, R;

			getline(cin, R);

			for (a = 0; R[a] != '#'; a++)	
         TA.push_back(R[a]);

			for (a++; R[a] != '@'; a++)	
          AS = AS * 10 + R[a] - '0';

			for (a++; R[a] != '#'; a++)
      	BS = BS * 10 + R[a] - '0';

			for (a++; R[a] != '\0'; a++)
      	TB.push_back(R[a]);

			for (int k = 0; k < numTeam; k++){

				if (cTeams[k].name == TA){

					cTeams[k].gScore += AS;

					cTeams[k].gAgainst += BS;

					if (AS > BS){
          	cTeams[k].win++;
          }

					if (AS == BS){
          	cTeams[k].tie++;
          }
          
					if (AS < BS) {	
            cTeams[k].loss++;
          }

				}

				if (cTeams[k].name == TB){

					cTeams[k].gScore += BS;
					cTeams[k].gAgainst += AS;

					if (AS < BS){
            	cTeams[k].win++;
          }

					if (AS == BS){	
            cTeams[k].tie++;

          }

					if (AS > BS){
            	cTeams[k].loss++;

          }
				}
			}
		}

		sort(cTeams, cTeams + numTeam, compare);

		cout << tName << endl;

		for (int i = 0; i < numTeam; i++){

			cout << i + 1 << ") " << cTeams[i].name << " " << 
        cTeams[i].win * 3 + cTeams[i].tie << "p, ";

			cout << cTeams[i].win + cTeams[i].loss + cTeams[i].tie << "g (" 
         << cTeams[i].win << "-" << cTeams[i].tie << "-" << cTeams[i].loss << "), ";


			cout << cTeams[i].gScore - cTeams[i].gAgainst << "gd (" << 
        cTeams[i].gScore << "-" << cTeams[i].gAgainst << ")" << endl;

		}

		if (tNum != 0)
			cout << endl;

	}
	return 0;
}

