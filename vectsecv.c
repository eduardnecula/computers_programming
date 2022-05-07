//NECULA EDUARD-IONUT 322 CA @2020
#include <stdio.h>
#include <math.h>

#define MAX 100 //maxim 100 de numere(garantat)

int numar_cifre_fara_zero(int nr)//returneaza numarul de cifre ale unui numar
{								//diferite de 0
	int nr_cifre = 0;
	int cifre_de_zero = 0;

	while (nr) {
		if (nr % 10 == 0)
			cifre_de_zero++;
		nr_cifre++;
		nr /= 10;
	}

	return (nr_cifre - cifre_de_zero);
}

int numar_cifre(int nr) //returnez numarul de cifre ale unui numar
{
	int nr_cifre = 0;

	while (nr) {
		nr_cifre++;
		nr /= 10;
	}

	return nr_cifre;
}

//functia ordoneaza crescator cifrele unui numar, fara 0
//ex: 9870---->789
//functia returneaza numarul ordonat crescator: 789
int nr_ordonat_cresc(int numar)
{
	int temporar, cifra, new_number = 0;
	int nr_cifre = numar_cifre_fara_zero(numar) - 1;
	for (cifra = 1; cifra <= 9; cifra++) {
		for (temporar = numar; temporar > 0; temporar /= 10) {
			if (temporar % 10 == cifra && cifra != 0) {
				new_number += cifra * pow(10, nr_cifre);
				nr_cifre--;
			}
		}
	}

	return new_number;
}

//functia ordoneaza descrescator cifrele unui numar
//ex: 1230---->3210
//functia returneaza numarul ordonat descrecator: 3210
int nr_ordonat_desc(int numar)
{
	int temporar, cifra, new_number = 0;
	int nr_cifre = numar_cifre(numar) - 1;
	for (cifra = 9; cifra >= 1; cifra--) {
		for (temporar = numar; temporar > 0; temporar /= 10) {
			if (temporar % 10 == cifra) {
				new_number += cifra * pow(10, nr_cifre);
				nr_cifre--;
			}
		}
	}

	return new_number;
}

int main(void)
{
	int nr_citit;
	int numere[MAX], numar_periodic = 0;
	int i, j, primul_nr_ciclat = -1;
	int pozitia_perioadei = 0, aux = 0;

	for (int i = 0; i < MAX; ++i)
		numere[i] = 0;

	scanf("%d", &nr_citit);//numarul initial
	numere[0] = nr_citit;

//in numere[i] se vor pune toate combinatiile de numere
	for (i = 0; i < MAX; i++) {
		numere[i] = nr_ordonat_desc(numere[i]) - nr_ordonat_cresc(numere[i]);
		numere[i + 1] = numere[i];
	}
//in acest for se cauta numerele periodice si pozitia unde apar prima data
	for (i = 0; i < MAX; i++) {
		for (j = (i + 1); j < MAX; j++) {
			if (numere[i] == numere[j]) {
				primul_nr_ciclat = numere[j];
				pozitia_perioadei = j;//in pozitia_perioadei pun
				break;				//locatia unde numarul incepe sa cicleze
			}
		}
		if (primul_nr_ciclat != -1)//daca primul_nr_ciclat != -1,
			break;					//inseamna ca eu inca n-am ajuns
	}								//la un numar periodic

	for (i = 0; i < MAX; i++) {
		if (numere[i] == primul_nr_ciclat)
			break;
		numar_periodic++;// cate numere se repeta in perioada
	}

	printf("%d\n", numar_periodic);

	for (i = pozitia_perioadei; i < MAX; ++i) {
		if (numere[i] == primul_nr_ciclat)
			aux++;
		if (aux == 2)// daca gasesc nr care cicleaza, a doua oara, ma opresc
			break;
		printf("%d ", numere[i]);// afisez numarele pana in numarul periodic
	}

	return 0;
}
