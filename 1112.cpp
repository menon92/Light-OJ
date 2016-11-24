/**
  * Problem : 1112-Curious Robin Hood
  * Verdict : Accepted.
  * Writer  : Mehadi Hasan Menon.
  * Date    : 24.11.16
  **/

#include <iostream>
#include <cstdio>

using namespace std;

const int mx = 100005;
int ara[mx];
int tree[mx * 3];

int money;

void init(int node, int b, int e)
{
    if(b == e) {
        tree[node] = ara[b]; return;
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

void giveMoneyFromI(int node, int b, int e, int i)
{
    if(b > i || e < i) {
        return;
    }

    if(b == i && e == i) {
        money = tree[node];

        //cout << "money: " << money << endl;

        tree[node] = 0; return;
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    giveMoneyFromI(left, b, mid, i);
    giveMoneyFromI(right, mid + 1, e, i);

    tree[node] = tree[left] + tree[right]; // update tree
}

void addMoneyToI(int node, int b, int e, int i, int v)
{
    if(b > i || e < i) {
        return ;
    }

    if(b == i && e == i) {
        tree[node] += v; return;
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    addMoneyToI(left, b, mid, i, v);
    addMoneyToI(right, mid + 1, e, i, v);

    tree[node] = tree[left] + tree[right]; // update tree
}

int getMoneyFromItoJ(int node, int b, int e, int i, int j)
{
    if(b > j || e < i) {
        return 0;
    }
    if(b >= i && e <= j) {
        return tree[node];
    }

    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    int p1 = getMoneyFromItoJ(left, b, mid, i, j);
    int p2 = getMoneyFromItoJ(right, mid + 1, e, i, j);

    return p1 + p2;
}

int main()
{
   // freopen("1112 - Curious Robin Hood.txt", "r+", stdin);

    int tc, n, q, v, i, j;
    int command;

    //cin >> tc;
    scanf("%d", &tc);
    for(int a = 1; a <= tc; a++)
    {
        //cin >> n >> q;
        scanf("%d %d", &n, &q);
        for(int b = 1; b <= n; b++)
        {
            //cin >> ara[b];
            scanf("%d", &ara[b]);
        }

        init(1, 1, n);

        //cout << "Case " << a << ":" << endl;
        printf("Case %d:\n", a);
        for(int b = 1; b <= q; b++)
        {
            //cin >> command;
            scanf("%d", &command);
            if(command == 1) {
                //cin >> i;
                scanf("%d", &i);
                giveMoneyFromI(1, 1, n, i + 1);

                //cout << money << endl;
                printf("%d\n", money);
                money = 0;
            }
            else if(command == 2) {
                //cin >> i >> v;
                scanf("%d %d", &i, &v);

                    addMoneyToI(1, 1, n, i + 1, v);

            }
            else if(command == 3) {
                //cin >> i >> j;
                scanf("%d %d", &i, &j);
                //cout << getMoneyFromItoJ(1, 1, n, i + 1, j + 1) << endl;
                printf("%d\n", getMoneyFromItoJ(1, 1, n, i + 1, j + 1));

            }
        }
    }

    return 0;
}
