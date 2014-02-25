#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("A-large-practice.in");
	outFile.open("A-large-practice.txt");
	int nnn;
	inFile >> nnn;
	for (int i = 0; i < nnn; ++i)
	{
		outFile << "Case #" << i + 1 << ": ";
		int x1, x2, x3, y1, y2, y3;
		inFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		int l1 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		int l2 = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);
		int l3 = (x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1);
		int m1, m2, m3;
		m1 = min(min(l1, l2), l3);
		m3 = max(max(l1, l2), l3);
		m2 = l1 + l2 + l3 - m1 - m3;
		l1 = m1, l2 = m2, l3 = m3;
		if ((x1 == x2) && (x2 == x3) || (y2 - y1)*(x3 - x1) == (y3 - y1) * (x2 - x1))
		{
			outFile << "not a triangle" << endl;
			continue;
		}
		bool same = false, right = false, obtuse = false;
		if (l1 == l2 || l1 == l3 || l2 == l3) same = true;
		if (l1 + l2 == l3) right = true;
		if (l1 + l2 < l3) obtuse = true;
		if (same) outFile << "isosceles ";
		else outFile << "scalene ";
		if (right) outFile << "right ";
		else if (obtuse) outFile << "obtuse ";
		else outFile << "acute ";
		outFile << "triangle" << endl;

	}
	inFile.close();
	outFile.close();
	return 0;
}
