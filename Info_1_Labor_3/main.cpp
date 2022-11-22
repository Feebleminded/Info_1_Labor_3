/*
Titel: Informatik 1 Labor 3: Paarweiser Vergleich
Beschreibung:	Prioritätenanalyse über die Komandozeile erstellt werden. Eine maximal anzahl an von 10 Kriterien und
				die berechung von Summen für jedes Kriterium und ein Gewichtungsfaktor in %. Ausgabe in einer Tabelle.
Name:			Thomas Kühnel
Datum:			20.11.2022
*/

#include <string>
#include <iostream>;		//Bibliotheken einbindung
using namespace std;

string nutzereingabe;		//Variable für die Nutzereingabe der Kriterien
string kriterien[10];		//Array der eingegebenen Kriterien

int ergebnis[10][10];		//Array der eingegebenen Bewertung

float sums[10];				//Ergebnisse der Berechnuggen pro Krieterium als Summe
float gf[10];				//Ergebnisse der Berechnuggen pro Krieterium als %

int eingabeint;				//Variable für die Nutzereingabe der Bewertung
int kl = 10;				//Maximale anzahl an Kriterien


void clacsumsweights() {
	for (int m = 0; m <= kl; m++) {
		for (int n = 0; n <= kl; n++) {
			cout << ergebnis[m][n] << "    ";
		}											//Ausgabe der Berechnung
		cout << "    " << sums[m];
		cout << "    " << gf[m];
		cout << endl;
	}
}

void main() {

	for (int i = 0; i <= 9; i++) {

		cout << "Kriterium " << i + 1 << " --> ";

		cin >> nutzereingabe;					//Nutzer eingabe der Kriterien und 
												

		if (nutzereingabe == "0") {
			kl = i - 1;							//das Zählen der max Kriterien
			break;
		}
		kriterien[i] = nutzereingabe;
	}

	cout << "bewerten sie die Kriterien mit 0 / 1 / 2" << endl;


	for (int m = 0; m <= kl; m++) {					//Paarweiser Vergleich der Kriterien
												
		for (int n = m + 1; n <= kl; n++) {

			cout << kriterien[m] << " <-> " << kriterien[n] << ": ";	//Ausgabe der Vergleiche 

			cin >> eingabeint;				//Eingabe der bewertung vom Nutzer

			ergebnis[m][n] = eingabeint;	//Eintragen in das Ergebnis Array

			if (eingabeint == 0)			
				ergebnis[n][m] = 2;

			if (eingabeint == 1)			//Abfragen für die gespiegelte bewertung
				ergebnis[n][m] = 1;			//Eintragen der gespeigelten bewertung

			if (eingabeint == 2)
				ergebnis[n][m] = 0;
		}

	}


	for (int m = 0; m <= kl; m++) {

		for (int n = 0; n <= kl; n++) {			

			sums[m] = sums[m] + ergebnis[m][n];		//Berechene und Eintragen der ergebnisse in das sums Array
		}
	}

	for (int m = 0; m <= kl; m++) {

		float sumstemp = 0;

		for (int n = 0; n <= kl; n++)

			sumstemp = sumstemp + sums[n];

		gf[m] = sums[m] * 100 / sumstemp;			//Berechene und Eintragen der ergebnisse in das GF Array
	}

	clacsumsweights();
}