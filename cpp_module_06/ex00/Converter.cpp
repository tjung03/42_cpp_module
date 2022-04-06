#include "Converter.hpp"

Converter::Converter(void)
	: _target("converter"), _cvalue(0), _ivalue(0), _fvalue(0.0f), _dvalue(0.0), _vflag(0), _sflag(0)
{
	this->setDecimalPlace(0);
}

Converter::Converter(const std::string &val)
	: _target(val), _cvalue(0), _ivalue(0), _fvalue(0.0f), _dvalue(0.0), _vflag(0), _sflag(0)
{
	this->setDecimalPlace(0);
	this->storeConversionValues();
	this->printValueType();
}

Converter::Converter(const Converter &rhs)
	:	_target(rhs.getTarget()), _cvalue(rhs.getCharValue()), _ivalue(rhs.getIntegerValue()), \
		_fvalue(rhs.getFloatValue()), _dvalue(rhs.getDoubleValue()), \
		_vflag(rhs.getValueFlag()), _sflag(rhs.getStringFlag())
{
	this->setDecimalPlace(rhs.getDecimalPlace());
}

Converter::~Converter(void)
{ }

Converter&	Converter::operator=(const Converter &rhs)
{
	if (this != &rhs)
	{
		this->setTarget(rhs.getTarget());
		this->setCharValue(rhs.getCharValue());
		this->setIntegerValue(rhs.getIntegerValue());
		this->setFloatValue(rhs.getFloatValue());
		this->setDoubleValue(rhs.getDoubleValue());
		this->setValueFlag(rhs.getValueFlag());
		this->setStringFlag(rhs.getStringFlag());
		this->setDecimalPlace(rhs.getDecimalPlace());
	}
	return (*this);
}

std::string	Converter::getTarget(void) const
{
	return (this->_target);
}

void	Converter::setTarget(const std::string &target)
{
	const_cast<std::string&>(this->_target) = target;
}

bool	Converter::checkValidValue(const std::string &target)
{
	int dot_cnt = 0;
	int	flt_cnt = 0;
	int	length = target.length();
	int	check = 0;

	for (int i = 0; i < length; i++)
	{
		if (!check && (length > 1) && (target[0] == '+' || target[0] == '-'))
		{
			for (int j = 1; j < length; j++)
			{
				if (target[j] < 48 || target[j] > 57)
				{
					if (target[j] == '.' || target[j] == 'f')
						continue ;
					return (false);
				}
			}
			check = 1;
		}
		else if (target[i] < 48 || target[i] > 57)
		{
			if (target[i] == '.' || target[i] == 'f')
			{
				if (target[i] == '.')
					dot_cnt++;
				else if (target[i] == 'f')
					flt_cnt++;
				continue ;
			}
			return (false);
		}
		else if (dot_cnt == 1)
			++(this->_decimal_place);
	}
	if (dot_cnt == 0 || target[length - 1] == '.')
		++(this->_decimal_place);
	if (length == 1 && (target[0] == '+' || target[0] == '-'))

	if (dot_cnt > 1 || flt_cnt > 1)
		return (false);
	if (this->_target.find('f') != std::string::npos && this->_target[this->_target.length() - 1] != 'f')
		return (false);
	if (this->_target[0] == '.')
		throw (Converter::NoDotFirstException());
	return (true);
}

void	Converter::setRangeFlag(const std::string &target)
{
	const char	*ch;
	int			num;

	try {
		ch = target.c_str();
		num = atoi(ch);
		if (num < 0 || num > 127)
			this->_vflag |= CHAR_RANGE_FLAG;
		num = std::stoi(target);
	}
	catch (const std::out_of_range &e) {
		this->_vflag |= INT_RANGE_FLAG;
		try {
			std::stof(target);
		}
		catch (const std::out_of_range &e) {
			this->_vflag |= FLOAT_RANGE_FLAG;
			try {
				std::stod(target);
			}
			catch (const std::out_of_range &e) {
				this->_vflag |= DOUBLE_RANGE_FLAG;
			}
		}
	}
}

bool	Converter::noSingleQuotesChar(void)
{
	if (this->_target.length() == 1 && (this->_target[0] < 48 || this->_target[0] > 57))
		return (true);
	return (false);
}

