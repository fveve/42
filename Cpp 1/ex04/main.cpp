#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

std :: string find_and_replace_line(std :: string line, const std :: string s1, const std :: string s2)
{
	int y = 0;

	if (!line.empty())
	{
		y = line.find(s1, y);
		while (y != std :: string::npos)
		{
			line.erase(y, s1.length());
			line.insert(y , s2);
			y = line.find(s1, y);
		}
	}
	return (line);
}

void	replace_file(std :: string file, std :: string s1, std :: string s2)
{
	std :: ofstream new_file(file + ".replace");
	std :: ifstream _file(file);
	std :: string line;

	while(std :: getline(_file, line))
	{
		new_file << find_and_replace_line(line, s1, s2);
	}
}

int main(int argc, char **argv)
{
	std :: string file;
	std :: string s1;
	std :: string s2;

	if (argc != 4)
	{
		std :: cout << "Wrong number of argument" << std :: endl;
		exit(0);
	}
	file = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (file.empty() | s1.empty() || s2.empty())
	{
		std :: cout << "Error, string problem" << std :: endl;
		exit(0);
	}
	replace_file(file, s1, s2);
}