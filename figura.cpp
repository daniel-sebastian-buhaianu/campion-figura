#include <fstream>
using namespace std;
struct Punct { int x, y; };
int main()
{
	ifstream f("figura.in");
	int D, N;
	f >> D >> N;
	int a[D+2][D+2];
	for (int i = 0; i <= D+1; i++)
		for (int j = 0; j <= D+1; j++)
			a[i][j] = 0;
	for (int i = 0; i <= D+1; i++)
	{
		a[0][i] = a[D+1][i] = -1;
		a[i][0] = a[i][D+1] = -1;
	}
	Punct v[N];
	for (int i = 0; i < N; i++)
	{
		int lin, col;
		f >> lin >> col;
		v[i].x = lin;
		v[i].y = col;
		a[lin][col] = 1;
	}
	f.close();
	int p = 4*N;
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	for (int i = 0; i < N; i++)
	{
		a[v[i].x][v[i].y] = -1;
		for (int d = 0; d < 4; d++)
		{
			int lin = v[i].x + dx[d];
			int col = v[i].y + dy[d];
			if (a[lin][col] == 1)
				p -= 2;
		}
	}
	ofstream g("figura.out");
	g << p;
	g.close();
	return 0;
}

