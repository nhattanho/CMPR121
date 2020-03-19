#include "Greeting.h"
// Implementation file for display 12_5
namespace savitch1
{
	void greeting()
	{
		cout << "Hello from namespace savitch1.\n";
	}
}

namespace savitch2
{
	void greeting()
	{
		cout << "Greetings from namespace savitch2.\n";
	}
}

void bigGreeting()
{
	cout << "A Big Global Hello!\n";
}