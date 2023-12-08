#include <fstream>
using namespace std;
int main()
{
	ifstream f("figura.in");
	int D, N, imin, imax, jmin, jmax;
	f >> D >> N;
	imin = jmin = D;
	imax = jmax = 1;
	while (N > 0)
	{
		int i, j;
		f >> i >> j;
		if (i < imin) imin = i;
		if (i > imax) imax = i;
		if (j < jmin) jmin = j;
		if (j > jmax) jmax = j;
		N--;
	}
	f.close();
	int L = jmax-jmin+1;
	int l = imax-imin+1;
	ofstream g("figura.out");
	g << 2*(L+l);
	g.close();
	return 0;
}

