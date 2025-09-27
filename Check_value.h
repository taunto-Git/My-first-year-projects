#include <iostream>
using namespace std;

//library for doing a cout,cin, and also checking if the type of value is right

int check_int(string frase) {
	int test;
	cout << frase << endl;
	while (true)
	{
		cin >> test;
		if (cin.fail()) {
        	(cin.clear());
        	cin.ignore(1000,'\n');
        	cout << "not a valid integer" << endl;
		}
		else {
			break;
		}
	}
	return test;
}

float check_float(string frase) {
	float test;
	cout << frase << endl;
	while (true)
	{
		cin >> test;
		if (cin.fail()) {
        	(cin.clear());
        	cin.ignore(1000,'\n');
        	cout << "not a valid float" << endl;
		}
		else {
			break;
		}
	}

	return test;
}

double check_double(string frase) {
	double test;
	cout << frase << endl;
	while (true)
	{
		cin >> test;
		if (cin.fail()) {
        	(cin.clear());
        	cin.ignore(1000,'\n');
        	cout << "not a valid double" << endl;
		}
		else {
			break;
		}
	}
	return test;
}

char check_char(string frase) {
	char test;
	cout << frase << endl;
	while (true)
	{
		cin >> test;
		if (cin.fail()) {
			(cin.clear());
			cin.ignore(1000,'\n');
			cout << "not a valid char" << endl;
		}
		else {
			break;
		}
	}
	return test;
	
}

