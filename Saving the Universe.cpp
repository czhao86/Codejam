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
  outFile.open("A-large-practice.out");
  int caseN;
  inFile>>caseN;
  for (int iii=0;iii<caseN;++iii)
    { 
      int engineN;
      inFile>>engineN;
      vector<string> engines(engineN,"");
      string tmp;
      getline(inFile,tmp);
      for (int i=0;i<engineN;++i)
	{
	  getline(inFile,engines[i]);
	}
      int queryN;
      inFile>>queryN;
      vector<string> queries(queryN,"");
      getline(inFile,tmp);
      for (int i=0;i<queryN;++i)
	{
	  getline(inFile,queries[i]);
	}
      long long mask=1<<engineN;
      mask--;
      long long querymask=0;
      int ans=0;
      for (int i=0;i<queryN;++i)
	{
	  int pos=-1;
	  for (int j=0;j<engineN;++j)
	    {
	      if (engines[j]==queries[i])
		{pos=j;break;}
	    }
	  if (pos==-1) continue;
	  querymask|=1<<pos;
	  if (querymask!=mask) continue;
	  else
	    {
	      ans++;
	      querymask=0;
	      i--;
	    }  
	}
      outFile<<"Case #"<<iii+1<<": "<<ans<<endl;
    }
  return 0;
}
