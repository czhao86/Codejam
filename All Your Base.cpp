#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("A-large-practice.in");
	outFile.open("A-large-practice.out");
	int TC;
	inFile >> TC;
	for (int iii = 0; iii < TC; ++iii)
	{
		outFile << "Case #" << iii + 1 << ": ";
		string tmp;
		inFile >> tmp;
		vector<pair<char, int>> vp;
		vp.push_back(make_pair(tmp[0], 1));
		int n = 0;
		for (int i = 1; i < tmp.length(); ++i)
		{
			bool test = true;
			for (int j = 0; j < vp.size(); ++j)
			{
				if (tmp[i] == vp[j].first)
				{
					test = false;
					break;
				}
			}
			if (test)
			{
				vp.push_back(make_pair(tmp[i], n));
				if (n == 0) n++;
				n++;
			}
		}
		int vs = vp.size();
		if (vs == 1) vs++;
		long long ans = 0;
		for (int i = 0; i < tmp.length(); ++i)
		{
			int v;
			for (int j = 0; j < vp.size(); ++j)
			{
				if (tmp[i] == vp[j].first)
				{
					v = vp[j].second;
					break;
				}
			}
			//ans += v*pow(vs, tmp.length() - i - 1);
			ans = ans*vs + v;
		}
		outFile << ans << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
