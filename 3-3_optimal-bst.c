#include <stdio.h>
#include <string.h> // strtok, strchr
#include <stdlib.h> // atof
#define N 30
#define INF 10.00

float opt[N + 1][N + 1];
int k[N + 1][N + 1];
float p[N + 1];
char bst[N + 1][N + 1];
int n; // number of keys
int depth; // depth of optimal bst

void input() {
    char str[100];
    char *ptr;
    int i;

    fgets(str, sizeof(str), stdin);
    n = atoi(str + 9);

    ptr = strchr(str + 9, '(');
    ptr = strtok(ptr, ", "); ptr++;
    i = 1;
    while (ptr != NULL) {
        p[i] = atof(ptr) + p[i - 1]; i++;
        ptr = strtok(NULL, ", ");
    }
}

void init() {
    int i, j;
    // init opt
    for (i = 1; i <= n; i++) {
        opt[i][i] = 1.00;
        for (j = i + 1; j <= n; j++)
            opt[i][j] = INF;
    }

    // init k
    for (i = 1; i <= n; i++)
        k[i][i] = i;
}

void print_table() {
    int i, j;
    // print opt
    printf("\n  table of opt[i, j]\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++){
            if (j < i) printf("      ");
            else printf("%4.2f  ", opt[i][j]);
        }
        printf("\n");
    }

    // print k
    printf("\n  table of k[i, j]\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++){
            if (j < i) printf("    ");
            else printf("%4d", k[i][j]);
        }
        printf("\n");
    }
}

void calc_opt() {
    int i, j, r, s;
    float temp;
    for (s = 1; s <= n - 1; s++) {
        i = 1; j = i + s;
        while (j <= n) {
            for (r = i; r <= j; r++) {
                temp = 1;
                temp += (p[r - 1] - p[i - 1]) / (p[j] - p[i - 1]) * opt[i][r - 1];
                temp += (p[j] - p[r]) / (p[j] - p[i - 1]) * opt[r + 1][j];
                if (opt[i][j] - temp > 0) {
                    k[i][j] = r;
                    opt[i][j] = temp;
                }
            }
            i++; j++;
        }
    }
}

void make_bst(int i, int j, int d) {
    int m;
    if (i > j) return;
    if (d > depth) depth = d;
    m = k[i][j];
    bst[d][m] = m;
    make_bst(i, m - 1, d + 1);
    make_bst(m + 1, j, d + 1);
}

void print_bst() {
    int i, j;
    printf("\n  print out BST\n\n");
    for (i = 1; i <= depth; i++) {
        for (j = 1; j <= n; j++) {
            if (bst[i][j] == 0) printf(" ");
            else printf("%d", bst[i][j]);
        }
        printf("\n");
    }
}

int main() {
    input();
    init();
    calc_opt();
    print_table();
    make_bst(1, n, 1);
    print_bst();
}