#include <iostream>

using namespace std;

int	main()
{
	std :: string hi = "HI THIS IS BRAIN";
	std :: string *stringPTR = &hi;
	std :: string &stringREF = hi;

	std :: cout << "string :	" << &hi << std :: endl;
	std :: cout << "stringPTR :	" << stringPTR << std :: endl;
	std :: cout << "stringREF :	" << &stringREF << std :: endl << std :: endl;

	std :: cout << "string value :		" << hi << std :: endl;
	std :: cout << "stringPTR value :	" << *stringPTR << std :: endl;
	std :: cout << "stringREF value :	" << stringREF << std :: endl;
}