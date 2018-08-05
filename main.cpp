#include <iostream>
#include "VersionControl/version_control.h"

int main(int argc, char const *argv[])
{
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Version " << VersionControl::GetVersion() << std::endl;
	return 0;
}