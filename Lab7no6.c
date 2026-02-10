#include <stdio.h>

void generateUniqueArray(int M, int N, int arr[20][20]);
void displayArray(int M, int N, int arr[20][20]);

int main() {
    int M, N;
    int data[20][20];

    srand(time(NULL));

    printf("Enter M and N (2 < M,N < 20): ");
    scanf("%d %d", &M, &N);

    
    if (M <= 2 || M >= 20 || N <= 2 || N >= 20) {
        printf("Invalid input! Please enter values between 3 and 19.\n");
        return 1;
    }

    
    generateUniqueArray(M, N, data);
    displayArray(M, N, data);

    return 0;
}

void generateUniqueArray(int M, int N, int arr[20][20]) {
    int used[201] = {0};
    int i,j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            int num;
            do {
                num = (rand() % 101) + 100;
            } while (used[num] == 1);
            
            arr[i][j] = num;
            used[num] = 1; 
        }
    }
}

void displayArray(int M, int N, int arr[20][20]) {
    printf("\n--- 2D Array (%d x %d) ---\n", M, N);
    int i,j;
	for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
