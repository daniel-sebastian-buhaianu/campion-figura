#include <fstream>
using namespace std;
int main()
{
	ifstream f("figura.in");
	int D, N;
	f >> D >> N;
	int a[D+1][D+1];
	for (int i = 0; i <= D; i++)
		for (int j = 0; j <= D; j++)
			a[i][j] = 0;
	while (N > 0)
	{
		int i, j;
		f >> i >> j;
		a[i][j] = 1;
		N--;
	}
	f.close();
	int lgmax = 0;
	for (int i = 1; i <= D; i++)
	{
		int lg = 0;
		for (int j = 1; j <= D; j++)
			if (a[i][j]) lg++;
		if (lg > lgmax) lgmax = lg;
	}
	int latmax = 0;
	for (int j = 1; j <= D; j++)
	{
		int lat = 0;
		for (int i = 1; i <= D; i++)
			if (a[i][j]) lat++;
		if (lat > latmax) latmax = lat;
	}
	ofstream g("figura.out");
	g << 2*(latmax + lgmax);
	g.close();
	return 0;
}

