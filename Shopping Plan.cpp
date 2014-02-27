#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct storestr
{
	int x;
	int y;
	int itemsmask;
	vector<int> price;
};

int num_items, num_stores, price_of_gas;
vector<string> items(num_items, "");
vector<bool> perish(num_items, false);
storestr *store = new storestr[num_stores];

double shoppingplan(int maskleft, int cur, int perish)
{
	int ans = INT_MAX;
	for (int i = 0; i < num_items; ++i)
	{
		if (maskleft & 1<<i)
		{
			for (int j = 0; j < num_stores; ++j)
			{
				if (store[j].price[i] != 0)
				{
					ans = shoppingplan(maskleft ^ 1<<j);
				}

			}

		}
	}
}

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("D-small-practice.in");
	outFile.open("D-small-practice.txt");
	int nnn;
	inFile >> nnn;
	inFile >> num_items >> num_stores >> price_of_gas;
	for (int i = 0; i < num_items;++i)
	{
		inFile >> items[i];
		if (items[i].find("!") != string::npos)
		{
			perish[i] = true;
			items[i] = items[i].substr(0, items[i].length() - 1);
		}
	}
	for (int j = 0; j < num_stores; ++j)
	{
		inFile >> store[j].x;
		inFile >> store[j].y;
		for (int ii = 0; ii < num_items; ++ii)
		{
			store[j].price.push_back(0);
		}
		string dummy;
		getline(inFile, dummy);
		istringstream iss (dummy);
		string tmp;
		store[j].itemsmask = 0;
		while (iss >> tmp)
		{
			int f = tmp.find(':');
			for (int ii = 0; ii < num_items; ++ii)
			{
				if (items[ii] == tmp.substr(0, f))
				{
					store[j].itemsmask |= 1 << ii;
					store[j].price[ii] = atoi(tmp.substr(f + 1).c_str());
				}
			}
		}
	}
	//finish reading
	

	inFile.close();
	outFile.close();
	return 0;
}
