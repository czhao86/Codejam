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
		int ny, nn;
		inFile >> ny >> nn;
		string tmp;
		getline(inFile, tmp);
		set<string> setstr;
		for (int i = 0; i < ny; ++i)
		{
			getline(inFile, tmp);
			setstr.insert(tmp);
		}
		int ans = 0;
		for (int j = 0; j < nn; ++j)
		{
			vector<string> vecstr;
			getline(inFile, tmp);
			for (int k = 0; k < tmp.length(); ++k)
			{
				if (tmp[k] == '/') tmp[k] = ' ';
			}
			istringstream iss(tmp);
			while (iss >> tmp)
			{
				vecstr.push_back(tmp);
			}
			string s = "";
			for (int j = 0; j < vecstr.size(); ++j)
			{
				s = s + '/' + vecstr[j];
				if (setstr.find(s) == setstr.end())
				{
					ans++;
					setstr.insert(s);
				}
			}
		}
		outFile << ans << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
