#pragma once

#include "pch.h"

vector<double> ReadVector(istream& inputStream);
double GetMinValue(vector<double>& vec);
void VectorScalarMultiplication(vector<double>& vec, double multiplier);
void ProcessVector(vector<double>& vec);
void PrintVector(vector<double> vec);

vector<double> GetVectorScalarMultiplication(const vector<double>& vec, double multiplier);
vector<double> GetProcessVector(const vector<double>& vec);
