#include<stdio.h>
#include<string.h>
#define CRC_DEGREE 16
#define CRC_POLY 0x11021
static unsigned long binstr_to_ul(const char *s) {
    unsigned long v = 0;
    for (; *s; s++) {
        v <<= 1;
        if (*s == '1') {
            v |= 1;
        }
    }
    return v;
}
static void ul_to_binstr(unsigned long v, int len, char *out) {
    out[len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        out[i] = (v & 1) ? '1' : '0';
        v >>= 1;
    }
}
int main(void) {
    char msg[512];
    scanf("%511s", msg);

    int mlen = strlen(msg);
    unsigned long dividend = binstr_to_ul(msg) << CRC_DEGREE;
    int total_bits = mlen + CRC_DEGREE;
    unsigned long top = 1UL << (total_bits - 1);

    for (int i = 0; i < mlen; i++) {
        unsigned long cur = top >> i;
        if (dividend & cur) {
            unsigned long aligned = (unsigned long)CRC_POLY << (total_bits - CRC_DEGREE - i);
            dividend ^= aligned;
        }
    }

    unsigned long crc = dividend & ((1UL << CRC_DEGREE) - 1);
    char out[CRC_DEGREE + 1];
    ul_to_binstr(crc, CRC_DEGREE, out);

    printf("CRC: %s\nCodeword: %s%s\n", out, msg, out);

    return 0;
}