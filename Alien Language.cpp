#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("A-large-practice.in");
	outFile.open("A-large-practice.out");
	int L, D, N;
	inFile >> L >> D >> N;
	vector<string> al(D, "");
	for (int i = 0; i < D; ++i)
	{
		inFile >> al[i];
	}
	string tmp;
	getline(inFile, tmp);
	for (int iii = 0; iii < N; ++iii)
	{
		outFile << "Case #" << iii + 1 << ": ";
		getline(inFile, tmp);
		vector<string> now;
		for (int i = 0; i < tmp.length(); ++i)
		{
			if (tmp[i] == '(')
			{
				for (int j = i; j < tmp.length(); ++j)
				{
					if (tmp[j] == ')')
					{
						now.push_back(tmp.substr(i + 1, j - i - 1));
						i = j;
						break;
					}
				}
			}
			else now.push_back(tmp.substr(i, 1));
		}
		int ans = 0;
		for (int i = 0; i < D; ++i)
		{
			int n = 0;
			for (int j = 0; j < L; ++j)
			{
				if (now[j].find(al[i][j]) == string::npos) break;
				n++;
			}
			if (n == L) ans++;
		}
		outFile << ans << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
