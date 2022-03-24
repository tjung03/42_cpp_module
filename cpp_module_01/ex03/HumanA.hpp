#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
private:
	std::string	_name;
	Weapon		&_club;

public:
	HumanA(std::string name, Weapon &club);
	~HumanA(void);
	void	attack(void);
};

#endif
