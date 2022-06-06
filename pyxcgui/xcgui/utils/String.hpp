#pragma once
#include "pch.h"
#include <string>
#include <cstdarg>
#include <vector>
#include <iostream>


std::vector<std::string> SplitWithCharacters(const std::string& str, int splitLength) {
	int NumSubstrings = str.length() / splitLength;
	std::vector<std::string> ret;

	for (int i = 0; i < NumSubstrings; i++) {
		ret.push_back(str.substr(i * splitLength, splitLength));
	}

	// If there are leftover characters, create a shorter item at the end.
	if (str.length() % splitLength != 0) {
		ret.push_back(str.substr(splitLength * NumSubstrings));
	}
	return ret;
}

// requires at least C++11
const std::string vformat(const char* const zcFormat, ...) {

	// initialize use of the variable argument array
	va_list vaArgs;
	va_start(vaArgs, zcFormat);

	// reliably acquire the size
	// from a copy of the variable argument array
	// and a functionally reliable call to mock the formatting
	va_list vaArgsCopy;
	va_copy(vaArgsCopy, vaArgs);
	const int iLen = std::vsnprintf(NULL, 0, zcFormat, vaArgsCopy);
	va_end(vaArgsCopy);

	// return a formatted string without risking memory mismanagement
	// and without assuming any compiler or platform specific behavior
	std::vector<char> zc(iLen + 1);
	std::vsnprintf(zc.data(), zc.size(), zcFormat, vaArgs);
	va_end(vaArgs);
	return std::string(zc.data(), iLen);
}