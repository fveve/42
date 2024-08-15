#include "Harl.hpp"

void Harl :: debug( void )
{
	 cout << "[DEBUG]" <<  endl;
	 cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" <<  endl;
}

void Harl :: info( void )
{
	 cout << "[INFO]" <<  endl;
	 cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<  endl;
}

void Harl :: warning( void )
{
	 cout << "[WARNING]" <<  endl;
	 cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<  endl;
}

void Harl :: error( void )
{
	 cout << "[ERROR]" <<  endl;
	 cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void Harl :: complain( string level )
{
	int _case = (!(level.compare("DEBUG"))) ? 0 : ((!(level.compare("INFO"))) ? 1 : ((!(level.compare("WARNING"))) ? 2 : ((!(level.compare("ERROR")) ? 3 : 4))));

	switch (_case)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
		{
			error();
			break;
		}
		case 4 :
		{
			 cout << "[Probably complaining about insignificant problems]" <<  endl;
			break;
		}
	};
}