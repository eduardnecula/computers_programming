Google Translate
Translation types
Text translation
Source text
@2021
Necula Eduard-Ionut 332CA

Tema 2 Algoritmi Paraleli si Distribuiti

Rulare tema: (din src)
javac* .java
java Tema2 <workers> <in_file> <out_file>

Programul Main este implementat in Tema2.java

Ce se intampla in Main: Tema2.java

    0 - ETAPA INPUT: ReadInput.java

1. Se citeste input-ul primit prin argumente, atunci cand se ruleaza tema.

2. Toate fisierele sunt citite si se calculeaza de cate task-uri am nevoie.
De exemplu, daca dimensiunea tuturor fisierlor este de 41 de octeti si
impart spatiul in X caractere, o sa rezulte 5 task-uri, int nr = 41 / 19 + 41 % 10.
Iar acest lucru se intampla pentru fiecare fisier in parte.

3. Voi citi din fisiere, si pentru fiecare fisier, voi pune in task-urile alocate,
cele X caractere, cu tot cu spatii si alte caractere intalnite.

    I - ETAPA MAP: Task.java + MapTask.java

4. Incepe prima partea de paralelizare, Etapa Map. Se vor porni atatea fire de
executie, pe cate primesc la input. Fiecare fir de executie primeste lista de
task-uri. In aceasta etapa mai intai se rezolva plasarea corecta a cuvintelor,
in fiecare task. De exemplu:
in1.txt
Task0: [afara es]
Task1: [te frumo]
Task2: [s]

Se poate observa ca unele cuvinte nu sunt puse cum trebuie in task-uri. Programul
parcurge fiecare task individual, din fiecare fisier, si va incerca sa modifice
programul, si la stanga si la dreapta. In secventa [afara es], programul va incerca
sa modifice la stanga, insa vede ca nu se afla nimic, apoi va modifica la dreapta.
Vede ca in partea dreapta nu se termina in spatiu, asa ca se va uita la urmatorul
task, vede ca nu incepe in spatiu, deci poate sa "fure" primul cuvant pana la primul
spatiu. Task0 va deveni [afara este]. Singurul lucru care se modifica in task
o sa fii offset-ul, si dimensiunea / lungimea nr de caractere citite, de la offset.

5. Dupa ce se face asezarea corecta a cuvintelor in fiecare task, se va pune in 
map-ul asociat task-ului, lungimea cuvintelor si de cate apare fiecare.

6. Cand se termina toate firele de executie, se va da join la operatiile de mai sus.

    II - ETAPA REDUCE: Reduce.java

7. In secunda asta, stim fiecare task ce map are, mai exact fiecare lungime de cuvant
si nr de aparitii puse intr-un map. Incepe etapa reduce, in care imbinam tot ce s-a
petrecut la etapa map doar ca intr-un singur map, pe fiecare fisier in parte.

8. In clasa Reduce.Java se vor parcurge toate task-urile de la etapa Map.
Daca task-ul respectiv face parte din fisierul lui, voi face un map final, pentru
acel fisier, in care pun exact ca la etapa MAP, lugimea cuvantului maxim, cat si
numarul de aparitii ale acestuia. Dupa ce termin de completat map-ul cu informatiile
potrivite, voi trece la calcularea rang-ului fisierului.
    Se va parcurge map-ul creat si cu ajutorul formulei urmatoare se va calcula rangul:
    float rang = [fib(lungimeCuvMaxim + 1) * nrAparitiiCuvLungimeMax] / nrCuvFisier
    fib - functia fibonacii care intoarce nr din secventa de pe o anumita pozitie

9. Dupa terminarea firelor de executie, se va da si al 2-lea join. Acum fiecare fisier
are calculat rangul, lungimea cuvantului maximal, cat si nr de aparitii ale acestuia.

    III - SORTAREA FISIERELOR

10. Pentru a sorta fisierele, fiecare informatie ce se gasea in obiectele de tip Reduce,
au fost puse in obiecte de tip WriteOutput.java, ce implementau Comparable.

11. Obiectele sunt puse intr-o lista, sunt sortate descrescator in functie de rang, iar la
final vor fi afisate in fisierul de output primit de la linia de comanda.

Observatii:
Codul trece 25 - 28 de puncte din 30, daca se ruleaza etapa map secvential folosind run(),
in loc de start, atunci programul ia 30/30. Probabil este ori o problema de separatori,
ori ceva modifica ceva inainte sa aiba voie sa fie modificata. Pica doar la testul cel mai
mic, asa ca pe teste mari codul este bun, posibil sa fie o alta problema mica prin cod.

Se respecta conceptul de Map-Reduce, deoarece fiecare fisier este impartit pe bucati, se face
un map pentru acea bucata, iar la final se pun toate map-urilile de pe fiecare task,
intr-un singur map pe fiecare fisier, iar totul se realizeaza in paralel,
pe fiecare fir de executie.

Durata tema: 20-25 de ore max, impartita pe 3 zile, iar 8-10 ore doar sa inteleg prima problema
de mai jos.

Probleme intalnite:
    Problema de a intelege de ce trece primul test0.txt, care este cel mai usor,
