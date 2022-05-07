//NECULA EDUARD-IONUT 322 CA
#include <stdio.h>

#define MAX 100
#define NOTA_10 10

int main(void)
{
	int nr_materii;
	int i, j, aux;
	int punctaj_materii[MAX];
	int credite_materii[MAX];
	int punctaj_minim;
	int punctaj_initial = 0;
	int nr_materii_necesare = 0;

	scanf("%d", &nr_materii);
	if (nr_materii > MAX && nr_materii < 1)
		return -1;

	for (i = 0; i < nr_materii; i++)
		scanf("%d", &punctaj_materii[i]);

	for (i = 0; i < nr_materii; i++)
		scanf("%d", &credite_materii[i]);

	scanf("%d", &punctaj_minim);

//momentan pe parcurs, ex: 117
	for (i = 0; i < nr_materii; ++i)//aici calculez punctele pe care le am
		punctaj_initial += credite_materii[i] * punctaj_materii[i];

//voi refolosi vectorul credite_materii si voi pune in el punctajul necesar
	for (i = 0; i < nr_materii; i++)
		credite_materii[i] = credite_materii[i] *
												(NOTA_10 - punctaj_materii[i]);
	//voi sorta vectorul credite_materii descrescator
	for (i = 0; i < nr_materii; i++) {
		for (j = i + 1; j < nr_materii; j++) {
			if (credite_materii[i] < credite_materii[j]) {
				aux = credite_materii[i];
				credite_materii[i] = credite_materii[j];
				credite_materii[j] = aux;
			}
		}
	}
//voi aduna punctele din materii la punctajul initial
//daca pucntajul initial + punctajul pe o materie nu satisface conditia
//ceruta de punctaj minim
//cresc nr_materii_
	for (i = 0; i < nr_materii; ++i) {
		if (punctaj_initial < punctaj_minim && credite_materii[i] != 0) {
			nr_materii_necesare++;
			punctaj_initial += credite_materii[i];
		}
	}

	if (nr_materii_necesare == 0)
		printf("%d", -1);
	else
		printf("%d", nr_materii_necesare);

	return 0;
}