void	Converter::storeConversionValues(void)
{
	if (this->_target.length() == 3 && this->_target[0] == '\'' && this->_target[2] == '\'')
	{
		this->_cvalue = this->_target[1];
		this->_ivalue = static_cast<int>(this->_cvalue);
		this->_fvalue = static_cast<float>(this->_cvalue);
		this->_dvalue = static_cast<double>(this->_cvalue);
		this->setDecimalPlace(1);
	}
	else if (noSingleQuotesChar())
	{
		this->_cvalue = this->_target[0];
		this->_ivalue = static_cast<int>(this->_cvalue);
		this->_fvalue = static_cast<float>(this->_cvalue);
		this->_dvalue = static_cast<double>(this->_cvalue);
		this->setDecimalPlace(1);
	}
	else if (checkValidValue(this->_target))
	{
		setRangeFlag(this->_target);
		if (this->_target.find('.') == std::string::npos)
		{
			if ((this->_vflag & INT_RANGE_FLAG) != INT_RANGE_FLAG)
			{
				this->_ivalue = std::stoi(this->_target);
				if ((this->_vflag & CHAR_RANGE_FLAG) != CHAR_RANGE_FLAG)
					this->_cvalue = static_cast<char>(this->_ivalue);
			}
			if ((this->_vflag & FLOAT_RANGE_FLAG) != FLOAT_RANGE_FLAG)
				this->_fvalue = std::stof(this->_target);
			if ((this->_vflag & DOUBLE_RANGE_FLAG) != DOUBLE_RANGE_FLAG)
				this->_dvalue = std::stod(this->_target);
		}
		else if (this->_target.find('f') != std::string::npos)
		{
			if ((this->_vflag & FLOAT_RANGE_FLAG) != FLOAT_RANGE_FLAG)
			{
				this->_fvalue = std::stof(this->_target);
				if ((this->_vflag & CHAR_RANGE_FLAG) != CHAR_RANGE_FLAG)
					this->_cvalue = static_cast<char>(this->_fvalue);
				if ((this->_vflag & INT_RANGE_FLAG) != INT_RANGE_FLAG)
					this->_ivalue = static_cast<int>(this->_fvalue);
			}
			if ((this->_vflag & DOUBLE_RANGE_FLAG) != DOUBLE_RANGE_FLAG)
				this->_dvalue = std::stod(this->_target);
		}
		else if (this->_target.find('.') != std::string::npos)
		{
			if ((this->_vflag & DOUBLE_RANGE_FLAG) != DOUBLE_RANGE_FLAG)
			{
				this->_dvalue = std::stod(this->_target);
				if ((this->_vflag & CHAR_RANGE_FLAG) != CHAR_RANGE_FLAG)
					this->_cvalue = static_cast<char>(this->_dvalue);
				if ((this->_vflag & INT_RANGE_FLAG) != INT_RANGE_FLAG)
					this->_ivalue = static_cast<int>(this->_dvalue);
				if ((this->_vflag & FLOAT_RANGE_FLAG) != FLOAT_RANGE_FLAG)
					this->_fvalue = static_cast<float>(this->_dvalue);
			}
		}
	}
	else
	{
		if (this->_target == KNAN || this->_target == KNANF)
			this->_sflag |= NAN_FLAG;
		else if (this->_target == KINF || this->_target == KPINF || this->_target == KINFF || this->_target == KPINFF)
			this->_sflag |= INF_FLAG;
		else if (this->_target == KMINF || this->_target == KMINFF)
			this->_sflag |= MINF_FLAG;
		else
			throw (Converter::InputException());
	}
}

void	Converter::printValueType(void) const
{
	std::cout<<"char: ";
	if (((this->_vflag & CHAR_RANGE_FLAG) == CHAR_RANGE_FLAG) || this->_sflag)
		std::cout<<"impossible"<<std::endl;
	else
	{
		if (this->_ivalue < 32 || this->_ivalue > 126)
			std::cout<<"Non displayable"<<std::endl;
		else
			std::cout<<"\'"<<this->getCharValue()<<"\'"<<std::endl;
	}
	std::cout<<"int: ";
	if (((this->_vflag & INT_RANGE_FLAG) == INT_RANGE_FLAG) || this->_sflag)
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<this->getIntegerValue()<<std::endl;
	std::cout<<"float: ";
	if (((this->_vflag & FLOAT_RANGE_FLAG) == FLOAT_RANGE_FLAG))
		std::cout<<"impossible"<<std::endl;
	else if (this->_sflag == 1)
		std::cout<<KNANF<<std::endl;
	else if (this->_sflag == 2)
		std::cout<<KINFF<<std::endl;
	else if (this->_sflag == 4)
		std::cout<<KMINFF<<std::endl;
	else if (this->getFloatValue() == 0)
		std::cout<<"0.0f"<<std::endl;
	else
		std::cout<<std::fixed<<std::setprecision(this->_decimal_place)<<this->getFloatValue()<<"f"<<std::endl;
	std::cout<<"double: ";
	if (((this->_vflag & DOUBLE_RANGE_FLAG) == DOUBLE_RANGE_FLAG))
		std::cout<<"impossible"<<std::endl;
	else if (this->_sflag == 1)
		std::cout<<KNAN<<std::endl;
	else if (this->_sflag == 2)
		std::cout<<KINF<<std::endl;
	else if (this->_sflag == 4)
		std::cout<<KMINF<<std::endl;
	else if (this->getDoubleValue() == 0)
		std::cout<<"0.0"<<std::endl;
	else
		std::cout<<std::fixed<<std::setprecision(this->_decimal_place)<<this->getDoubleValue()<<std::endl;
}

char	Converter::getCharValue(void) const
{
	return (this->_cvalue);
}

int		Converter::getIntegerValue(void) const
{
	return (this->_ivalue);
}

float	Converter::getFloatValue(void) const
{
	return (this->_fvalue);
}

double	Converter::getDoubleValue(void) const
{
	return (this->_dvalue);
}

int		Converter::getValueFlag(void) const
{
	return (this->_vflag);
}

int		Converter::getStringFlag(void) const
{
	return (this->_sflag);
}

int		Converter::getDecimalPlace(void) const
{
	return (this->_decimal_place);
}

void	Converter::setCharValue(const char char_)
{
	this->_cvalue = char_;
}

void	Converter::setIntegerValue(const int int_)
{
	this->_ivalue = int_;
}

void	Converter::setFloatValue(const float float_)
{
	this->_fvalue = float_;
}

void	Converter::setDoubleValue(const double double_)
{
	this->_dvalue = double_;
}

void	Converter::setValueFlag(const int int_)
{
	this->_vflag = int_;
}

void	Converter::setStringFlag(const int int_)
{
	this->_sflag = int_;
}

void	Converter::setDecimalPlace(const int int_)
{
	this->_decimal_place = int_;
}
