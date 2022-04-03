#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cmath>
# include <cstdlib>
# include <iomanip>

# define CHAR_RANGE_FLAG (1 << 0)
# define INT_RANGE_FLAG (1 << 1)
# define FLOAT_RANGE_FLAG (1 << 2)
# define DOUBLE_RANGE_FLAG (1 << 3)
# define OUT_RANGE_FLAG (1 << 4)

# define NAN_FLAG (1 << 0)
# define INF_FLAG (1 << 1)
# define MINF_FLAG (1 << 2)

# define KNAN "nan"
# define KINF "inf"
# define KPINF "+inf"
# define KMINF "-inf"
# define KNANF "nanf"
# define KINFF "inff"
# define KPINFF "+inff"
# define KMINFF "-inff"

class	Converter
{
private:
	const std::string	_target;
	char				_cvalue;
	int					_ivalue;
	float				_fvalue;
	double				_dvalue;
	int					_vflag;
	int					_sflag;
	int					_decimal_place;

	Converter(void);

	std::string	getTarget(void) const;
	void		setTarget(const std::string &target);

	void	setCharValue(const char char_);
	void	setIntegerValue(const int int_);
	void	setFloatValue(const float float_);
	void	setDoubleValue(const double double_);
	void	setValueFlag(const int int_);
	void	setStringFlag(const int int_);
	void	setDecimalPlace(const int int_);

	bool	checkValidValue(const std::string &target);
	void	setRangeFlag(const std::string &target);
	bool	noSingleQuotesChar(void);

	void	storeConversionValues(void);
	void	printValueType(void) const;

public:
	explicit Converter(const std::string &val);
	Converter(const Converter &rhs);
	virtual ~Converter(void);

	Converter&	operator=(const Converter &rhs);

	char	getCharValue(void) const;
	int		getIntegerValue(void) const;
	float	getFloatValue(void) const;
	double	getDoubleValue(void) const;
	int		getValueFlag(void) const;
	int		getStringFlag(void) const;
	int		getDecimalPlace(void) const;

	class	InputException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

	class	NoDotFirstException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

#endif
