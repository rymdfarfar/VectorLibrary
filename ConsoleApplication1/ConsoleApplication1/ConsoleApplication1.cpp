// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector2.h"
#include "Vector3.h"
#include <string>
#include <iostream>

using namespace std;


int main()
{
	/*int fem = 5;
	cout << fem;*/
	vector2i kina2(10, 10);
	vector2f kina2f(11.2, 12.2);
	vector3f kina3f(11.1, 11.1, 11.1);


	//cout << kina2.x , cout << kina2.y;
	//cout << kina2f.x, cout << kina2f.y;
	kina3f.normalize();
	cout << kina3f.x, kina3f.y, kina3f.z;
	std::cout << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}

