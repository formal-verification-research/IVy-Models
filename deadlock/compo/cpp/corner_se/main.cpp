#include <iostream>
#include <string>

#include "Utils.hpp"
#include "Tests.hpp"

using namespace std; 

int main() 
{
	string name;
	cout << "Welcome. Input a name for this test: ";
	cin >> name;
	cout << "Testing will begin without further interaction." << endl;
	cout << "Expect a message once finished." << endl;

	runSafeTests(name);
	runUnsafeTests(name);
	cout << "Success. Check for results and traces named "<< name <<" for more info :)" << endl;

	return 0;
}