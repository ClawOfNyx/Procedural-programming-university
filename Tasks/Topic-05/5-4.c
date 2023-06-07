#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int validation(char letter) {
    int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite sveika skaiciu", letter);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}

bool isPrime(int n) {
        if (n <= 1)
            return false;
 
        else if (n == 2)
            return true;
 
        else if (n % 2 == 0)
            return false;
 
        // If not, then just check the odds
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
}

int main() {
    int c = 0;
    int arr[100000];
    int primes[100000];
    int length = 100000;

    for (int i = 0; i < 100000; ++i) {
        printf("\nIveskite skaiciu: ");
        arr[i] = validation(' ');

        if (arr[i] <= 0) {
            break;
        }

        if (isPrime(arr[i])) {
            primes[c] = arr[i];
            ++c;
        }
    }

    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (primes[i] == primes[j]) {
                for (int k = j; k < length - 1; ++k) {
                    primes[k] = primes [k + 1];
                }
                --length;
                --j;
            }
        }
    }

    for (int i = 0; i < length; ++i) {
        if (primes[i] != 0) {
            printf("%d ", primes[i]);
        }
    }

}