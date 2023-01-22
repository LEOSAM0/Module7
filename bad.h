#pragma once
#include <exception>

class bad_range : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Invalid number of elements";
	}
};

class bad_length : public std::exception {
public:
	virtual const char* what() const noexcept override {
		return "Number of elemetns is out if control";
	}
};