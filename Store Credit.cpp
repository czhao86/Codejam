#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<int> storecredit(int credit, vector<int> items)
	{
		vector<int> ans;
		ans.clear();
		vector<pair<int, int>> per;
		per.clear();
		int n = items.size();
		for (int i = 0; i < n; ++i)
		{
			per.push_back(make_pair(items[i], i + 1));
		}
		sort(per.begin(),per.end());
		int start = 0, end = n - 1;
		while (start < end)
		{
			if (per[start].first + per[end].first == credit)
			{
				ans.push_back(per[start].second);
				ans.push_back(per[end].second);
				break;
			}
			else if (per[start].first + per[end].first < credit)
				start++;
			else if (per[start].first + per[end].first > credit)
				end--;
		}
		return ans;
	}
};

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("A-large-practice.in");
	outFile.open("A-large-practice.txt");
	int nnn;
	inFile >> nnn;
	for (int iii = 0; iii < nnn; ++iii)
	{
		outFile << "Case #" << iii+1 << ": ";
		int credit;
		inFile >> credit;
		int nn;
		inFile >> nn;
		vector<int> items(nn, 0);
		for (int i = 0; i < nn; ++i)
		{
			inFile >> items[i];
		}
		Solution sol;
		vector<int> res = sol.storecredit(credit, items);
		int a = res[0];
		int b = res[1];
		outFile << min(a, b) << ' ' << max(a, b) << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
