#pragma once
#include "pch.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

COLORREF hexToRGBColorRef(string hex) {

	if (hex.at(0) == '#') {
		hex.erase(0, 1);
	}

	while (hex.length() != 6) {
		hex += "0";
	}

	std::vector<string> colori = SplitWithCharacters(hex, 2);

	BYTE r = stoi(colori[0], nullptr, 16);
	BYTE g = stoi(colori[1], nullptr, 16);
	BYTE b = stoi(colori[2], nullptr, 16);

	return (RGB(r, g, b)) & 0xFFFFFFFF;
}

COLORREF hexToRGBAColorRef(string hex) {

	if (hex.at(0) == '#') {
		hex.erase(0, 1);
	}

	while (hex.length() != 8) {
		hex += "0";
	}

	std::vector<string> colori = SplitWithCharacters(hex, 2);
	
	BYTE a = stoi(colori[0], nullptr, 16);
	BYTE r = stoi(colori[1], nullptr, 16);
	BYTE g = stoi(colori[2], nullptr, 16);
	BYTE b = stoi(colori[3], nullptr, 16);

	return (RGBA(r, g, b, a)) & 0xFFFFFFFF;
}