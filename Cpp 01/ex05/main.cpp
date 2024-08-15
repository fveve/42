#include "Harl.hpp"

int main ()
{
	Harl	harl;
	
	cout << "Printing all harl could say." << endl << endl;
	harl.complain("ERROR");
	cout << endl;
	harl.complain("WARNING");
	cout << endl;
	harl.complain("INFO");
	cout << endl;
	harl.complain("DEBUG");
	cout << endl;
	harl.complain("something else");
	cout << endl;
}