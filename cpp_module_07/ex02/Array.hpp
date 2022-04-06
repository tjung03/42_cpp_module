#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <exception>

template <typename T>
class	Array
{
private:
	unsigned int	_n;
	T				*_arr;

public:
	Array(void) : _n(0), _arr(new T[0]) { }
	Array(const unsigned int n) : _n(n), _arr(new T[n]) { }

	Array(const Array &rhs) : _n(rhs.size()), _arr(new T[rhs.size()])
	{
		for (unsigned int i = 0; i < this->_n; i++)
			this->_arr[i] = rhs.getArrPtr()[i];
	}

	virtual ~Array(void)
	{
		delete []this->_arr;
	}

	Array&	operator=(const Array &rhs)
	{
		if (this != &rhs)
		{
			if (this->_arr)
				delete []this->_arr;
			this->_n = rhs.size();
			this->_arr = new T[this->_n];
			for (unsigned int i = 0; i < this->size(); i++)
				this->_arr[i] = rhs.getArrPtr()[i];
		}
		return (*this);
	}

	const T&	operator[](unsigned int idx) const
	{
		if (idx >= this->_n || idx < 0)
			throw (std::exception());
		return (this->_arr[idx]);
	}

	T&	operator[](unsigned int idx)
	{
		if (idx >= this->_n || idx < 0)
			throw (std::exception());
		return (this->_arr[idx]);
	}

	unsigned int	size(void) const
	{
		return (this->_n);
	}

	T*	getArrPtr(void) const
	{
		return (this->_arr);
	}
};

#endif
