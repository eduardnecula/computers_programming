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
so "Correct" will be displayed, otherwise "Wrong".
8) Everything that has been read from STDIN will be equal to 0, in order to be able to
move on (if necessary) to the next puzzle.

* Note: At the end of everything after int main (void) {...} there is a blank line,
which should not be deleted.