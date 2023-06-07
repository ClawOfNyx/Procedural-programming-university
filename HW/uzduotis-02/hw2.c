#include <stdio.h>
#include <stdbool.h>

#define MAX 100

/*int validation(char letter);*/
void spiral(int n, int m, int mat[MAX][MAX]);

int main() {
    int n;
    int i, j;
    int mat[MAX][MAX];

    printf("\nIveskite skaiciu N: ");
    scanf("%d", &n);
    
    spiral(n, n, mat);

    printf("Matrica %d-dydzio:\n", n);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void spiral(int n, int m, int mat[MAX][MAX]) {
	int val = 1;
    int k = 0, l = 0, i, j;

    /*  val - skaiciai, kurie sudedami i matrica
        k - pradinis eilutes indeksas
        m - paskutinis eilutes indeksas
        l - pradinis stulpelio indeksas
        n - paskutinis stulpelio indeksas */

	
	while (k < m && l < n) {
        /*pirma eilute is likusiu*/
		for (i = l; i < n; ++i) {
			mat[k][i] = val++;
        }
		++k; /*redaguos viena eilute nuo virsaus maziau*/

        /*paskutinis stulpelis is likusiu*/
		for (i = k; i < m; ++i) {
			mat[i][n - 1] = val++;
        }
		--n; /*redaguos vienu stulpeliu nuo desines maziau*/

        /*paskutine eilute is likusiu*/
		if (k < m) {
			for (i = n - 1; i >= l; --i) {
				mat[m - 1][i] = val++;
            }
			--m; /*redaguos per viena eilute nuo apacios maziau*/
		}

        /*pirmas stulpelis is likusiu*/
		if (l < n) {
			for (i = m - 1; i >= k; --i) {
				mat[i][l] = val++;
            }
			++l; /*redaguos vienu stulpeliu maziau nuo kaires*/
		}
	}
}

/*int validation(char letter) {
    int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && (num > 0) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            if (num == 0) {
                printf("\nNetinkama ivestis, nuline matrica yra tuscia, iveskite teigima sveika skaiciu %c:", letter);
            } else {
                printf("\nNetinkama ivestis, iveskite teigima sveika skaiciu %c:", letter);
            }
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}*/