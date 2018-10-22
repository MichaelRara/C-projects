/* 
 * File:   main.c
 * Author: micha
 *
 * Created on 4. září 2017, 17:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Umožní používat datový tip string
#include <stdbool.h>// Umožní používat datový typ boolean
#include <math.h>// Umožní používat funkci abs() pro integet a funkce fabs() pro double, obě funkce vrací absolutní hodnotu čísla

double Determinant(double** M, int r, int s, int sgn)
{
    double d = 1;
    if (r!=s)
        printf("Matice není čtvercová ");
    else 
    {
        for (int i = 0; i < r; i++) // Součín prvků hlavní diagonály = determinant matice
        {
            d *= *(M[i]+i);
        }
        if (sgn % 2 == 0) // Ověření znaménka
        {
            printf("Determinant matice je: %lf ",d);
            return d;
        }
        else // Ověření znaménka
        {
            printf( "Determinant matice je: %lf ",(-1)*d);
            return (-1)*d;
        }
    }
}

void Diagonal(double** M,int r, int s, int* sgn)
{
    int dim; 
	if (r == s) // zjistí tvar zadané matice ( čtvercová x obdelníková svislá x obdelníková vodorovná)
		dim = s - 1;
	else if (r > s)
		dim = s;
	else if (r < s)
		dim = r - 1;
    for (int k = 0; k < dim; k++)//Spočítá hodnost matice M
	{
		for (int e = (k + 1); e < r; e++)//Výměna řádků podle pivotní formule
		{
			if (fabs(*(M[k] + k)) < fabs(*(M[e] + k)))
			{
                                //*sgn++;
                                *sgn=*sgn+1;
				double* pomocna = M[k];
				M[k] = M[e];
				M[e] = pomocna;
				printf( "======Prohození řádků=========\n");
				vypis(M,r,s);
			}
	        }
		printf("=======Finální tvar========\n");
		vypis(M,r,s);
		for (int i = k; i < (r - 1); i++)//Vynuluje sloupec
		{
			if (*(M[i + 1] + k) == 0)//Pokud je na pozici i+1. sloupce a k. řádku nula, pak se nulování tohoto prvku (a řádku jemu příslušném) nekoná a jde se na další řádek.   
				continue;
			double a = *(M[i + 1] + k) / *(M[k] + k);
			for (int j = k; j < s; j++)//Upraví příslušný řádek
			{
				*(M[i + 1] + j) = -a* *(M[k] + j) + *(M[i + 1] + j);
				if (fabs(*(M[i + 1] + j)) < 0.000001)//Pokud je hodnota prvku menší než daná tolerance, pak se tento prvek nastaví na nulu
					*(M[i + 1] + j) = 0;
			}
		}
		printf("=======Vynulování sloupce========\n");
		vypis(M,r,s);
	}    
}

void Diagonal2(double** M,int r, int s)
{
    
    int dim; 
    if (r == s)
        dim = s - 1;
    else if (r > s)
	dim = s;
    else if (r < s)
	dim = r - 1;
    for (int k = 0; k < dim; k++)//Převede na schodovitý tvar
    {
	for (int e = (k + 1); e < r; e++)//Výměna řádků podle pivotní formule
	{
            if (fabs(*(M[k] + k)) < fabs(*(M[e] + k)))
                {
                    double* pomocna = M[k];
		    M[k] = M[e];
                    M[e] = pomocna;
                    printf( "======Prohození řádků=========\n");
                    vypis(M,r,s);
		}
	}
	printf("=======Finální tvar========\n");
	for (int i = k; i < (r - 1); i++)//Vynuluje sloupec
        {
            if (*(M[i + 1] + k) == 0)//Pokud je na pozici i+1. sloupce a k. řádku nula, pak se nulování tohoto prvku (a řádku jemu příslušném) nekoná a jde se na další řádek.   
		continue;
            double a = *(M[i + 1] + k) / *(M[k] + k);
            for (int j = k; j < s; j++)//Upraví příslušný řádek
            {
		*(M[i + 1] + j) = -a* *(M[k] + j) + *(M[i + 1] + j);
		if (fabs(*(M[i + 1] + j)) < 0.0000001)//Pokud je hodnota prvku menší než daná tolerance, pak se tento prvek nastaví na nulu
                    *(M[i + 1] + j) = 0;
            }
        }
	printf("=======Vynulování sloupce========\n");
	vypis(M,r,s);
    }    
}

double* GEM(double** M, int r, int s)
{
    Diagonal2(M,r,s);// Převede na diagonální tvar
    int dim; 
    if (r == s)
        dim = s - 1;
    else if (r > s)
	dim = s;
    else if (r < s)
	dim = r - 1;
    printf("================Zpětná diagonalizace========\n");
    double *result = (double *)malloc(r * sizeof(double));// vytvoří vektor řešení
    *(result+(r-1))=*(M[r-1]+(s-1)) / *(M[r-1]+(r-1));// spočte poslední složku vektoru řešení z posledního řádku diagonalizované matice soustavy
    for(int j=(s-2);j>=0;j--)
    {
        for(int k=(r-1);k>j;k--)//Převede na pravou stranu takové výrazy ze soustavy rovnic u nichž již známe hodnotu neznámé
        {
            *(M[j]+(s-1))-=*(M[j]+k);
        }
        vypis(M,r,s);
        *(result+j)=*(M[j]+(s-1))/ *(M[j]+j);//Spočte další složku vektoru řešení (postupuje se od poslední složce k první)
        for(int i=(r-1);i>=0;i--)//Pronásobí sloupec matice soustavy hodnotou výše získané složky vektoru řešení
        {
            *(M[i]+j)*= *(result+j);
        }
        vypis(M,r,s);
        printf("??????????????????????????????????????????????????????????????\n");
    }
    printf("Řešení je: \n");
    for(int i=0;i<r;i++)//Vypíše řešení soustavy
    {
        printf("%lf\n",*(result+i));
    }
    return result;
}
int Hodnost(double** M, int r, int s) // Spočte hodnost matice
{
    Diagonal2(M,r,s); // Převede na diagonální tvar
    int h = 0;
    bool b;
    for (int i = 1; i < r; i++)//Zjistí počet nulových řádků
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
	printf( "Hodnost matice je: %d",h);
	return h;
}
void vypis(double** M, int r, int s)//Vypíše matici M, r = řádky, s = sloupce 
{
    printf("\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<s;j++)
        {
            printf("%lf, ",M[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char** argv) {
    int r; int s; int n; double* p; int sgn=0; int h; double d;
    printf("Zadej počet řádků matice ");
    scanf("%d",&r);
    printf("Zadej počet sloupců matice ");
    scanf("%d",&s);
    double **mat = (double **)malloc(r * sizeof(double*)); // Vytvoří pole ukazatelů
    for(int i = 0; i < r; i++)
    {
        mat[i] = (double *)malloc(s * sizeof(double)); // Každý ukazatel z pole mat ukazuje na příslušný kus paměti
    }
    printf("\n");
    for(int i=0;i<r;i++) // Zadání matice
    {
        for(int j=0;j<s;j++)
        {
            printf("Zadej cislo: ");
            scanf("%lf",&mat[i][j])  ;
        }
    }
    
    //POKUD CHCEŠ SPOČÍTAT DETERMINANT, TAK VOLEJ METODU Diagonal() A NÁSLEDNĚ METODU Determinant(), JE-LI VOLÁNA METODA Hodnost() PŘED METODOU Determinant, TAK SE VÝPOČET NEPROVEDE SPRÁVNĚ  
    vypis(mat,r,s);
   // h= Hodnost(mat,r,s); // Spočte hodnost matice
   // printf("\n===============HODNOST====================== %d",h);
    Diagonal(mat,r,s,&sgn); // Převede matici na diagonální tvar
    vypis(mat,r,s); // Vypíše matici mat v diagonálním tvaru
    printf("Celkový počet prohozených řádků %d\n",sgn);
    d= Determinant(mat,r,s,sgn); // Spočítá determinant
    printf("\n===============DETERMINANT================== %lf\n",d);
    GEM(mat,r,s); // Spustí Gaussovu eliminační metodu (vyřeší soustavu lineárních rovnic)
    
    
    
    
    
    
    return (EXIT_SUCCESS);
}

