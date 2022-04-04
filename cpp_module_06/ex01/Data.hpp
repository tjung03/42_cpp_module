#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class	Data
{
private:
	std::string	_str;
	int			_num;

public:
	Data(void);
	Data(const Data &rhs);
	virtual ~Data(void);

	Data&	operator=(const Data &rhs);

	uintptr_t	serialize(Data* ptr);
	Data*		deserialize(uintptr_t raw);

	void		setArguments(const std::string &str, const int num);
	std::string	getString(void) const;
	int			getInteger(void) const;
};

#endif
