#include <ctime>
#include <iostream>
#include "Account.hpp"

int				Account::_totalNbWithdrawals = 0;
int				Account::_totalNbDeposits = 0;
int				Account::_totalAmount = 0;
int				Account::_nbAccounts = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	// [timestamp] accounts:_nbAccount;total:_totalAmount;deposits:_totalNbDeposits;withdrawals:_totalNbWithdrawals
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	// [timestamp] index:_accountIndex;amount:_amount;created
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	// [timestamp] index:_accountIndex;amount:_amount;closed
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int				p_amount;

	p_amount = checkAmount();
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	// [timestamp] index:_accountIndex;p_amount:p_amount;deposit:deposit;amount:_amount;nb_deposits:_nbDeposits
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int				p_amount;

	p_amount = checkAmount();
	if (p_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;

		// [timestamp] index:_accountIndex;p_amount:_amount;withdrawal:withdrawal;amount:_amount;nb_withdrawals:_nbWithdrawals
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << p_amount << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		// [timestamp] index:_accountIndex;p_amount:_amount;withdrawal:refused
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << p_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	// [timestamp] index:_accountIndex;amount:_amount;deposits:_nbDeposits;withdrawals:nbWithdrawals
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

#include <iomanip>
void	Account::_displayTimestamp( void )
{
	std::time_t				now;
	std::tm					*tm;

	now = std::time(nullptr);
	tm = localtime(&now);
	std::cout << "[" << std::setprecision(4) << tm->tm_year + 1900;
	std::cout << std::setprecision(2) << tm->tm_mon + 1;
	std::cout << std::setprecision(2) << tm->tm_mday;
	std::cout << "_" << std::setprecision(2) << tm->tm_hour;
	std::cout << std::setprecision(2) << tm->tm_min;
	std::cout << std::setprecision(2) << tm->tm_sec << "] ";
}
