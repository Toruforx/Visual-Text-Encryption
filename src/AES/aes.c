#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

const char str16[] = "0123456789abcdef";

int m[250] = {0};

const unsigned int S[16][16] = {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
                                0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
                                0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
                                0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
                                0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
                                0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
                                0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
                                0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
                                0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
                                0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
                                0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
                                0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
                                0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
                                0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
                                0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
                                0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};

const unsigned int SR[16][16] = {0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
                                 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
                                 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
                                 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
                                 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
                                 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
                                 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
                                 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
                                 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
                                 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
                                 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
                                 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
                                 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
                                 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
                                 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
                                 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};

const unsigned int Rcon[10] = {0x01000000, 0x02000000,
                               0x04000000, 0x08000000,
                               0x10000000, 0x20000000,
                               0x40000000, 0x80000000,
                               0x1b000000, 0x36000000};

const int colM[4][4] = {2, 3, 1, 1,
                        1, 2, 3, 1,
                        1, 1, 2, 3,
                        3, 1, 1, 2};

const int colMR[4][4] = {14, 11, 13, 9,
                         9, 14, 11, 13,
                         13, 9, 14, 11,
                         11, 13, 9, 14};

unsigned int w[44] = {0};

void substitute(unsigned int *state)
{
    unsigned int tmp;
    for (int i = 0; i < 16; i++)
    {
        tmp = state[i];
        state[i] = S[tmp / 16][tmp % 16];
    }
    return;
}

void substituteR(unsigned int *state)
{
    unsigned int tmp;
    for (int i = 0; i < 16; i++)
    {
        tmp = state[i];
        state[i] = SR[tmp / 16][tmp % 16];
    }
    return;
}

void row_shift(unsigned int *state)
{
    unsigned int tmp[16] = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp[4 * j + i] = state[(4 * j + 5 * i) % 16];
        }
        for (int j = 0; j < 4; j++)
        {
            state[4 * j + i] = tmp[4 * j + i];
        }
    }
}

void row_shiftR(unsigned int *state)
{
    unsigned int tmp[16] = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp[4 * j + i] = state[(4 * j - 3 * i + 16) % 16];
        }
        for (int j = 0; j < 4; j++)
        {
            state[4 * j + i] = tmp[4 * j + i];
        }
    }
}

unsigned int multi(unsigned char a, unsigned char b)
{
    unsigned int ans = 0, v;
    for (int i = 0; i < 8; i++)
    {
        if ((b & 0x01) != 0)
        {
            ans ^= a;
        }
        v = a >> 7;
        a = a << 1;
        if (v != 0)
        {
            a ^= 0x1b;
        }
        b = b >> 1;
    }
    return ans;
}

void col_mix(unsigned int *state)
{
    unsigned int tmp, statep[16];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp = 0;
            for (int k = 0; k < 4; k++)
            {
                tmp ^= multi(colM[i][k], state[k + 4 * j]);
            }
            statep[i + 4 * j] = tmp & 0x00ff;
        }
    }
    for (int i = 0; i < 16; i++)
    {
        state[i] = statep[i];
    }
}

void col_mixR(unsigned int *state)
{
    unsigned int tmp, statep[16];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp = 0;
            for (int k = 0; k < 4; k++)
            {
                tmp = tmp ^ multi(colMR[i][k], state[k + 4 * j]);
            }
            statep[i + 4 * j] = tmp & 0x00ff;
        }
    }
    for (int i = 0; i < 16; i++)
    {
        state[i] = statep[i];
    }
}

unsigned int T(unsigned int x, int t)
{
    unsigned int tmp = 0;
    int r, c;
    x = (x << 8) | (x >> 24);
    for (int i = 0; i < 4; i++)
    {
        c = x % 16;
        x >>= 4;
        r = x % 16;
        x >>= 4;
        tmp |= S[r][c] << (8 * i);
    }
    tmp ^= Rcon[t];
    return tmp;
}

