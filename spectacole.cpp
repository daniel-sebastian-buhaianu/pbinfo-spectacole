#include <fstream>
#include <algorithm>

#define NMAX 100

using namespace std;

ifstream fin("spectacole.in");
ofstream fout("spectacole.out");

struct Spectacol
{
	int x, y;
};

bool crescator_y(Spectacol a, Spectacol b)
{
	return a.y < b.y;
}

int main()
{
	int n, i, nr, ultim;
	Spectacol s[NMAX];

	fin >> n;

	for (i = 0; i < n; i++)
	{
		fin >> s[i].x >> s[i].y;
	}

	fin.close();

	// sortez spectacolele crescator dupa Y
	sort(s, s+n, crescator_y);

	// aleg primul spectacol
	nr = 1, ultim = 0;

	for (i = 1; i < n; i++)
	{
		if (s[i].x >= s[ultim].y)
		{
			nr++;
			ultim = i;
		}
	}

	fout << nr;

	fout.close();

	return 0;
}
// scor 100
