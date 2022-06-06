#pragma once
#include "pch.h"
#include <vector>
#include "String.hpp"

COLORREF hexToRGBColorRef(std::string hex) {

	if (hex.at(0) == '#') {
		hex.erase(0, 1);
	}

	while (hex.length() != 6) {
		hex += "0";
	}

	std::vector<std::string> colori = SplitWithCharacters(hex, 2);

	BYTE r = stoi(colori[0], nullptr, 16);
	BYTE g = stoi(colori[1], nullptr, 16);
	BYTE b = stoi(colori[2], nullptr, 16);

	return (RGB(r, g, b)) & 0xFFFFFFFF;
}

COLORREF hexToRGBAColorRef(std::string hex) {

	if (hex.at(0) == '#') {
		hex.erase(0, 1);
	}

	while (hex.length() != 8) {
		hex += "0";
	}

	std::vector<std::string> colori = SplitWithCharacters(hex, 2);
	
	BYTE a = stoi(colori[0], nullptr, 16);
	BYTE r = stoi(colori[1], nullptr, 16);
	BYTE g = stoi(colori[2], nullptr, 16);
	BYTE b = stoi(colori[3], nullptr, 16);

	return (RGBA(r, g, b, a)) & 0xFFFFFFFF;
}