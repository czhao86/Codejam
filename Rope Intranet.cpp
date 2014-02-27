#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct line
{
	int x, y;
};

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
		int N;
		inFile >> N;
		line dummy;
		dummy.x = 0, dummy.y = 0;
		vector<line> p(N, dummy);
		for (int i = 0; i < N; ++i)
		{
			inFile >> p[i].x;
			inFile >> p[i].y;
		}
		int ans = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if ((p[i].x - p[j].x)*(p[i].y - p[j].y) < 0) ans++;
			}
		}
		outFile << ans << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
