#include <stdio.h>
#include <string.h> // strtok, strchr
#include <stdlib.h> // atoi
#define N 30
#define INF 10000

int opt[N + 1][N + 1];
int k[N + 1][N  + 1];
int d[N + 2];
int p[N + 1][2]; // number of parentheses on either side of each matrix
int n; // number of matrix

// input n, d
void input() {
    char str[100];
    char *ptr;
    int i;

    fgets(str, sizeof(str), stdin);
    n = atoi(str + 9); n--;

    ptr = strchr(str + 9, '(');
    ptr = strtok(ptr, ", "); ptr++;
    i = 1;
    while (ptr != NULL) {
        d[i] = atoi(ptr); i++;
        ptr = strtok(NULL, ", ");
    }
}

// init opt
void init() {
    int i, j;
    // init INF
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            opt[i][j] = INF;
}

// print arrays
void print_table() {
    int i, j;

    // print opt
    printf("\n  table of opt[i, j]\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++){
            if (j < i) printf("    ");
            else printf("%4d", opt[i][j]);
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

// calculate opt
void calc_opt() {
    int i, j, r, s, temp;
    for (s = 1; s <= n - 1; s++) {
        i = 1, j = i + s;
        while (j <= n) {
            for (r = i; r < j; r++) {
                temp = opt[i][r] + opt[r + 1][j] + d[i] * d[r + 1] * d[j + 1];
                if (temp < opt[i][j]) {
                    k[i][j] = r;
                    opt[i][j] = temp;
                }
            }
            i++; j++;
        }
    }
}

void make_p(int i, int j){
    int m = k[i][j];
    if (m - i >= 1) {
        p[i][0]++;
        p[m][1]++;
        make_p(i, m);
    }
    if (j - m - 1 >= 1) {
        p[m + 1][0]++;
        p[j][1]++;
        make_p(m + 1, j);
    }
}

void print_p() {
    int i;
    printf("\n  optimal chained matrix multiplication\n\n");
    for (i = 1; i <= n; i++) {
        while(p[i][0]--) printf("(");
        printf("A%d", i);
        while(p[i][1]--) printf(")");
    }
    printf("\n");
}

int main() {
    input();
    init();
    calc_opt();
    make_p(1, n);
    print_table();
    print_p();
}
