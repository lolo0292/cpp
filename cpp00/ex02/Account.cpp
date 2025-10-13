#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

// ---- Définition des membres statiques ----
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ---- Outil d'affichage du timestamp ----
void Account::_displayTimestamp(void) {
    std::time_t now = std::time(0);
    std::tm *lt = std::localtime(&now);

    char buf[20];
    // Format: [YYYYMMDD_HHMMSS]
    if (lt && std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", lt)) {
        std::cout << "[" << buf << "] ";
    } else {
        std::cout << "[00000000_000000] ";
    }
}

// ---- Getters statiques ----
int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

// ---- Affichage global ----
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout
        << "accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals()
        << std::endl;
}

// ---- Ctor / Dtor ----
Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts),
  _amount(initial_deposit),
  _nbDeposits(0),
  _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "created"
        << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "closed"
        << std::endl;
}

// ---- Méthodes d'instance ----
void Account::makeDeposit(int deposit) {
    int p_amount = _amount;
    _amount += deposit;
    ++_nbDeposits;

    _totalAmount += deposit;
    ++_totalNbDeposits;

    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "deposit:" << deposit << ";"
        << "amount:" << _amount << ";"
        << "nb_deposits:" << _nbDeposits
        << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    int p_amount = _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << p_amount << ";";

    if (withdrawal > _amount) {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    ++_nbWithdrawals;

    _totalAmount -= withdrawal;
    ++_totalNbWithdrawals;

    std::cout
        << "withdrawal:" << withdrawal << ";"
        << "amount:" << _amount << ";"
        << "nb_withdrawals:" << _nbWithdrawals
        << std::endl;

    return true;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "deposits:" << _nbDeposits << ";"
        << "withdrawals:" << _nbWithdrawals
        << std::endl;
}
