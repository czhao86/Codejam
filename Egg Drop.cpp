#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void initialDP(long long D, long long B, vector<vector<long long>> &Fdp)
{
	for (long long i = 1; i <= B; ++i)
		Fdp[i][1] = 1;
	for (long long j = 1; j <= D; ++j)
		Fdp[1][j] = j;
	for (long long i = 2; i <= B; ++i)
	{
		for (long long j = 2; j <= D; ++j)
		{
			Fdp[i][j] = Fdp[i-1][j-1] + Fdp[i][j-1] + 1;
			if (Fdp[i][j] >= 4294967296) Fdp[i][j] = -1;
			if (Fdp[i - 1][j - 1] < 0 || Fdp[i][j - 1] < 0) Fdp[i][j] = -1;
		}
	}
}

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("C-small-practice.in");
	outFile.open("C-large-practice.txt");
	int nnn;
	inFile >> nnn;
	for (int ii = 0; ii < nnn; ++ii)
	{
		outFile << "Case #" << ii + 1 << ": ";
		long long F, D, B;
		inFile >> F >> D >> B;
		static vector<vector<long long>> Fdp(101, vector<long long>(101, 0));
		initialDP(D, B, Fdp);
		outFile << Fdp[B][D] << ' ';
		long long tmp1 = 1;
		while (Fdp[B][tmp1] < F) tmp1++;
		long long tmp2 = 1;
		while (Fdp[tmp2][D] < F) tmp2++;
		outFile << tmp1 << ' ' << tmp2 << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
