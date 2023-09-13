#include<iostream>
#include<map>
#include<vector>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	map<int, int> m, m_idx;

	int n, c,idx=0;
	cin >> n >> c;

	while (n--)
	{
		int x;
		cin >> x;

		if (m.find(x) == m.end()) {
			m_idx[x] = idx;
			idx++;
		}
		m[x]++;
	}

	while (!m.empty()) {
		int max = -1, max_idx = 0,max_val=0;
		for (auto& t : m) {
			if (max < t.second)
			{
				max = t.second;
				max_idx = m_idx[t.first];
				max_val = t.first;
			}
			else if (max == t.second and max_idx > m_idx[t.first])
			{
				max = t.second;
				max_idx = m_idx[t.first];
				max_val = t.first;
			}
		}
		for (int i = 0; i < m[max_val]; i++)
			cout << max_val << " ";
		m.erase(max_val);
	}

	return 0;
}