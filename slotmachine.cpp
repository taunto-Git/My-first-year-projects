#include <iostream>
#include <random>
#include <iomanip>
#include <windows.h>
using namespace std;

//struct for keeping track of wins and stats
struct Nvinci {
	int V=0;
	int G=0;
	int cash=0;
	int triplo=0;
};

void vincite(Nvinci&NV);
int main() {
	Nvinci NV; //struct instance
	//arrays for slot machine numbers
	int N1[9] {1,2,3,4,5,6,7,8,9};
	int N2[9] {1,2,3,4,5,6,7,8,9};
	int N3[9] {1,2,3,4,5,6,7,8,9};
	int money,num1,num2,num3;
	string com;
	cout << "welcome to the slot machine" << endl;
	cout << "insert money" << endl;
	cin >> money;
	//main game loop
	while (true) {
	random_device rd;
	mt19937 gen1(rd());
	mt19937 gen2(rd());
	mt19937 gen3(rd());
	uniform_int_distribution<int> dist1(0,8);
	uniform_int_distribution<int> dist2(0,8);
	uniform_int_distribution<int> dist3(0,8);
	num1=dist1(gen1);
	num2=dist2(gen2);
	num3=dist3(gen3);
	if (money<10) {
		cout << "cash finished" << endl;
		vincite(NV);
	}
	cout << "type spin to start" << endl;
		cout << setfill (' ') << setw(40) << ' ' << setfill (' ') << " " << NV.V << endl;
		if (NV.G>=10) {
		cout << setfill (' ') << setw(40) << ' ' << setfill (' ') << " " << NV.G << endl;
		}
		cout << setfill (' ') << setw(40) << ' ' << setfill (' ') << " " << money << "$" << endl;
	cin >> com;
		if (com=="spin") {
			NV.cash=NV.cash-10;
			money=money-10;
			NV.G=NV.G+1;
			cout << N1[num1] << " " << N2[num2] << " " <<  N3[num3] <<endl;
			if (N1[num1]==9 && N2[num2]==9 && N3[num3]==9) {
				cout << "!!! great win! +50$ !!!" << endl;
				money=money+50;
				NV.cash=NV.cash+50;
				NV.V=NV.V+1;
			}
			else if (N1[num1]==7 && N2[num2]==7 && N3[num3]==7) {
				cout << "!!! great win! +100$ !!!" << endl;
				money=money+100;
				NV.cash=NV.cash+100;
				NV.V=NV.V+1;
				NV.triplo=NV.triplo+1;
				if (NV.triplo==3) {
					money=money+(1100-100);
				}
			}
			else if (N1[num1]==6 && N2[num2]==6 && N3[num3]==6) {
				cout << "triple 6! -10$" << endl;
				money=money-10;
			}
			else if (N1[num1]==N2[num2] && N2[num2]==N3[num3]) {
				money=money+20;
				cout << "you won 20$!" << endl;
				NV.V=NV.V+1;
				NV.cash=NV.cash+20;
			} 
			else if (N1[num1]==N2[num2] || N1[num1]==N3[num3] || N2[num2]==N3[num3]) {
				cout << "you won 5$!" << endl;
				money=money+5;
				NV.cash=NV.cash+5;
				NV.V=NV.V+1;
			}
		}
		else if (com=="cashout") {
			vincite(NV);
		}
		else continue;
	}
}

//function to display final stats and exit
void vincite(Nvinci&NV) {
	cout << "cash finished! here are your results" << endl;
	cout << "money: " << endl;
	cout << NV.cash << "$" << endl;
	cout << "spins: " << endl;
	cout << NV.G << endl;
	cout << "wins: " << endl;
	cout << NV.V << endl; 
	Sleep (10000);
	exit (0);
}
