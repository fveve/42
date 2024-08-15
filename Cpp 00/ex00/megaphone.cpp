#include <iostream>

using namespace std;

int	main(int argc, char **argv)
{
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int y = 1; y < argc; y++)
		for (int x = 0; argv[y][x]; x++)
		{
			cout << (char)toupper(argv[y][x]);
		}
		cout << '\n';
	}
}