#include<bits/stdc++.h>




using namespace std;







void build(int a[], int s, int e, int tree[], int index) {

	if (s == e) {

		tree[index] = a[s];

		return;

	}

	int mid = (s + e) / 2;

	build(a, s, mid, tree, 2 * index);

	build(a, mid + 1, e, tree, 2 * index + 1);

	tree[index] = tree[2 * index] + tree[2 * index + 1];

	return;

}




int query(int tree[], int s, int e, int qs, int qe, int index) {

	if ((s >= qs) and (qe >= e)) {

		return tree[index];

	}

	if ((qe < s) or (qs > e)) {

		return 0;

	}

	int mid = (s + e) / 2;

	int left = query(tree, s, mid, qs, qe, 2 * index);

	int right = query(tree, mid + 1, e, qs, qe, (2 * index) + 1);

	return left + right;

}




void update(int tree[], int s, int e, int index, int key, int val) {

	if ((key > e) or (key < s)) return;

	if ((s == e) and (s == key)) {

		tree[index] = tree[index] + val;

		return;

	}

	int mid = (s + e) / 2;

	update(tree, s, mid, 2 * index, key, val);

	update(tree, mid + 1, e, 2 * index + 1, key, val);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);

	return;

}




int32_t main()

{	

	// Input number of queries

	int n;

	cin >> n;

	int a[n];

	int tree[4 * n + 1];

	for(int i=0;i<n;i++) cin >> a[i];

	build(a, 0, n - 1, tree, 1);

	int m;

	cin >> m;

	while (m--) {

		int x, y;

		cin >> x >> y;

		cout << query(tree, 1, n , x, y, 1) << "\n";

	}




	return 0;

}
