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

bool test(vector<vector<char>> table, int N, int K, char target)
{
	bool B = false, R = false;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (B == false && table[i][j] == target)
			{
				if (i <= N - K)
				{
					bool test = true;
					for (int k = 0; k < K; ++k)
					{
						if (table[i + k][j] != target) test = false;
					}
					if (test == true) B = true;
				}
				if (j <= N - K)
				{
					bool test = true;
					for (int k = 0; k < K; ++k)
					{
						if (table[i][j + k] != target) test = false;
					}
					if (test == true) B = true;
				}
				if (i <= N - K&&j <= N - K)
				{
					bool test = true;
					for (int k = 0; k < K; ++k)
					{
						if (table[i + k][j + k] != target) test = false;
					}
					if (test == true) B = true;
				}
				if (i <= N - K&&j >= K - 1)
				{
					bool test = true;
					for (int k = 0; k < K; ++k)
					{
						if (table[i + k][j - k] != target) test = false;
					}
					if (test == true) B = true;
				}
			}
		}
	}
	return B;
}

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
		int N, K;
		inFile >> N >> K;
		vector<vector<char>> table(N, vector<char>(N, '.'));
		vector<int> notdot(N, 0);
		queue<char> sc;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				inFile >> table[i][j];
				if (table[i][j] != '.')
				{
					notdot[i]++;
					sc.push(table[i][j]);
				}
			}
			if (notdot[i]>0)
			{
				for (int j = 0; j < N - notdot[i]; ++j)
				{
					table[i][j] = '.';
				}
				for (int j = N - notdot[i]; j < N; ++j)
				{
					table[i][j] = sc.front();
					sc.pop();
				}
			}
		}
		bool B = test(table, N, K, 'B');
		bool R = test(table, N, K, 'R');
		if (B&&R) outFile << "Both";
		else if (B) outFile << "Blue";
		else if (R) outFile << "Red";
		else outFile << "Neither";
		outFile << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}
