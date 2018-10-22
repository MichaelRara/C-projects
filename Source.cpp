#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include "Matice.h"
#include "Vektor.h"
//#include "Person.h"
//#include "History.h"
#include "Primka.h"
#include <fstream>
#include <vector>
using namespace std;

int main(void)
{
	locale loc("Czech_Czech Republic.1250");
	locale::global(loc);
	//ofstream Mat;
	//Mat.open("test.txt"); //Vytvoøí, nebo otevøe soubor test.txt ve složce Matematika
	//Mat << " 3 4 4\n 7 8 8\n 0 -2 -7"; // Zapíše do souboru test.txt matici 3 4\n 7 8
	//Mat.close();
	char volba;
	cout<<"Chceš-li zadat matici z txt soubotu stiskni 't' pro standartní zadání pomocí klávesnice stiskni 'k'"<<endl;
	cin >> volba;
	if (volba=='t')
	{
		//Mat.open("test.txt");
		string line; 
		int n=0;// n= poèet øádkù
		vector<string> arr;//vektor øádkù souboru test.txt
		vector<int> d;//vektor délek øádkù
		ifstream Mat("test.txt");
		while (getline(Mat,line)) //naète øádek ze souboru test.txt
		{
			n++;					// poèet øádkù se zvýší o +1
			cout << line << '\n';
			int s = line.size(); //délka øádku vèetnì mezer 
			d.push_back(s); //naète délku aktiálního øádku do vektoru d
			arr.push_back(line); //do vektoru arr se na první (druhou, tøetí...) pozici uloží aktuální øádek
		}
		int ss = line.size();
		int s = ss-1;//s= délka øádku bez posledího null characteru tj. znak \0
		
		for (int i = 0; i < s; i++)
		{
			if (line[i]=' ')//kdykoliv najde v øádku mezeru, sníží se délka øádku o -1, nakonec dostaneme poèet prvkù v øádku
				s--;
		}
		cout << s << endl;
		double** L = new double*[n];//Deklarujeme matici soustavy
		for (int i = 0; i < n; i++)
		{
			double* l = new double[s];
			int r = 0;//pomocí r posouváme index u pointeru l
			for (int j = 0; j < d[i]; j++)
			{
				if ((arr[i][j] != ' ') && (arr[i][j] != '-'))
				{
					line = arr[i][j] + '\0';//aby funkce ::atof fungovala (pøevede string na double), potøebuje na konci null pointer tj. \0
					if (arr[i][j-1] == '-')//pokud byl pøedchozí znak v øetìzci øádku -, pak následující èíslo je záporné
						*(l + r) = (-1)*::atof(line.c_str());
					else 
						*(l + r) = ::atof(line.c_str());
					cout << *(l + r) << " ";
					r++;
				}
			}
			L[i] = l;// naète øádek do matice
			cout << endl;
		}
		Matice v(L, n, s);//vytvoøí instanci matice ze souboru test.txt
		v.vypis();
		int w = 3;
		double* p = new double[w];//Vektor pravé strany
		for (int i = 0; i < w; i++)
		{
			*(p + i) = i;
		}
		double* t = v.Cramer(p);// Pomocí Cramerovy metody spoète øešení soustavy
		if (t != nullptr) // pokud má soustava øešení
		{
			cout << "Øešení: " << endl;
			for (int i = 0; i < w; i++)//Vypíše øešení
			{
				cout << *(t + i) << ", " << endl;
			}
		}
	}
	else
	{
		int w = 3;
		Matice m(w, w);//Zadání matice
		m.vypis();//Výpis matice
		double* p = new double[w];//Vektor pravé strany
		*(p) = 0;
		*(p + 1) = 1;
		*(p + 2) = -6;
		/*for (int i = 0; i < w; i++)
		{
			*(p + i) = i;
		}*/
		double* t = m.Cramer(p);// získáme vektor øešení
		if (t!=nullptr)// pokud øešení existuje
		{
			cout << "Øešení: " << endl;
			for (int i = 0; i < w; i++)//Vypíše øešení
			{
				cout << *(t + i) << ", " << endl;
			}
		}
	}
	

	/*int w = 1;
	Matice m(w, w);
	m.vypis();
	double* p = new double[w];
	for (int i = 0; i < w; i++)
	{
		*(p + i) =i ;
	}
	double* t=m.Cramer(p);
	cout<<"Øešení: "<<endl;
	for (int i = 0; i < w; i++)
	{
		cout <<*(t+i)<<", " <<endl;
	}*/

	//double** E=m.Diagonal();
	//m.Hodnost();
	//double p=m.Determinant();
	//cout << p << endl;
	cout << "Zadej dimenzi" << endl;
	int n; cin >> n;
	Primka v(n);
	v.vypis();
	Primka w(n);
	w.vypis();
	double a = v.Ssoucin(w.p);
	cout << a << endl;
	w.poloha(v);



	//Vektor x(n);
	//x.vektor();
	//Primka q(n);
	/*cout << q.p << endl;
	cout << q.n << endl;*/
	//double* m = q.p;
	/*cout<<*(m+0) <<endl;
	cout<<*(m+1) <<endl;*/

	//q.primka();
	//q.vypis();
	//Primka p(n);
	//double* t = p.p;
	/*cout << *(t + 0) << endl;
	cout << *(t + 1) << endl;*/
	//p.primka();
//	system("cls");
	//q.vypis();
	//p.vypis();
	//cout<<"Úhel mezi tìmito pøímkami je: "+to_string(Primka::angle(q,p))<<"°" <<endl;

	//q.poloha(p);

	//cout << "Normálový vektor tìchto pøímek je: "<<*(normala)<< *(normala+1) << *(normala+2) << endl;


	/*double* pole = new double[3];
	for (int i = 0; i < 3; i++)
	{
		*(pole + i) = i * 3;
	}
	Primka p(pole,pole,3);
    
	p.vypis();*/
	/*Vektor y(n);
	y.vektor();
	
	system("cls");
	x.vypis();
	cout << "Norma vektoru je " + to_string(x.norm()) << endl;
	y.vypis();
	cout << "Norma vektoru je " + to_string(y.norm()) << endl;
	cout << "Skalární souèin je " + to_string(y.Ssoucin(x)) << endl;
	cout << "Úhel je " + to_string(Vektor::angle(x,y)) << endl;*/
	/*
	double* p = new double[n];
	for (int i = 0; i < n; i++)
	{
		*(p + i) = 2 * i;
		cout << *(p + i)<<" ";
	}
	Vektor v(p,n);
	double a=v.norm();



	cout << a << endl;

	*/







	/*cout << "Zadej rok, zakladatele a hrad" << endl;
	int year; string founder; string castle;
	cin >> year;
	cin.ignore();
	getline(cin, founder);
	getline(cin, castle);
	History h(year,founder,castle);
	Person white(17,"Arya", "Stark","Stark",h);
	//white.BasicInfo();
	white.DetailInfo();*/
	/*Person black("Sansa", "Stark");
	black.BasicInfo();
	bool b = white.Family(white, black);*/
	/*
	cout << "Zadej jméno" << endl;
	string name; string house;
	cin>> name;
	cout << "Zadej rod" << endl;
	cin >> house;

	Person purple(name, house);
	cout << "Zadej jméno" << endl;
	cin >> name;
	cout << "Zadej rod" << endl;
	cin >> house;
	Person brown(name, house);
	system("cls");
	purple.BasicInfo();
	brown.BasicInfo();
	bool r = purple.Family(purple, brown);
	if (r)
		cout << "Jsou ze stejné rodiny gratuluji" << endl;
	else
		cout << "Nejsou ze stejné rodiny" << endl;*/
	



	/*double *a;
	cout << "Zadej cislo" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		*(a + i) = 1;
	}
	Vektor* v = new Vektor(a);
	cout<< v->norm(a) <<endl;*/


	/*cout << "Zadej poèet øádkù matice" << endl;
	int r;
	cin >> r;
	cout << "Zadej poèet sloupcù matice" << endl;
	int s;
	cin >> s;
	int** mat;
	double** e = new double* [r];
	for (int i = 0; i < r; i++)
	{
		e[i] = new double[s];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << "Zadej èíslo" <<endl ;
			cin>> e[i][j];
		}
	}
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout<< e[i][j] <<" ";
		}
		cout << endl;
	}
	*/

	
	
	
	
	
	
	/*Matice* m=new Matice();
	m->ahoj();*/





system("pause");
	return 0;
}