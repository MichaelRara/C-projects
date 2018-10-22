#include "Primka.h"
#include <iostream>
#include <string>
#include <math.h>
#include "Vektor.h"
#include "Matice.h"
#include <stdio.h>  
#include <stdlib.h>
using namespace std;

Primka::Primka(){}
Primka::Primka(int n): Vektor(n) //Konstruktor na zadání bodu pøímky. Nejprve se zadá vektor pomocí konstruktoru ze tøídy Vektor.h
{
	P = new double[n];
	double f;
	for (int i = 0; i < n; i++)
	{
		cout << "Zadej " + to_string(i) << ". bod pøímky" << endl;
		cin >> f;
		*(P + i)=f;
	}
}
Primka::~Primka()
{
	//for (int i = 0; i < n; i++)
	//{
		delete[] P;
	//}
	cout << "SMAZAL JSEM===========================================" << endl;
}

void Primka::vypis()//Vypíše parametrickou rovnici pøímky
{
	cout<<"Bod pøímky"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(P+i)<<" ";
	}
	cout << endl;
	cout << "Vektor pøímky" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}
	cout << endl;
	cout << "Parametrická rovnice pøímky " << endl;
	for (int i = 0; i < n; i++)
	{
		if (i < (n - 1))
			cout << "X" + to_string(i) << " = " << *(P + i) << " + " << *(p + i) << "t"<<endl;
		else
			cout << "X" + to_string(i) << " = " << *(P + i) << " + " << *(p + i) << "t" << "; t in R"<<endl;
	}
}
void Primka::poloha(Primka v)
{
	if (n>3)
			cout << "Algoritmus funguje jen pro pøímky v rovinì nebo 3D prostoru" << endl;
	else 
	{
		double** M = new double*[3];//Matice M bude mít 3 øádky
		double* g = new double[n];
		for (int i = 0; i < n; i++)
		{
			*(g+i) = *(v.p+i);//Vektor v
		}
		M[0] = g;//Vektor v
		double* x = new double[n];
		for (int i = 0; i < n; i++)
		{
			*(x+i) = *(p + i);//Vektor v
		}
		M[1] = x;//Vektor u
		double* R = new double[n];
		R = M[1];
		double* c = new double[n];
		for (int i = 0; i < n; i++)//Spoète vektor A-B
		{
			c[i] = *(P + i) - *(v.P + i);
		}
		M[2] = c;
		Matice m(M, 3, n);
		m.vypis();
		//Zjistí hodnost matice a submatice
		//double** N = m.Diagonal(3,n);
		double** N = m.Diagonal();
		int k = 1;//Hodnost matice 
		int l = 1;//Hodnost rozšíøené matice
		bool u=true;
		for (int j = 0; j < n; j++)//Zjistí, jestli je øádek nulový
		{
			if (*(N[1] + j) != 0)
			{
				u = false;
				break;
			}
		}
		if (u==false)//pokud je øádek nenulový, tak se zvedne hodnost matic k, l o jednièku
		{
			k++;
			l++;
		}
		u = true;
		for (int j = 0; j < n; j++)//Zjistí, jestli je øádek nulový
		{
			if (*(N[2] + j) != 0)
			{
				u = false;
				break;
			}
		}
		if (u ==false)//pokud je øádek nenulový, tak se zvedne hodnost rozšíøené matice l o jednièku
			l++;
		int d = k + l;// seète hodnost matic l, k
		cout << "k = " << k << endl;
		cout << "l = " << l << endl;
		cout << "d = " << d << endl;
		switch (d)
		{
		case 2:
			cout << "Tyto pøímky jsou totožné " << endl;//funguje
			cout << "Úhel mezi tìmito pøímkami je: " + to_string(Angle(v.p)) << "°" << endl;
			break;
		case 3:
			cout << "Tyto pøímky jsou rovnobìžné" << endl;//funguje
			cout << "Úhel mezi tìmito pøímkami je: " + to_string(Angle(v.p)) << "°" << endl;
			break;
		case 4:
			cout << "Tyto pøímky jsou rùznobìžné" << endl;//funguje
			cout << "Úhel mezi tìmito pøímkami je: " + to_string(Angle(v.p)) << "°" << endl;
			normal(v.p);
			break;
		case 5:
			cout << "Tyto pøímky jsou mimobìžné" << endl;//funguje
			cout << "Úhel mezi tìmito pøímkami je: " + to_string(Angle(v.p)) << "°" << endl;
			normal(v.p);
			break;
		}
	}
}

double Primka::Angle(double* les)//Spoète úhel mezi dvìma pøímkami
{
	double s = acos(abs(Ssoucin(les)) / (norm(p)*norm(les)));
	s *= (180 / 3.14159265359); //Pøevede z radiánù na stupnì
	return s;
}

