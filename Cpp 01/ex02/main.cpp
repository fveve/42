#include <iostream>

using namespace std;

int	main()
{
	 string hi = "HI THIS IS BRAIN";
	 string *stringPTR = &hi;
	 string &stringREF = hi;

	 cout << "string :	" << &hi <<  endl;
	 cout << "stringPTR :	" << stringPTR <<  endl;
	 cout << "stringREF :	" << &stringREF <<  endl <<  endl;

	 cout << "string value :		" << hi <<  endl;
	 cout << "stringPTR value :	" << *stringPTR <<  endl;
	 cout << "stringREF value :	" << stringREF <<  endl;
}