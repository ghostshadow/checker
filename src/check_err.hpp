/****
 * check_err.hpp
 * Movement Exception Handling
 * by ghostshadow
 ****/

#ifndef CHECK_ERR_INCL__
#define CHECK_ERR_INCL__

#include "std_incl.hpp"

namespace Checker {
class Turn_Error :public std::exception {
private:
	const char *errorcode;
public:
	Turn_Error(const char *) noexcept;
	~Turn_Error() noexcept;
	const char *what() const noexcept;
};
}

#endif /*CHECK_ERR_INCL__*/
/*EOF: check_err.hpp*/
