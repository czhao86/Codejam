#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("B-large-practice.in");
	outFile.open("B-large-practice.out");
	int nnn;
	inFile >> nnn;
	string tmp;
	getline(inFile, tmp);
	for (int iii = 0; iii < nnn; ++iii)
	{
		outFile << "Case #" << iii + 1 << ": ";
		getline(inFile, tmp);
		stack<string> ans;
		int prev = 0;
		for (int i = 0; i < tmp.length(); ++i)
		{
			if (tmp[i] != ' ') continue;
			else
			{
				ans.push(tmp.substr(prev, i - prev));
				prev = i + 1;
			}
		}
		ans.push(tmp.substr(prev, tmp.length() - prev));
		string res = "";
		while (!ans.empty())
		{
			res = res + ans.top() + ' ';
			ans.pop();
		}
		res = res.substr(0, res.length() - 1);
		outFile << res << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
