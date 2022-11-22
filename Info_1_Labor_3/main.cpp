#include <iostream>;
using namespace std;


string kriterien[10];
int ergebnis[10][10];
float sums[10];
float gf[10];
string nutzereingabe;
int eingabeint;
int kl = 10;



void clacsumsweights() {
	for (int m = 0; m <= kl; m++) {
		for (int n = 0; n <= kl; n++) {
			cout << ergebnis[m][n] << "    ";
		}
		cout << "    " << sums[m];
		cout << "    " << gf[m];
		cout << endl;
	}
}

void main() {

	for (int i = 0; i <= 9; i++) {

		cout << "Kriterium " << i + 1 << " --> ";

		cin >> nutzereingabe;


		if (nutzereingabe == "0") {
			kl = i - 1;
			break;
		}
		kriterien[i] = nutzereingabe;
	}

	cout << "bewerten sie die Kriterien mit 0 / 1 / 2" << endl;


	for (int m = 0; m <= kl; m++) {

		for (int n = m + 1; n <= kl; n++) {

			cout << kriterien[m] << " <-> " << kriterien[n] << ": ";

			cin >> eingabeint;

			ergebnis[m][n] = eingabeint;

			if (eingabeint == 0)
				ergebnis[n][m] = 2;

			if (eingabeint == 1)
				ergebnis[n][m] = 1;

			if (eingabeint == 2)
				ergebnis[n][m] = 0;
		}

	}


	for (int m = 0; m <= kl; m++) {

		for (int n = 0; n <= kl; n++) {

			sums[m] += ergebnis[m][n];
		}
	}

	for (int m = 0; m <= kl; m++) {

		float sumstemp = 0;

		for (int n = 0; n <= kl; n++)

			sumstemp += sums[n];

		gf[m] = sums[m] * 100 / sumstemp;
	}

	clacsumsweights();
}