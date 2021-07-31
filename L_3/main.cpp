#include "duplicates.h"
#include<iostream>
#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include"time.h"

int main(int argc, char** argv)
{

	int result = Catch::Session().run(argc, argv);

	for (int i = 1; i < 8; i++)
	{
		measure(pow(10, i));
	}
}