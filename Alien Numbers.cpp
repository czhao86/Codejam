#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("A-large-practice.in");
	outFile.open("A-large-practice.txt");
	int n;
	inFile >> n;
	for (int i = 0; i < n; ++i)
	{
		string str, sl, tl;
		inFile >> str;
		inFile >> sl;
		inFile >> tl;
		int sln = sl.length();
		int tln = tl.length();
		map<char, int> m1;
		map<int, char> m2;
		for (int i = 0; i < sln; ++i)
		{
			m1[sl[i]] = i;
		}
		int decx = 0;
		for (int i = 0; i < str.length(); ++i)
		{
			decx += m1[str[i]] * pow(sln, (str.length() - i - 1));
		}
		for (int i = 0; i < tln; ++i)
		{
			m2[i] = tl[i];
		}
		string ans = "";
		int s = 0;
		while (decx>0)
		{
			ans = m2[decx%tln]+ans;
			decx = decx / tln;
			s++;
		}
		outFile << "Case #" << i + 1 << ": " << ans << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}
