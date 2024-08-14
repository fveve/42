#include <iostream>
#include <string>

using namespace std;

string to_upper(string str)
{
	for (int x = 0; str[x]; x++)
	{
		if (str[x] >= 97 && str[x] <= 122)
			str[x] -= 32;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int x = 1; x < argc; x++)
		{
			cout << to_upper((string)argv[x]);
		}
		cout << '\n';
	}
}