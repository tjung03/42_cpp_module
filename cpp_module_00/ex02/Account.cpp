#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
	: _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	std::cout<<"Called Account(void)"<<std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";amount:"<<_amount;
	std::cout<<";created"<<std::endl;
	++Account::_nbAccounts;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";amount:"<<_amount;
	std::cout<<";closed"<<std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		timestamp = time(NULL);
	struct tm	*timeinfo = localtime(&timestamp);
	char		buffer[16] = {};

	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
	std::cout<<"["<<buffer<<"] ";
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts();
	std::cout<<";total:"<<getTotalAmount();
	std::cout<<";deposits:"<<getNbDeposits();
	std::cout<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}

void	Account::makeDeposit(int deposit)
{
	if (deposit > 0)
	{
		_displayTimestamp();
		std::cout<<"index:"<<_accountIndex;
		std::cout<<";p_amount:"<<_amount;
		_amount += deposit;
		std::cout<<";deposit:"<<deposit;
		std::cout<<";amount:"<<_amount;
		Account::_totalAmount += deposit;
		++_nbDeposits;
		std::cout<<";nb_deposits:"<<_nbDeposits<<std::endl;
		++Account::_totalNbDeposits;
	}
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	temp;

	temp = _amount;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";p_amount:"<<_amount;
	_amount = temp - withdrawal;
	if (!checkAmount())
	{
		_amount = temp;
		std::cout<<";withdrawal:refused"<<std::endl;
		return (false);
	}
	std::cout<<";withdrawal:"<<withdrawal;
	std::cout<<";amount:"<<_amount;
	Account::_totalAmount -= withdrawal;
	++_nbWithdrawals;
	std::cout<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
	++Account::_totalNbWithdrawals;
	return (true);
}

int		Account::checkAmount(void) const
{
	if (_amount < 0)
		return (0);
	return (1);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";amount:"<<_amount;
	std::cout<<";deposits:"<<_nbDeposits;
	std::cout<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}
