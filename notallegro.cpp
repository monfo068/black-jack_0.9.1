#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <fstream>
#include <Windows.h>
#include <conio.h>
using namespace std;
void haipers(string &name, int &credit)
{
	system("cls");
	cout << "hai perso tutte le fish il tuo accunt e' stato eliminato come ti vuoi chiamare?" << endl;
	cin >> name;
	ofstream documento("file/name.txt");
	documento << name;
	documento.close();
	int app3 = 10000;
	ofstream ciao("file/credito.txt");
	ciao << app3;
	ciao.close();
	credit = 10000;
	cout << name << " hai " << credit << " fish" << endl;
}
void prima(string &name, int &credit)
{
	system("cls");
	cout << " come ti vuoi chiamare?" << endl;
	cin >> name;
	ofstream documento("file/name.txt");
	documento << name;
	documento.close();
	int app3 = 10000;
	ofstream ciao("file/credito.txt");
	ciao << app3;
	ciao.close();
	credit = 10000;
	cout << name << " hai " << credit << " fish" << endl;
}
void creditoper(int &credit)
{
	ifstream ducumento("file/credito.txt");
	while (ducumento >> credit)
	{ // perfetto
	}
}
void nam(string &name, int &credit) // perfetto
{
	string app;
	ifstream ducumento("file/name.txt");
	while (ducumento >> name)
	{
	}
	cout << "vuoi continuare il game come " << name << " con " << credit << " fish "
		 << "[y]es o [n]o" << endl;
	cin >> app;
	if (app != "n")
	{
		cout << "ok puoi continuare" << endl;
	}
	else
	{
		cout << "sei sicuro? scrivi [y]es se vuoi confermare se no [n]o" << endl;
		cin >> app;
		if (app == "y")
		{
			cout << "come ti vuoi chiamare " << endl;
			cin >> name;
			ofstream documento("file/name.txt");
			documento << name;
			documento.close();
			int app3 = 10000;
			ofstream ciao("file/credito.txt");
			ciao << app3;
			ciao.close();
		}
		credit = 10000;
		cout << "ti chiami " << name << " e hai " << credit << " fish ";
	}
}

void regole()
{
	system("start www.pokerstars.it/casino/how-to-play/blackjack/rules"); // gls
}