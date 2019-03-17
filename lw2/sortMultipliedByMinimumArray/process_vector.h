#pragma once

#include "pch.h"

vector<double> ReadVector(istream& inputStream);
double GetMinValue(vector<double>& vec);
bool VectorScalarMultiplication(vector<double>& vec, double multiplier);
bool MultipliedByMinimum(vector<double>& vec);
void PrintVector(vector<double> vec);

vector<double> GetVectorScalarMultiplication(const vector<double>& vec, double multiplier);
vector<double> GetMultipliedByMinimum(const vector<double>& vec);
