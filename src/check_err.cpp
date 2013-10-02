/****
 * check_err.cpp
 * Error Implementation
 * by ghostshadow
 ****/

#include "check_err.hpp"

Checker::Turn_Error::Turn_Error(const char *errcode) noexcept {
	this->errorcode=errcode;
}

const char *Checker::Turn_Error::what() const noexcept {
	return this->errorcode;
}

Checker::Turn_Error::~Turn_Error() noexcept {}


