//NECULA EDUARD IONUT 322 CA @2020
#include <stdio.h>
#include <math.h>

#define LONG_NUMBER 100000000.0

int main(void)
{
	long i; //contor
	long double nr_copaci, copac; //ce voi citi de la STDIN
	long double suma_copaci_speciali = 0.f, media_arit = 0.f; //suma si media
	float xmax_impar = 0, xmin_par = 0; //copac max si copac min
	//in primul_copac si al_doilea_copac salvez primele 2 numere
	//iar al treilea va fi citit de la tastatura
	//asa pot compara mereu elementul din mijloc cu cel din stanga si din dr
	float primul_copac = 0, al_doilea_copac = 0;
	float nr_copaci_speciali = 0;
	int check = 0;

	scanf("%Lf", &nr_copaci);
	for (i = 0; i < nr_copaci; i++) {
		scanf("%Lf", &copac); //citesc fiecare copac
		if (i == 0) //primul copac
			primul_copac = copac;

		if (i == 1) //al doilea copac
			al_doilea_copac = copac;

		if (i >= 2) {
			if (al_doilea_copac > primul_copac &&
				al_doilea_copac > copac) {
				if ((i % 2) == 1) {
					if (check == 0) {
						xmin_par = al_doilea_copac;
						check = 1;
					} //asta inseamna ca nu am mai intrat pe primul copac par
					if (al_doilea_copac < xmin_par)
						xmin_par = al_doilea_copac;
				} else {
					if (al_doilea_copac > xmax_impar)
						xmax_impar = al_doilea_copac;
					}
				suma_copaci_speciali += al_doilea_copac;
				nr_copaci_speciali++;
			} //ma plimb doar cu 3 elemente, mut pozitiile
			primul_copac = al_doilea_copac;
			al_doilea_copac = copac;
		}
	}

	printf("%0.Lf\n", suma_copaci_speciali);//suma copacilor speciali
	if (nr_copaci_speciali == 0) {
		printf("%.7Lf\n", media_arit);//afisez 0 daca nu am copaci speciali
	} else {//media aritmetica
		media_arit = suma_copaci_speciali / nr_copaci_speciali;
		printf("%.7Lf\n", (media_arit * LONG_NUMBER) / LONG_NUMBER);
	}
	printf("%.0f\n", xmax_impar);//inaltime copac max de pe poz impara
	printf("%.0f\n", xmin_par);//inaltime copac min de pe poz para

	return 0;
}
