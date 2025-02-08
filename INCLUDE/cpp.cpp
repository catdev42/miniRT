#ifndef CLASSNAME_HPP
#define CLASSNAME_HPP

// Uncomment if you need colors
/*
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
*/

#include <iostream>

class CLASSNAME
{
private:

protected:

public:
	CLASSNAME();
	CLASSNAME(CLASSNAME const &src);
	CLASSNAME &operator=(CLASSNAME const &rhs);
	~CLASSNAME();

	// Getters & Setters

	// Member functions
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, CLASSNAME const &infile);

#endif