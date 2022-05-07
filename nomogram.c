//NECULA EDUARD-IONUT 322 CA @2020
#include <stdio.h>

#define MAX 1000

int main(void)
{
	int i, j, k, contor_corecte_lin = 0, contor_corecte_col = 0;
	int nr_puzzle, nr_lin_puz, nr_col_poz;
	int piese_lin[MAX], val_pies_lin[MAX], piese_col[MAX];
	int sum_lin_vect[MAX], sum_col_vect[MAX];
	int sum_lin_puz[MAX], sum_col_puz[MAX], val_pies_col[MAX];
	int puzzle[MAX][MAX]; //puzzle

	scanf("%d", &nr_puzzle);//numarul de puzzle-uri
	for (i = 0; i < nr_puzzle; i++) {
		scanf("%d", &nr_lin_puz);//citesc nr de linii
		scanf("%d", &nr_col_poz);//citesc nr de coloane
		//pentru linie
		for (j = 0; j < nr_lin_puz; j++) {
			scanf("%d", &piese_lin[j]);//citesc primul indice de pe linie
			for (k = 0; k < piese_lin[j]; k++) {
				scanf("%d", &val_pies_lin[k]);
				sum_lin_vect[j] += val_pies_lin[k];//suma de pe linie
			}
		}
		//pentru coloana
		for (j = 0; j < nr_col_poz; j++) {
			scanf("%d", &piese_col[j]);//citesc primul indice de pe coloana
			for (k = 0; k < piese_col[j]; k++) {
				scanf("%d", &val_pies_col[k]);
				sum_col_vect[j] += val_pies_col[k];//suma de pe coloana
			}
		}
		//citesc matricea
		for (j = 0; j < nr_lin_puz; j++)
			for (k = 0; k < nr_col_poz; k++)
				scanf("%d", &puzzle[j][k]);

		//suma de pe linii
		for (j = 0; j < nr_lin_puz; j++)
			for (k = 0; k < nr_col_poz; k++)
				sum_lin_puz[j] += puzzle[j][k];
		//suma de pe coloane
		for (j = 0; j < nr_col_poz; j++)
			for (k = 0; k < nr_lin_puz; k++)
				sum_col_puz[j] += puzzle[k][j];
		//daca linia citita din input este diferita din matrice
		for (j = 0; j < nr_lin_puz; j++)
			if (sum_lin_puz[j] != sum_lin_vect[j])
				contor_corecte_lin++;
		//daca coloana citita din input este diferita din matrice
		for (j = 0; j < nr_col_poz; j++)
			if (sum_col_puz[j] != sum_col_vect[j])
				contor_corecte_col++;
		//daca nu exista diferente, inseamna ca avem un puzzle corect
		if (contor_corecte_col == 0 && contor_corecte_lin == 0)
			printf("Corect\n");
		else
			printf("Eroare\n");

		//curatare nomogram, initializez tot ce am citit la 0
		contor_corecte_col = 0;
		contor_corecte_lin = 0;
		for (j = 0; j < nr_col_poz; j++) {
			sum_col_puz[j] = 0;
			piese_col[j] = 0;
			sum_col_vect[j] = 0;
		}
		for (j = 0; j < nr_lin_puz; j++) {
			sum_lin_puz[j] = 0;
			piese_lin[j] = 0;
			sum_lin_vect[j] = 0;
		}
		for (k = 0; k < piese_lin[j]; k++)
			val_pies_lin[k] = 0;
		for (k = 0; k < piese_col[j]; k++)
			val_pies_col[k] = 0;
		for (j = 0; j < nr_lin_puz; j++)
			for (k = 0; k < nr_col_poz; k++)
				puzzle[j][k] = 0;
	}

	return 0;
}
