/**
  * Problem : 1082-Array Queries
  * Status : Accepted.
  * Writer : Mehaidi Hasan Menon
  * Date : 23.11.16
  **/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mx = 100005;
int ara[mx];
int tree[mx * 3];

void init(int node, int b, int e)
{
    if(b == e) {
        tree[node] = ara[b];
        return ;
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = min(tree[left], tree[right]);
}

int quary(int node, int b, int e, int i, int j)
{

    if(b > j || e < i) {
       return mx; // 100005
    }

    if(b >= i && e <= j) {
        return tree[node];
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    int q1 =  quary(left, b, mid, i, j);
    int q2 = quary(right, mid + 1, e, i, j);

    return min(q1, q2);
}

int main()
{
    freopen("1082 - Array Queries.txt", "r+", stdin);

    int tc, n, q, i, j;

    scanf("%d", &tc);
    for(int a = 1; a <= tc; a++)
    {
        scanf("%d %d", &n, &q);
        for(int b = 1; b <= n; b++) {
            scanf("%d", &ara[b]);
        }

        init(1, 1, n);

        int ans;
        printf("Case %d:\n", a);
        for(int c = 1; c <= q; c++)
        {
            scanf("%d %d", &i, &j);

            ans = quary(1, 1, n, i, j);

            printf("%d\n", ans);
        }

    }
    return 0;
}
