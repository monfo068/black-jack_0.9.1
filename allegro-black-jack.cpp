#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdio>
#include "notallegro.cpp"
using namespace std;
/*poi allegro rendere tutto piu bello, mettere la message box, funzione 11 che non diventa 1*/
struct carsegn
{
	int carte;
	string segno;
};

void manouno(carsegn gio[], carsegn cru[])
{

	int app = 0, app2 = 0, a = 0;
	srand(time(0));
	app = rand() % 4;
	if (app < 3)
	{
		gio[0].carte = rand() % 10 + 2;
	}
	else
	{
		gio[0].carte = 10;
	}
	a = rand() % 4;
	if (a == 0)
	{
		gio[0].segno = "C ";
	}
	if (a == 1)
	{
		gio[0].segno = "Q ";
	}
	if (a == 2)
	{
		gio[0].segno = "F ";
	}
	if (a == 3)
	{
		gio[0].segno = "P ";
	}
	//
	app = rand() % 4;

	if (app < 3)
	{
		gio[1].carte = rand() % 10 + 2;
	}
	else
	{
		gio[1].carte = 10;
	}
	a = rand() % 4;
	if (a == 0)
	{
		gio[1].segno = "C ";
	}
	if (a == 1)
	{
		gio[1].segno = "Q ";
	}
	if (a == 2)
	{
		gio[1].segno = "F ";
	}
	if (a == 3)
	{
		gio[1].segno = "P ";
	}
	//
	app = rand() % 4;
	if (app < 3)
	{
		cru[0].carte = rand() % 10 + 2;
	}
	else
	{
		cru[0].carte = 10;
	}
	a = rand() % 4;
	if (a == 0)
	{
		cru[0].segno = "C ";
	}
	if (a == 1)
	{
		cru[0].segno = "Q ";
	}
	if (a == 2)
	{
		cru[0].segno = "F ";
	}
	if (a == 3)
	{
		cru[0].segno = "P ";
	}
	//
	app = rand() % 4;
	if (app < 3)
	{
		cru[1].carte = rand() % 10 + 2;
	}
	else
	{
		cru[1].carte = 10;
	}
	a = rand() % 4;
	if (a == 0)
	{
		cru[1].segno = "C ";
	}
	if (a == 1)
	{
		cru[1].segno = "Q ";
	}
	if (a == 2)
	{
		cru[1].segno = "F ";
	}
	if (a == 3)
	{
		cru[1].segno = "P ";
	}
}

void blackjack(carsegn cru[], int &credit, int &punt, string &contr)
{
	cout << "blackjack" << endl;
	if ((cru[0].carte + cru[1].carte) == 21)
	{
		cout << endl
			 << "pareggio";
	}
	else
	{
		cout << "Hai vinto" << endl;
		credit += punt + punt;
	}
	cout << endl
		 << "vuoi continuare? scrivi [y]es o [n]ot ";
	cin >> contr;
	cout << endl
		 << "hai " << credit << " fish" << endl;
}

