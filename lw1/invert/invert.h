#pragma once

#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

enum class Status
{
	Ok,
	WrongArgumentCount,
	InvalidInputFile,
	WrongInputData,
	CanNotInvertMatrix
};
