#include <stdio.h>

/* Function Prototype */
void towerOfHanoi(int n, char source, char auxiliary, char destination, int *moves);

int main() {
    int n, moves = 0;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C', &moves);

    printf("Total number of moves: %d\n", moves);

    return 0;
}

/* Function Definition */
void towerOfHanoi(int n, char source, char auxiliary, char destination, int *moves) {
    if (n == 1) 
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        (*moves)++;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary, moves);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    (*moves)++;
    towerOfHanoi(n - 1, auxiliary, source, destination, moves);
}