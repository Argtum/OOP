#pragma once

enum class Status
{
	Ok,
	WrongArgumentCount,
	InvalidInputFile,
	WrongInputData,
	CanNotInvertMatrix
};

void printError(Status error);
