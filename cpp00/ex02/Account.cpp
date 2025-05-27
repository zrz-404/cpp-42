/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:47:13 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/21 13:54:04 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip> // For std::setw, std::setfill
#include <ctime>   // For time functions


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Private static method to display timestamp
// Format: [YYYYMMDD_HHMMSS] (e.g., [19920104_091532])
void Account::_displayTimestamp(void) {
    std::time_t t = std::time(0); // Get current time
    std::tm* now = std::localtime(&t);
    std::cout << "[" 
              << (now->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
              << std::setfill('0') << std::setw(2) << now->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << now->tm_hour
              << std::setfill('0') << std::setw(2) << now->tm_min
              << std::setfill('0') << std::setw(2) << now->tm_sec 
              << "] ";
}

// Constructor
Account::Account(int initial_deposit) : _amount(initial_deposit) {
    this->_accountIndex = _nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "created" << std::endl;
}

// Destructor
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "closed" << std::endl;
}

// --- Getters for static members ---
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

// --- Public static method ---
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

// --- Public member methods ---
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";"
              << "deposit:" << deposit << ";";

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << "amount:" << this->_amount << ";"
              << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";"
              << "withdrawal:";

    if (this->_amount < withdrawal) {
        std::cout << "refused" << std::endl;
        return false;
    } else {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << withdrawal << ";"
                  << "amount:" << this->_amount << ";"
                  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return true;
    }
}

int Account::checkAmount(void) const {
    // This function is const, it doesn't modify members.
    // Its return value isn't explicitly shown being used in the log for output formatting,
    // but it's part of the class. tests.cpp doesn't call it directly for printing.
    // It might be used internally or by other tests not provided.
    // For this exercise, just returning _amount is sufficient.
    return this->_amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Private default constructor (as per Account.hpp)
Account::Account(void) {
    // This constructor should not be callable from outside.
    // It's private, so it's likely meant to be un-implemented or used
    // by a very specific internal case which is not apparent here.
    // For the purpose of this exercise, it can be left empty or minimal.
    this->_accountIndex = _nbAccounts++; // Still needs to assign an index if called.
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    // _totalAmount does not change here by default.
    // No log output for this one usually.
}