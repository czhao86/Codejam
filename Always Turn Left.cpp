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
	inFile.open("B-large-practice.in");
	outFile.open("B-large-practice.txt");
	int nnn;
	inFile >> nnn;
	for (int iii = 0; iii < nnn; ++iii)
	{
		outFile << "Case #" << iii + 1 << ':' << endl;
		string s, t;
		inFile >> s >> t;
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		int d = 0, i = 0, j = 0;
		vector<pair<int, int>> posvec;
		vector<int> dvec;
		for (int sl = 0; sl < s.length(); ++sl)
		{
			if (s[sl] == 'W')
			{
				posvec.push_back(make_pair(i, j));
				dvec.push_back(d);
				i += dx[d], j += dy[d];
			}
			else if (s[sl] == 'L')
			{
				d = (d + 1) % 4;
			}
			else if (s[sl] == 'R')
			{
				d = (d + 3) % 4;
			}
		}
		int ex = i, ey = j;
		d = (d + 2) % 4;
		for (int tl = 0; tl < t.length(); ++tl)
		{
			if (t[tl] == 'W')
			{
				posvec.push_back(make_pair(i, j));
				dvec.push_back(d);
				i += dx[d], j += dy[d];
			}
			else if (t[tl] == 'L')
			{
				d = (d + 1) % 4;
			}
			else if (t[tl] == 'R')
			{
				d = (d + 3) % 4;
			}
		}
		map<pair<int, int>, int> MM;
		int ymax = INT_MIN, xmin = INT_MAX, xmax = INT_MIN;
		for (int i = 0; i < posvec.size(); ++i)
		{
			if ((posvec[i].first != 0 || posvec[i].second != 0) && (posvec[i].first != ex || posvec[i].second != ey))
			{
				if (MM.count(posvec[i]) == 0) MM[posvec[i]] = 0;
				int xx = posvec[i].first;
				int yy = posvec[i].second;
				int dd = dvec[i];
				int tmp;
				if (dd == 0) tmp = 1;
				if (dd == 1) tmp = 3;
				if (dd == 2) tmp = 0;
				if (dd == 3) tmp = 2;
				MM[posvec[i]] |= 1 << tmp;
				if (xmin > xx) xmin = xx;
				if (xmax < xx) xmax = xx;
				if (ymax < yy) ymax = yy;
			}
		}
		for (int j = 1; j <= ymax; ++j)
		{
			for (int i = xmin; i <= xmax; ++i)
			{
				int dum = MM[make_pair(i, j)];
				char dummy = (dum - 10) + 'a';
				if (dum < 10) outFile << dum;
				else outFile << dummy;
			}
			outFile << endl;
		}
	}
	inFile.close();
	outFile.close();
	return 0;
}