void generate_w(char *strk)
{
    unsigned int tmp, key[16];
    for (int i = 0; i < 16; i++)
    {
        key[i] = (unsigned int)strk[i];
        w[i / 4] |= key[i] << ((3 - i % 4) * 8);
    }
    for (int i = 4; i < 44; i++)
    {
        if (i % 4 != 0)
        {
            w[i] = w[i - 4] ^ w[i - 1];
        }
        else
        {
            w[i] = w[i - 4] ^ T(w[i - 1], i / 4 - 1);
        }
    }
    return;
}

void add(unsigned int *state, int t)
{
    unsigned int tmp = 0;
    for (int i = 0; i < 16; i++)
    {
        tmp |= state[i] << ((3 - i % 4) * 8);
        if (i % 4 == 3)
        {
            tmp ^= w[4 * t + i / 4];
            for (int j = 0; j < 4; j++)
            {
                state[i - j] = tmp % 256;
                tmp >>= 8;
            }
            tmp = 0;
        }
    }
}

char *int_to_str_en(unsigned int *ct)
{
    static char ans[33];
    ans[32] = '\0';
    unsigned int tmp;
    for (int i = 0; i < 16; i++)
    {
        tmp = ct[i];
        ans[2 * i] = str16[(tmp / 16) % 16];
        ans[2 * i + 1] = str16[tmp % 16];
    }
    return ans;
}

char *int_to_str_de(unsigned int *ct)
{
    static char anst[17];
    anst[16] = '\0';
    unsigned int tmp;
    for (int i = 0; i < 16; i++)
    {
        tmp = ct[i];
        anst[i] = (char)tmp;
    }
    return anst;
}

char *aes_encode(char *strx, char *strk)
{
    if (!(strlen(strx) == 16 && strlen(strk) == 16))
    {
        perror("invalid length");
        return NULL;
    }

    unsigned int bit[16] = {0};
    for (int i = 0; i < 16; i++)
    {
        bit[i] = (unsigned int)strx[i];
    }
    generate_w(strk);
    add(bit, 0);
    for (int t = 1; t < 10; t++)
    {
        substitute(bit);
        row_shift(bit);
        col_mix(bit);
        add(bit, t);
    }
    substitute(bit);
    row_shift(bit);
    add(bit, 10);
    return int_to_str_en(bit);
}

char *aes_decode(char *strx, char *strk)
{
    if (!(strlen(strx) == 32 && strlen(strk) == 16))
    {
        perror("invalid length");
        return NULL;
    }
    m['0'] = 0;
    m['1'] = 1;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    m['a'] = 10;
    m['b'] = 11;
    m['c'] = 12;
    m['d'] = 13;
    m['e'] = 14;
    m['f'] = 15;
    unsigned int bit[16] = {0};
    for (int i = 0; i < 16; i++)
    {
        bit[i] = m[strx[2 * i]];
        bit[i] = (bit[i] << 4) | m[strx[2 * i + 1]];
    }
    generate_w(strk);
    add(bit, 10);
    for (int t = 9; t > 0; t--)
    {
        row_shiftR(bit);
        substituteR(bit);
        add(bit, t);
        col_mixR(bit);
    }
    row_shiftR(bit);
    substituteR(bit);
    add(bit, 0);
    return int_to_str_de(bit);
}

#if 1
int main(int argc, void *argv[])
{
    char *option, *text, *key, *out;

    if (argc != 4)
    {
        printf("Usage: aes <--encode | --decode> <text> <key>\n");
        return 0;
    }
    else
    {
        option = argv[1];
        text = argv[2];
        key = argv[3];
        if (strcmp(option, "--encode") == 0)
        {
            out = aes_encode(text, key);
            puts(out);
        }
        else if (strcmp(option, "--decode") == 0)
        {
            out = aes_decode(text, key);
            puts(out);
        }
        else
        {
            printf("Usage: aes <--encode | --decode> <text> <key>\n");
            return 0;
        }
    }

    return 0;
}
#endif