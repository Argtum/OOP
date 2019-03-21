#pragma once

#include "pch.h"

bool ReadVector(istream& inputStream, vector<double>& vec);
double GetMinValue(vector<double>& vec);
void VectorScalarMultiplication(vector<double>& vec, double multiplier);
bool MultipliedByMinimum(vector<double>& vec);
void PrintVector(vector<double> vec);

vector<double> GetReadVector(istream& inputStream, vector<double>& vec);
vector<double> GetVectorScalarMultiplication(const vector<double>& vec, double multiplier);
vector<double> GetMultipliedByMinimum(const vector<double>& vec);
