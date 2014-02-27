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
	int nnn;
	inFile >> nnn;
	for (int iii = 0; iii < nnn; ++iii)
	{
		outFile << "Case #" << iii + 1 << ": ";
		int n;
		inFile >> n;
		vector<long long> first(n, 0);
		vector<long long> second(n, 0);
		for (int i = 0; i < n; ++i)
		{
			inFile >> first[i];
		}
		for (int i = 0; i < n; ++i)
		{
			inFile >> second[i];
		}
		sort(first.begin(), first.end());
		sort(second.begin(), second.end());
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans += first[i] * second[n - 1 - i];
		}
		outFile << ans << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
