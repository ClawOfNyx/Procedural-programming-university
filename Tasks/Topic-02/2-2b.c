#include <stdio.h>
#include <math.h>

int convertToDec(long long binary) {
    int decimal = 0, remains;

    for (int i = 0; binary != 0; i++) {
        remains = binary % 10;
        binary /= 10;
        decimal += remains * pow(2, i);
    }

    return decimal;
}

long long convertToBin(int decimal) {
    long long binary = 0;
    int remains;

    for (long long i = 1; decimal != 0; i = i*10) {
        remains = decimal % 2;
        decimal /= 2;
        binary += remains * i;
    }

    return binary;
}

int main() {
    printf("a) 11011(2) = %d(10), 10010100(2) = %d(10), 11001011010101(2) = %d(10)\n",
           convertToDec(11011), convertToDec(10010100), convertToDec(11001011010101));
    printf("b) 37(10) = %lld(2), 241(10) = %lld(2), 2487(10) = %lld(2)\n",
           convertToBin(37), convertToBin(241), convertToBin(2487));
    printf("c) 6E2(16) = %d(10), ED33(16) = %d(10), 123456(16) = %d(10)\n", 0x6E2, 0xED33, 0x123456);
    printf("d) 243(10) = %x(16), 2612(10) = %x(16), 4612(10) = %x(16)\n", 243, 2483, 4612);

    return 0;
}