void giocate(carsegn gio[], carsegn cru[], int &punt, int &credit, string name, string &contr) // note sopra
{
	int so = gio[0].carte + gio[1].carte, sc = cru[0].carte + cru[1].carte, controllo = 0, a = 0, app2 = 2, mae = 0, yu = 2;
	string pesca = "y";
	cout << name << " le tue carte sono " << gio[0].carte << gio[0].segno << gio[1].carte << gio[1].segno << endl
		 << "somma delle tue carte " << gio[0].carte + gio[1].carte << endl
		 << "carta croupier " << cru[0].carte << cru[0].segno << endl;
	srand(time(0));
	do
	{
		cout << endl
			 << "vuoi pescare? scrivi [y]es o [n]ot ";
		cin >> pesca;
		if (pesca == "y")
		{
			for (int i = app2; i < app2 + 1; i++)
			{
				a = rand() % 10 + 2;
				if ((so > 21) && (a == 11))
				{
					gio[i].carte = 1;
					so += gio[i].carte;
				}
				else
				{
					gio[i].carte = a;
					so += gio[i].carte;
				}
			}
			cout << "carte: ";
			for (int i = 0; i < app2 + 1; i++)
			{
				cout << gio[i].carte << gio[i].segno << " ";
			}
			cout << endl
				 << "somma delle carte=" << so;
			if (so > 21)
			{
				controllo = 10;
				if (controllo == 10)
				{
					cout << endl
						 << name << " hai sballato!!";
					credit -= punt;
					pesca = "n";
				}
			}
			app2++;
		}
	} while (pesca != "n");
	if (controllo != 10)
	{
		cout << "crupier mano:";
		for (int i = 0; i < 10; i++)
		{
			if (cru[i].carte != 0)
			{
				cout << cru[i].carte << cru[i].segno;
			}
		}
		cout << endl;
		while (sc <= 16)
		{
			mae = rand() % 10 + 2;
			cru[yu].carte = mae;
			sc += mae;
			cru[yu].carte = mae;
			cout << "mano crupier:";
			for (int i = 0; i < 10; i++)
			{
				if (cru[i].carte != 0)
				{
					cout << cru[i].carte << cru[i].segno;
				}
			}
			yu++;
			cout << "il crupier ha " << sc << endl;
			for (int i = 0; i < 10; i++)
			{
				if (sc > 22)
				{
					if (cru[i].carte == 11)
					{
						cru[i].carte = 1;
					}
				}
			}
		}
		if (sc < 22)
		{
			if ((sc > so) || (sc == so))
			{
				cout << name << " hai perso!!";
				credit -= punt;
			}
			else
			{
				cout << name << " hai vinto!!";
				credit += punt;
			}
		}
		else
		{
			cout << name << " hai vinto!! il crupier ha sballato!! ";
			credit += punt;
		}
	}
	cout << endl
		 << "vuoi continuare? scrivi [y]es o [n]ot ";
	cin >> contr;
	cout << endl
		 << "hai " << credit << " fish" << endl;
}
void divisione(carsegn gio[], carsegn cru[], int punt, int &credit, string name, string &contr) // nota sopra
{
	const int n = 10;
	carsegn gio2[n];
	int app = 0, app2 = 0, app3 = 2, app4 = 2, so = 0, so2 = 0, sc = 0, yu = 2, mae = 0, it = 0;
	string scelta = " ", scelta2 = " ";
	gio2[0].carte = gio[1].carte;
	gio[1].carte = 0;
	srand(time(0));
	app = rand() % 2;
	if (app == 0)
	{
		app2 = rand() % 10 + 2;
		gio[1].carte = app2;
	}
	if (app == 1)
	{
		gio[1].carte = 10;
	}
	app = rand() % 2;
	if (app == 0)
	{
		app2 = rand() % 10 + 2;
		gio2[1].carte = app2;
	}
	if (app == 1)
	{
		gio2[1].carte = 10;
	}
	so = gio[0].carte + gio[1].carte;
	so2 = gio2[0].carte + gio2[1].carte;
	do
	{
		cout << "mano 1:";
		for (int i = 0; i < 10; i++)
		{
			if (gio[i].carte != 0)
			{
				cout << gio[i].carte << gio[i].segno;
			}
		}
		cout << " somma=" << so << endl;
		cout << "mano 1 vuoi pescare? scrivi [y]es o [n]ot: ";
		cin >> scelta;
		if (scelta != "n")
		{
			app = rand() % 2;
			if (app == 0)
			{
				app2 = rand() % 10 + 2;
				gio[app3].carte = app2;
				so += app2;
			}
			if (app == 1)
			{
				gio[app3].carte = 10;
				so += 10;
			}
		}
		app3++;
	} while ((scelta != "n") && (so < 22));
	if (so > 21)
	{
		cout << "hai sballato con la prima mano" << endl;
		credit -= punt;
		cout << "fish=" << credit << endl;
	}
	do
	{
		cout << "mano 2:";
		for (int i = 0; i < 10; i++)
		{
			if (gio2[i].carte != 0)
			{
				cout << gio2[i].carte << gio[i].segno;
			}
		}
		cout << " somma=" << so2 << endl;
		cout << "mano 2 vuoi pescare? scrivi [y]es o [n]ot: ";
		cin >> scelta2;
		srand(time(0));
		if (scelta2 != "n")
		{
			app = rand() % 2;
			if (app == 0)
			{
				app2 = rand() % 10 + 2;
				gio2[app4].carte = app2;
				so2 += app2;
			}
			if (app == 1)
			{
				gio2[app4].carte = 10;
				so2 += 10;
			}
		}
		app4++;
	} while ((scelta2 != "n") && (so2 < 22));
	if (so2 > 21)
	{
		cout << "hai sballato con la seconda mano" << endl;
		credit -= punt;
		cout << "fish=" << credit << endl;
	}
	if ((so > 21) && (so2 > 21))
	{
		cout << "hai sballato con entrabbe le mani" << endl;
		cout << "fish=" << credit << endl;
	}
	if ((so < 22) || (so2 < 22))
	{
		cout << "crupier mano:";
		for (int i = 0; i < 2; i++)
		{
			cout << cru[i].carte << cru[i].segno;
		}
		cout << endl;
		sc = cru[0].carte + cru[1].carte;
		while (sc <= 16)
		{
			mae = rand() % 10 + 2;
			cru[yu].carte = mae;
			sc += mae;
			cout << "mano crupier:";
			for (int i = 0; i < 10; i++)
			{
				if (cru[i].carte != 0)
				{
					cout << cru[i].carte << cru[i].segno;
				}
			}
			yu++;
			cout << "il crupier ha " << sc << endl;
			// correggi sto ciclo
			for (int i = 0; i < 10; i++)
			{
				if (sc > 22)
				{
					if (cru[i].carte == 11)
					{
						cru[i].carte = 1;
					}
				}
			}
		}
		if (sc < 22)
		{
			if ((sc > so) || (sc == so))
			{
				cout << name << " hai perso!! con la prima mano " << endl;
				credit -= punt;
			}
			else
			{
				cout << name << " hai vinto!! con la prima mano " << endl;
				credit += punt;
			}
		}
		else
		{
			cout << name << " hai vinto con la prima mano!! il crupier ha sballato!!" << endl;
			credit += punt;
			it++;
		}
	}
	if (so2 < 22)
	{
		if (sc < 22)
		{
			if ((sc > so2) || (sc == so2))
			{
				cout << name << " hai perso!! con la seconda mano " << endl;
				credit -= punt;
			}
			else
			{
				cout << name << " hai vinto!! con la seconda mano " << endl;
				credit += punt;
			}
		}
		if (it == 1)
		{
			cout << name << " hai vinto con la seconda mano!!  il crupier ha sballato!!" << endl;
			credit += punt;
		}
	}
	cout << endl
		 << "vuoi continuare? scrivi [y]es o [n]ot ";
	cin >> contr;
	cout << endl
		 << "hai " << credit << " fish" << endl;
}
void assic(carsegn cru[], int punt, int &credit, int &appp)
{
	string app = " ";
	int app2 = punt / 2;
	cout << endl
		 << "vuoi fare l'assicurazione? [y]es o [n]o ";
	cin >> app;
	if (app == "y")
	{
		if (cru[1].carte == 10)
		{
			credit += app2;
			credit -= punt;
			appp = 10;
			cout << endl
				 << "black-jack da parte del crupier " << credit;
		}
		else
		{
			credit -= app2;
			cout << "si continua" << endl;
		}
	}
	if (app == "n")
	{
		if (cru[1].carte == 10)
		{
			credit -= punt;
			appp = 10;
			cout << "il crupier ha fatto black-jack " << credit;
		}
		else
		{
			cout << "si continua" << endl;
		}
	}
}
void reg(int primavolta)
{
	srand(time(0));
	const int n = 10;
	carsegn gio[n], cru[n];
	int punt = 0, credit = 0, appp = 0; // note sopra
	string name, contr = "", div = " ";
	if (primavolta != 33)
	{
		creditoper(credit);
		if (credit > 0)
		{
			nam(name, credit);
		}
		else
		{
			haipers(name, credit);
		}
	}
	else
	{
		prima(name, credit);
	}
	if (credit > 0)
	{
		do
		{
			Sleep(1450);
			system("cls");
			do
			{
				if (punt > credit)
				{
					cout << "dottore non puo puntare piu di quanto ha, non deve diventare ludopatico!!" << endl;
				}
				cout << "quanto vuoi puntare: ";
				cin >> punt;
			} while (punt > credit);
			manouno(gio, cru);
			appp = 0;
			if (cru[0].carte == 11)
			{
				assic(cru, punt, credit, appp);
			}
			if ((gio[0].carte == 11) && (gio[1].carte == 11) && (appp != 10))
			{
				manouno(gio, cru);
			}
			if (((gio[0].carte + gio[1].carte) == 21) && (contr != "n") && (appp != 10))
			{
				system("color a");
				blackjack(cru, credit, punt, contr);
			}
			if ((gio[0].carte == gio[1].carte) && (contr != "n") && (appp != 10))
			{
				system("color c");
				cout << gio[0].carte << gio[0].segno << gio[1].carte << gio[1].segno << endl
					 << "somma carte=" << gio[0].carte + gio[1].carte << endl
					 << "carta crupier " << cru[0].carte << cru[0].segno << endl;
				cout << "vuoi dividere? [y]es o [n]o ";
				cin >> div;
				if (div == "y")
				{
					credit -= punt;
					divisione(gio, cru, punt, credit, name, contr);
				}
			}
			if (((gio[0].carte + gio[1].carte) != 21) && (div != "y") && (contr != "n") && (appp != 10))
			{
				system("color b");
				giocate(gio, cru, punt, credit, name, contr);
			}
			div = " ";
			ofstream documento("file/credito.txt");
			documento << credit;
			documento.close();
			if (credit < 1)
			{
				haipers(name, credit);
			}
		} while ((contr != "n") && (credit > 0));
	}
}
int main() // almeno questo e' apposto
{
	clock_t start, end;
	int tempo, tp2;
	start = clock();
	ifstream tpo("file/tempo.txt");
	while (tpo >> tp2)
	{
	}
	int primavolta = 0;
	if (tp2 < 4)
	{
		primavolta = 33;
		cout << "non hai mai giocato ecco le regole";
		Sleep(1800);
		system("cls");
		regole();
		Sleep(2000);
		reg(primavolta);
	}
	else
	{
		
		cout << "1) GIOCA " << endl
			 << "2) REGOLE" << endl;
		char a = _getch();
		if (a == '1')
		{
			reg(primavolta);
		}
		if (a == '2')
		{
			regole();
			cout << "Ora sei pronto a giocare" << endl;
			reg(primavolta);
		}
	}
	cout << endl;
	end = clock();
	tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
	tp2 += tempo;
	ofstream tep("file/tempo.txt");
	tep << tp2;
	tep.close();
	Sleep(2000);
	return 0;
}
