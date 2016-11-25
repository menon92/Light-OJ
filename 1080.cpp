/**
  * Problem : 1080 - Binary Simulation
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 25.11.16
  **/
#include <iostream>
#include <cstdio>
#include <cstring>

const int mx = 1000005; // SIZE MUST 10^6 NOT 10^5
char ara[mx]; int ans;

struct node {
    int prop;
}tree[mx * 3];

void update(int node, int b, int e, int i, int j)
{
    if(b > j || e < i) {
        return ;
    }
    if(b >= i && e <= j) {
        tree[node].prop++;
        return;
    }
    int mid = (b + e) / 2; int left = 2 * node; int right = 2 * node + 1;

    update(left, b, mid, i, j);
    update(right, mid + 1, e,  i, j);
}

void quary(int node, int b, int e, int i, int carryProp = 0)
{
    carryProp += tree[node].prop;

    if(b > i || e < i) {
        return;
    }
    if(b >= i && e <= i)
    {
        if(carryProp % 2 == 0) {

            ans = ara[i - 1] - '0'; // ara[i] change to ara[i - 1];
            return;
        }
        else {
            int bit = (ara[i - 1] - '0');
            bit ^= 1;
            ans =  bit;
            return;
        }
    }
    int mid = (b + e) / 2; int left = 2 * node; int right = 2 * node + 1;

    quary(left, b, mid, i, carryProp);
    quary(right, mid + 1, e, i, carryProp);
}

int main()
{
    freopen("1080.txt", "r+", stdin);

    int t, n, q, i, j;
    char command;

    scanf("%d", &t);
    for(int a = 1; a <= t; a++)
    {
        scanf("%s", &ara);
        int len = strlen(ara);
        scanf("%d", &q);
        getchar();

        printf("Case %d:\n", a);
        for(int h = 1; h <= q; h++)
        {
            scanf("%c",  &command);
            if(command == 'I') {
                scanf("%d %d", &i, &j);
                update(1, 1, len, i, j);
            }
            else if(command == 'Q') {
                scanf("%d", &i);
                quary(1, 1, len, i);
                printf("%d\n", ans);

            }
            getchar();
        }
        for(int i = 0; i <= mx; i++) {
            tree[i].prop = 0;
        }
    }
    return 0;
}
