#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

 string find_and_replace_line( string line, const  string s1, const  string s2)
{
	int y = 0;

	if (!line.empty())
	{
		y = line.find(s1, y);
		while (y !=  string::npos)
		{
			line.erase(y, s1.length());
			line.insert(y , s2);
			y = line.find(s1, y);
		}
	}
	return (line);
}

void	replace_file( string file,  string s1,  string s2)
{
	 ofstream new_file(file + ".replace");
	 ifstream _file(file);
	 string line;

	while( getline(_file, line))
	{
		new_file << find_and_replace_line(line, s1, s2);
	}
}

int main(int argc, char **argv)
{
	 string file;
	 string s1;
	 string s2;

	if (argc != 4)
	{
		 cout << "Wrong number of argument" <<  endl;
		exit(0);
	}
	file = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (file.empty() | s1.empty() || s2.empty())
	{
		 cout << "Error, string problem" <<  endl;
		exit(0);
	}
	replace_file(file, s1, s2);
}