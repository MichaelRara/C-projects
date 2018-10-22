#include "Matice.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

Matice::Matice(double ** matrix, int r, int s):M(matrix),r(r),s(s)
{
	if (r == s)
		n = r;
}
Matice::Matice(double ** matrix, int n):M(M),n(n),r(n),s(n){}
Matice::Matice(int r, int s):r(r),s(s)//Konstruktor na vytvoøení matice 
{
	if (r == s)
		n = r;
	M = new double*[r];
	for (int i = 0; i < r; i++)
	{
		double* R = new double[s];
		for (int j = 0; j < s; j++)
		{
			cout << "Zadej cislo: ";
			cin >> *(R + j);
		}
		M[i] = R;
	}
}
Matice::~Matice(void)
{
	for (int i = 0; i < r; i++)
	{
		delete[] M[i];
	}
	cout<<"SMAZAL JSEM==========================================="<<endl;
}

void Matice::vypis(double ** N,int r, int s)//Vypíše matici
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << N[i][j] << " ";
		}
		cout << endl;
	}
}

void Matice::vypis()//Vypíše matici
{
	for (int i = 0; i < this->r; i++)
	{
		for (int j = 0; j < this->s; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

double** Matice::Diagonal()//Pøevede matici na diagonální tvar
{
	int dim; sgn = 0;
	if (r == s)//Zjistí tvar matici(ètvercová x obdelníková svislá x obdelníková vodorovná )
		dim = s - 1;
	else if (r > s)
		dim = s;
	else if (r < s)
		dim = r - 1;
	for (int k = 0; k < dim; k++)//Spoèítá hodnost matice M
	{
		for (int e = (k + 1); e < r; e++)//Výmìna øádkù podle pivotní formule
		{
			if (abs(*(M[k] + k)) < abs(*(M[e] + k)))
			{
				sgn++;
				double* pomocna = M[k];
				M[k] = M[e];
				M[e] = pomocna;
				cout << "======Prohození øádkù=========" << endl;
				vypis();
			}
			/*cout << "======Prohození øádkù=========" << endl;
			vypis();*/
		}
		cout << "=======Finální tvar========" << endl;
		vypis();
		for (int i = k; i < (r - 1); i++)//Vynuluje sloupec
		{
			if (*(M[i + 1] + k) == 0)//Pokud je na pozici i+1. sloupce a k. øádku nula, pak se nulování tohoto prvku (a øádku jemu pøíslušném) nekoná a jde se na další øádek.   
				continue;
			double a = *(M[i + 1] + k) / *(M[k] + k);//Spoète podíl dvou prvkù matice, z nichž jeden je eliminován
			for (int j = k; j < s; j++)//Upraví pøíslušný øádek
			{
				*(M[i + 1] + j) = -a* *(M[k] + j) + *(M[i + 1] + j);
				if (abs(*(M[i + 1] + j)) < 0.000000001)//Pokud je hodnota prvku menší než daná tolerance, pak se tento prvek nastaví na nulu
					*(M[i + 1] + j) = 0;
			}
		}
		cout << "=======Vynulování sloupce========" << endl;
		vypis();
	}
	cout << "===============" << endl;
	vypis();
	return M;
}

int Matice::Hodnost()
{
	double** M = Diagonal();//Pøevede na diagonální tvar
	h = 0;
	bool b;
	for (int i = 1; i < r; i++)//Zjistí poèet nulových øádkù
	{
		b = true;
		for (int j = 0; j < s; j++)
		{
			if (*(M[i] + j) != 0)
			{
				b = false;
				break;
			}
		}
		if (b == true)
			h++;
	}
	h = r - h;
	cout << "Hodnost matice je: " << h << endl;
	return h;
}

double Matice::Determinant()
{
	if (r!=s)
	{
		cout<<"Matice není ètvercová "<<endl;
	}
	else {
		double** K = Diagonal();
		cout<<"%%%%%%%%%%%%  "<< to_string(sgn)  <<"     %%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		d = 1;
		for (int i = 0; i < r; i++)//Souèin prvkù na hlavní diagonále = determinant matice
		{
			d *= *(K[i]+i);
		}
	}
	if (sgn % 2 == 0)//kontrola zmìna znaménka pøi pøehozování øádkù
	{
		//sgn = 0;
		cout<<"Determinant matice je: "<< d <<endl;
		return d;
	}
	else//kontrola zmìna znaménka pøi pøehozování øádkù
	{
	  //sgn = 0;
		cout << "Determinant matice je: " << (-1)*d << endl;

		return (-1)*d;
	}
}

double * Matice::Cramer(double* p) //p je vektor pravé strany soustavy
{
	cout << n << endl;
	result = new double[n]; // result je vektor øešení zadané soustavy
	double** N = new double*[n];//Vytvoøí novou matici
	N = Copy(M, n, n);//Funkce zkopíruje hodnoty matice M do matice N

	vypis(N, n, n);
	cout <<N<<", " <<M << endl;
	double D = Determinant(); // D je determinant soustavy
	cout<<"=====================================================  D: "<< D<<endl;
	if (D==0)
	{
		cout<<"Zadaná soustava nemá øešení" <<endl;
		return nullptr;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			M = Copy(N, n, n);//Funkce zkopíruje hodnoty matice N do matice M
			cout<<"Zkopírování matice"<<endl;
			vypis();
			cout << "Zkopírování matice" << endl;
			//cout<<"=============PROHODIL JSEM SLOUPEC========"<<endl;
			for (int j = 0; j < n; j++)
			{
				*(M[j] + i) = *(p + j); //vymìní sloupec pravé strany za pøíslušný i-tý sloupec matice soustavy
			}
			result[i] = Determinant() / D;
		}
		return result;
	}
}

double ** Matice::Copy(double ** matrix,int r,int s)//Zkopíruje hodnoty jedné matice do druhé
{
	double** K = new double*[r];//Vytvoøí novou matici
	for (int i = 0; i < r; i++)
	{
		double* g = new double[s];
		for (int j = 0; j < s; j++)
		{
			*(g + j) = *(matrix[i] + j);//vektor se naplní hodnotami z øádku pùvodní matice
		}
		K[i] = g;//zkopíruje vektor g do øádku matice K
	}
	return K;
}