iar la restul pica. S-a rezolvat prin crearea de alte teste mai mici, in care 
s-a observat ca daca aveam (5, 1) si alt (5, 2) mie nu-mi dadea (5, 3), imi dadea
(5, 2), deoarece pe primul teste mergea sa aduni (5, 1 +1) si sa dea (5, 2)
    Grija la separatori. Daca nu esti atent si omiti ceva, se duce totul.
    Anumite caractere cum ar fi " ' ", pot sa fie codat diferit ori pe windows, 
ori pe linux. Pe windows cu Intelijei voia un caracter pentru ghilimea, iar pe linux,
altul, o problema stupida rau :)).

Lifehack:
    Scrii problema pe hartie, intelegi ce vrea de la tine, facand exemplul scurt,
abia apoi scrii cod 
5,000 / 5,000
Translation results
NECULA EDUARD-IONUT 322 CA @ 2020

~ Theme 1 PC ~

Problem 1 - On the fly analysis

* The program reads a number of trees from STDIN, then reads the trees.
* The program to be able to find special trees, uses the following
reasoning:
a) The first 2 trees read, will be stored in the variables "first_tree" and
"al_doilea_copac". They can't be special trees.
b) When the third tree is read (if any), it will be memorized
in the variable "tree".
c) The program starts to determine if the "second_tree" is bigger
than the "first_tree" and than the tree, to find out if it's special.
d) Special trees are grouped in the variable "sum_of_species_species" and are
number in the variable "nr_copaci_speciali".
e) At the same time, determine the minimum tree from the para position and
the maximum tree in the odd position.
f) At the end of the iteration. Put "second_tree" in "first_tree",
and in the "second_tree" is put "tree". Thus, the program
memorize all the time (for no trees> = 3), 3 trees.
* The program displays:
a) The sum of the special trees.
b) Arithmetic mean of special trees.
c) The maximum special tree on the odd position.
d) The special minimum tree on the para position.

Note: At the end of everything after int main (void) {...} there is a blank line,
which should not be deleted.



Problem 2 - Properties of natural numbers

* The program reads a number from STDIN.
* After reading, the following transformations will be applied to the number:
a) Using the "int no_order_increase (int number)" function, the digits
of the number will be ordered ascending: 9870 becomes 789. The figure 0 will
be ignored. The function uses another auxiliary function:
"int number_numbers_not_zero (int no)" which counts the digits of the number,
non-zero.
b) With the help of the function "int no_ordered_desc (int number)", the digits
the number will be sorted in descending order: 1230 becomes 3210.
The function uses another auxiliary function
"int number_digit (int no)", which counts the digits of the number.
c) Numbers obtained from step a) and step b) will be subtracted, and
the resulting number will go through step a) b) and c) for 100 times
* A vector with 100 elements will be obtained. This vector will be searched
the first number to be repeated, and if it is found, its position will
be remembered.
* The program displays how many numbers there are up to periodic numbers
* The program displays the numbers from the period, without being repeated.

Note: At the end of everything after int main (void) {...} there is a blank line,
which should not be deleted.



Problem 3 - Improving scores

* The program reads from STDIN:
a) Number of subjects
b) Score on each subject
c) Subject credits
d) Minimum required score
* In the variable "initial_point", enter the initial score.
* The program reuses for memory efficiency, the vector for credits
matter. It will be placed respecting the formula:
"subject_ credits * (NOTE_10 - subject_tips [i]);", for each
element in part.
* The new vector obtained, ascending, will be sorted
* At the initial score, the first value from will be added (if needed)
vector, until the initial score is greater than or equal to the score
minimum required. For each material added to the vector, it will increase
counter "no_subject_subject".
* The program displays at the end, no_subject_subjects, representing the number
of materials needed to take a child's scholarship.

Note: At the end of everything after int main (void) {...} there is a blank line,
which should not be deleted.



Problem 4 - Nonogram checker

* The program reads from STDIN:
a) The number of the puzzle
b) The number of lines
c) Number of columns
d) For each line
1) It reads from the first position, how many items I will read in
continuation. These represent the length of the pieces on the line
e) For each column
1) It reads from the first position, how many items I will read in
continuation. These represent the length of the pieces on the column.
f) Read the puzzle matrix.
g) The program that says if it is correct or not works like this:
1) Add the elements on each line separately and place
in a vector: "sum_lin_vect []"
2) Add the elements on each column separately and place
in a vector: "sum_col_vect []"
3) Gather the items on each line of the puzzle separately, and
put in a vector: "sum_lin_puz []"
4) Gather the items on each column of the puzzle separately, and
put in a vector: "sum_col_puz []"
5) If in the line vector compared to the line vector in the puzzle is
find something different grow counter "correct_contour_liner"
6) If in the column vector compared to the column vector in the puzzle
find something different grow counter "correct_contour_col"
7) If the 2 counters remain 0, it means that there are no differences,
so "Correct" will be displayed, otherwise "Wrong"
More about this source text
Source text required for additional translation information
Send feedback
Side panels
5,000 character limit. Use the arrows to translate more.
