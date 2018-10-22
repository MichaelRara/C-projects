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
	//Mat.open("test.txt"); //Vytvo��, nebo otev�e soubor test.txt ve slo�ce Matematika
	//Mat << " 3 4 4\n 7 8 8\n 0 -2 -7"; // Zap�e do souboru test.txt matici 3 4\n 7 8
	//Mat.close();
	char volba;
	cout<<"Chce�-li zadat matici z txt soubotu stiskni 't' pro standartn� zad�n� pomoc� kl�vesnice stiskni 'k'"<<endl;
	cin >> volba;
	if (volba=='t')
	{
		//Mat.open("test.txt");
		string line; 
		int n=0;// n= po�et ��dk�
		vector<string> arr;//vektor ��dk� souboru test.txt
		vector<int> d;//vektor d�lek ��dk�
		ifstream Mat("test.txt");
		while (getline(Mat,line)) //na�te ��dek ze souboru test.txt
		{
			n++;					// po�et ��dk� se zv��� o +1
			cout << line << '\n';
			int s = line.size(); //d�lka ��dku v�etn� mezer 
			d.push_back(s); //na�te d�lku akti�ln�ho ��dku do vektoru d
			arr.push_back(line); //do vektoru arr se na prvn� (druhou, t�et�...) pozici ulo�� aktu�ln� ��dek
		}
		int ss = line.size();
		int s = ss-1;//s= d�lka ��dku bez posled�ho null characteru tj. znak \0
		
		for (int i = 0; i < s; i++)
		{
			if (line[i]=' ')//kdykoliv najde v ��dku mezeru, sn�� se d�lka ��dku o -1, nakonec dostaneme po�et prvk� v ��dku
				s--;
		}
		cout << s << endl;
		double** L = new double*[n];//Deklarujeme matici soustavy
		for (int i = 0; i < n; i++)
		{
			double* l = new double[s];
			int r = 0;//pomoc� r posouv�me index u pointeru l
			for (int j = 0; j < d[i]; j++)
			{
				if ((arr[i][j] != ' ') && (arr[i][j] != '-'))
				{
					line = arr[i][j] + '\0';//aby funkce ::atof fungovala (p�evede string na double), pot�ebuje na konci null pointer tj. \0
					if (arr[i][j-1] == '-')//pokud byl p�edchoz� znak v �et�zci ��dku -, pak n�sleduj�c� ��slo je z�porn�
						*(l + r) = (-1)*::atof(line.c_str());
					else 
						*(l + r) = ::atof(line.c_str());
					cout << *(l + r) << " ";
					r++;
				}
			}
			L[i] = l;// na�te ��dek do matice
			cout << endl;
		}
		Matice v(L, n, s);//vytvo�� instanci matice ze souboru test.txt
		v.vypis();
		int w = 3;
		double* p = new double[w];//Vektor prav� strany
		for (int i = 0; i < w; i++)
		{
			*(p + i) = i;
		}
		double* t = v.Cramer(p);// Pomoc� Cramerovy metody spo�te �e�en� soustavy
		if (t != nullptr) // pokud m� soustava �e�en�
		{
			cout << "�e�en�: " << endl;
			for (int i = 0; i < w; i++)//Vyp�e �e�en�
			{
				cout << *(t + i) << ", " << endl;
			}
		}
	}
	else
	{
		int w = 3;
		Matice m(w, w);//Zad�n� matice
		m.vypis();//V�pis matice
		double* p = new double[w];//Vektor prav� strany
		*(p) = 0;
		*(p + 1) = 1;
		*(p + 2) = -6;
		/*for (int i = 0; i < w; i++)
		{
			*(p + i) = i;
		}*/
		double* t = m.Cramer(p);// z�sk�me vektor �e�en�
		if (t!=nullptr)// pokud �e�en� existuje
		{
			cout << "�e�en�: " << endl;
			for (int i = 0; i < w; i++)//Vyp�e �e�en�
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
	cout<<"�e�en�: "<<endl;
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
	//cout<<"�hel mezi t�mito p��mkami je: "+to_string(Primka::angle(q,p))<<"�" <<endl;

	//q.poloha(p);

	//cout << "Norm�lov� vektor t�chto p��mek je: "<<*(normala)<< *(normala+1) << *(normala+2) << endl;


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
	cout << "Skal�rn� sou�in je " + to_string(y.Ssoucin(x)) << endl;
	cout << "�hel je " + to_string(Vektor::angle(x,y)) << endl;*/
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
	cout << "Zadej jm�no" << endl;
	string name; string house;
	cin>> name;
	cout << "Zadej rod" << endl;
	cin >> house;

	Person purple(name, house);
	cout << "Zadej jm�no" << endl;
	cin >> name;
	cout << "Zadej rod" << endl;
	cin >> house;
	Person brown(name, house);
	system("cls");
	purple.BasicInfo();
	brown.BasicInfo();
	bool r = purple.Family(purple, brown);
	if (r)
		cout << "Jsou ze stejn� rodiny gratuluji" << endl;
	else
		cout << "Nejsou ze stejn� rodiny" << endl;*/
	



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


	/*cout << "Zadej po�et ��dk� matice" << endl;
	int r;
	cin >> r;
	cout << "Zadej po�et sloupc� matice" << endl;
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
			cout << "Zadej ��slo" <<endl ;
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