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
Matice::Matice(int r, int s):r(r),s(s)//Konstruktor na vytvo�en� matice 
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

void Matice::vypis(double ** N,int r, int s)//Vyp�e matici
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

void Matice::vypis()//Vyp�e matici
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

double** Matice::Diagonal()//P�evede matici na diagon�ln� tvar
{
	int dim; sgn = 0;
	if (r == s)//Zjist� tvar matici(�tvercov� x obdeln�kov� svisl� x obdeln�kov� vodorovn� )
		dim = s - 1;
	else if (r > s)
		dim = s;
	else if (r < s)
		dim = r - 1;
	for (int k = 0; k < dim; k++)//Spo��t� hodnost matice M
	{
		for (int e = (k + 1); e < r; e++)//V�m�na ��dk� podle pivotn� formule
		{
			if (abs(*(M[k] + k)) < abs(*(M[e] + k)))
			{
				sgn++;
				double* pomocna = M[k];
				M[k] = M[e];
				M[e] = pomocna;
				cout << "======Prohozen� ��dk�=========" << endl;
				vypis();
			}
			/*cout << "======Prohozen� ��dk�=========" << endl;
			vypis();*/
		}
		cout << "=======Fin�ln� tvar========" << endl;
		vypis();
		for (int i = k; i < (r - 1); i++)//Vynuluje sloupec
		{
			if (*(M[i + 1] + k) == 0)//Pokud je na pozici i+1. sloupce a k. ��dku nula, pak se nulov�n� tohoto prvku (a ��dku jemu p��slu�n�m) nekon� a jde se na dal�� ��dek.   
				continue;
			double a = *(M[i + 1] + k) / *(M[k] + k);//Spo�te pod�l dvou prvk� matice, z nich� jeden je eliminov�n
			for (int j = k; j < s; j++)//Uprav� p��slu�n� ��dek
			{
				*(M[i + 1] + j) = -a* *(M[k] + j) + *(M[i + 1] + j);
				if (abs(*(M[i + 1] + j)) < 0.000000001)//Pokud je hodnota prvku men�� ne� dan� tolerance, pak se tento prvek nastav� na nulu
					*(M[i + 1] + j) = 0;
			}
		}
		cout << "=======Vynulov�n� sloupce========" << endl;
		vypis();
	}
	cout << "===============" << endl;
	vypis();
	return M;
}

int Matice::Hodnost()
{
	double** M = Diagonal();//P�evede na diagon�ln� tvar
	h = 0;
	bool b;
	for (int i = 1; i < r; i++)//Zjist� po�et nulov�ch ��dk�
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
		cout<<"Matice nen� �tvercov� "<<endl;
	}
	else {
		double** K = Diagonal();
		cout<<"%%%%%%%%%%%%  "<< to_string(sgn)  <<"     %%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		d = 1;
		for (int i = 0; i < r; i++)//Sou�in prvk� na hlavn� diagon�le = determinant matice
		{
			d *= *(K[i]+i);
		}
	}
	if (sgn % 2 == 0)//kontrola zm�na znam�nka p�i p�ehozov�n� ��dk�
	{
		//sgn = 0;
		cout<<"Determinant matice je: "<< d <<endl;
		return d;
	}
	else//kontrola zm�na znam�nka p�i p�ehozov�n� ��dk�
	{
	  //sgn = 0;
		cout << "Determinant matice je: " << (-1)*d << endl;

		return (-1)*d;
	}
}

double * Matice::Cramer(double* p) //p je vektor prav� strany soustavy
{
	cout << n << endl;
	result = new double[n]; // result je vektor �e�en� zadan� soustavy
	double** N = new double*[n];//Vytvo�� novou matici
	N = Copy(M, n, n);//Funkce zkop�ruje hodnoty matice M do matice N

	vypis(N, n, n);
	cout <<N<<", " <<M << endl;
	double D = Determinant(); // D je determinant soustavy
	cout<<"=====================================================  D: "<< D<<endl;
	if (D==0)
	{
		cout<<"Zadan� soustava nem� �e�en�" <<endl;
		return nullptr;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			M = Copy(N, n, n);//Funkce zkop�ruje hodnoty matice N do matice M
			cout<<"Zkop�rov�n� matice"<<endl;
			vypis();
			cout << "Zkop�rov�n� matice" << endl;
			//cout<<"=============PROHODIL JSEM SLOUPEC========"<<endl;
			for (int j = 0; j < n; j++)
			{
				*(M[j] + i) = *(p + j); //vym�n� sloupec prav� strany za p��slu�n� i-t� sloupec matice soustavy
			}
			result[i] = Determinant() / D;
		}
		return result;
	}
}

double ** Matice::Copy(double ** matrix,int r,int s)//Zkop�ruje hodnoty jedn� matice do druh�
{
	double** K = new double*[r];//Vytvo�� novou matici
	for (int i = 0; i < r; i++)
	{
		double* g = new double[s];
		for (int j = 0; j < s; j++)
		{
			*(g + j) = *(matrix[i] + j);//vektor se napln� hodnotami z ��dku p�vodn� matice
		}
		K[i] = g;//zkop�ruje vektor g do ��dku matice K
	}
	return K;
}

