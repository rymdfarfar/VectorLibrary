#include "Test.h"
#include "Vector2.h"
#include "Vector3.h"
#include <string>
#include <iostream>

using namespace std;



Test::Test()
{
}


Test::~Test()
{
}

void Test::Testvector() {
	kina = vector2i(10, 10);
	vector3f kina3(10, 10, 10);
	vector2i kina2;
	
	cout << kina.x;
	cout << kina.y;
}

int Test:: main(int argc, char **argv)
{
	Testvector();
	
	return 0;
}
