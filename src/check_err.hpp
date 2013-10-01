/****
 * check_err.hpp
 * Movement Exception Handling
 * by ghostshadow
 ****/

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
/*EOF: check_err.hpp*/
