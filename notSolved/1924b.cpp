#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <set>
#include <map>
#include <string.h>

typedef long long int ll;

using namespace std;

ll solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> hl(m);
    unordered_map<ll, ll> mp;
    for (int i = 0; i < m; i++)
    {
        cin >> hl[i];
    }
    for (int i = 0; i < m; i++)
    {
        ll t;
        cin >> t;
        mp[hl[i]] = t;
    }
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 2)
        {
            ll l, r;
            cin >> l >> r;

            ll result = 0;
            vector<ll>::iterator low, high;
            for (int i = l; i <= r; i++)
            {
                if (mp.find(i) != mp.end())
                    continue;

                low = lower_bound(hl.begin(), hl.end(), i);
                high = upper_bound(hl.begin(), hl.end(), i);
                if (low != hl.begin() && high != hl.end())
                {
                    result += (mp[hl[low - hl.begin() - 1]]) * (hl[(high - hl.begin())] - i);
                }
            }
            cout << result << endl;
        }
        else
        {
            ll x, v;
            cin >> x >> v;
            hl.push_back(x);
            sort(hl.begin(), hl.end());
            mp[x] = v;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
}


// //#include <bits/stdc++.h>
// using namespace std;

// const int NR = 3e5+10;
// int x[NR], v[NR], len[NR << 2];
// long long a[NR], b[NR];
// long long suma[NR << 2], sumb[NR << 2], sumab[NR << 2];
// long long marka[NR << 2], markb[NR << 2];

// void Set(int p, long long c, long long d)
// {
// 	markb[p] += d;
// 	sumb[p] += d * len[p];
// 	sumab[p] += d * suma[p];
// 	if (!c) return;
// 	marka[p] = c;
// 	suma[p] = c * len[p];
// 	sumab[p] = c * sumb[p];
// }

// void merge(int p)
// {
// 	suma[p] = suma[p << 1] + suma[p << 1 | 1];
// 	sumb[p] = sumb[p << 1] + sumb[p << 1 | 1];
// 	sumab[p] = sumab[p << 1] + sumab[p << 1 | 1];
// }

// void pushdown(int p)
// {
// 	Set(p << 1, marka[p], markb[p]);
// 	Set(p << 1 | 1, marka[p], markb[p]);
// 	marka[p] = markb[p] = 0;
// }

// void build(int p, int pl, int pr)
// {
// 	len[p] = pr - pl + 1;
// 	if (pl == pr) return Set(p, a[pl], b[pl]);
// 	int mid = (pl + pr) >> 1;
// 	build(p << 1, pl, mid);
// 	build(p << 1 | 1, mid + 1, pr);
// 	merge(p);
// }

// void update(int p, int pl, int pr, int l, int r, long long c, long long d)
// {
// 	if (l <= pl && pr <= r) return Set(p, c, d);
// 	pushdown(p);
// 	int mid = (pl + pr) >> 1;
// 	if (l <= mid) update(p << 1, pl, mid, l, r, c, d);
// 	if (r > mid) update(p << 1 | 1, mid + 1, pr, l, r, c, d);
// 	merge(p);
// }

// long long query(int p, int pl, int pr, int l, int r)
// {
// 	if (l <= pl && pr <= r) return sumab[p];
// 	pushdown(p);
// 	int mid = (pl + pr) >> 1;
// 	if (r <= mid) return query(p << 1, pl, mid, l, r);
// 	if (l > mid) return query(p << 1 | 1, mid + 1, pr, l, r);
// 	return query(p << 1, pl, mid, l, r) + query(p << 1 | 1, mid + 1, pr, l, r);
// }

// set<int> s1, s2;

// int main()
// {
// 	ios::sync_with_stdio(0), cin.tie(0);
// 	int n, m, q;
// 	cin >> n >> m >> q;
// 	for (int i = 1; i <= m; i++)
// 		cin >> x[i], s1.insert(x[i]), s2.insert(-x[i]);
// 	for (int i = 1; i <= m; i++)
// 		cin >> v[i], a[x[i]] = v[i];
// 	for (int i = n; i >= 1; i--)
// 		if (a[i]) b[i] = 0;
// 		else b[i] = b[i + 1] + 1;
// 	for (int i = 1; i <= n; i++)
// 		if (!a[i]) a[i] = a[i - 1];
// 	build(1, 1, n);
// 	while (q--)
// 	{
// 		int t, x, y;
// 		cin >> t >> x >> y;
// 		if (t == 1)
// 		{
// 			int l = -(*s2.upper_bound(-x));
// 			int r = *s1.upper_bound(x);
// 			s1.insert(x), s2.insert(-x);
// 			update(1, 1, n, x, r - 1, y, 0);	
// 			update(1, 1, n, l + 1, x, 0, x - r);
// 		}
// 		else cout << query(1, 1, n, x, y) << endl;
// 	}
// 	return 0;
// }