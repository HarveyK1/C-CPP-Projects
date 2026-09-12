#include <iostream>
#include "Account.h"


Account::Account()
{
	// nothing in constructor, just declaring it (not sure what to use it for).
}

Account::~Account()
{
	// nothing in destructor, just declaring it (not sure what to use it for).
}

void Account::Run()
{
	int bankChoice{};

	do
	{
		std::cout << "Welcome to our ATM\n";

		std::cout << "1. Bank Deposit.\n2. Bank Withdraw.\n3. Check Balances.\n";
		std::cout << "Please choose an option: "; std::cin >> bankChoice;

		if (bankChoice < 1 || bankChoice > 3)
		{
			system("cls");
			std::cout << "Please enter a valid option\n\n";
		}

	} while (bankChoice < 1 || bankChoice > 3);


	switch (bankChoice)
	{
	case 1: // selects bank deposit - (wallet money into bank)
		Deposit();
		break;
	case 2: // selects bank withdraw - (bank money into wallet)
		Withdraw();
		break;
	case 3: // check balances
		CheckBalacnes();
		break;

	default:
		break;
	}
}

void Account::Deposit()
{
	std::cout << "Please enter the amount you would like to deposit into your bank: "; std::cin >> m_inputDeposit;
	DepositMath();
	std::cout << std::endl;
}

void Account::Withdraw()
{
	std::cout << "Please enter the amount you would like to withdraw to your wallet: "; std::cin >> m_inputWithdraw;
	WithdrawMath();
	std::cout << std::endl;
}

void Account::CheckBalacnes()
{
	int choice{};
	system("cls");
	PrintBalance("Bank Balance: ", m_bankBalance, m_bankCentsBalance);
	PrintBalance("Wallet Balance: ", m_walletBalance, m_walletCentsBalance);

	std::cout << "1. to go back.\n";
	std::cout << "Enter your choice: "; std::cin >> choice;

	if (choice == 1)
	{
		system("cls");
		Run();
	}
}

void Account::DepositMath()
{
	if ((m_walletBalance && m_walletCentsBalance) <= 0.0)
	{
		std::cout << "Your wallet balance is: " << m_walletBalance << "." << m_walletCentsBalance << ", you don't have enough money in your wallet to deposit\n";
	}
	else if ((m_walletBalance || m_walletCentsBalance) >= 0.1)
	{
		int bWholeNumber{ static_cast<int>(m_inputDeposit) };
		m_bankBalance += bWholeNumber;
		
		double bDecimalPart{ m_inputDeposit - bWholeNumber }; // input - wholeNumber to get decimal part (cents)
		
		int bCentsNumber{ static_cast<int>(bDecimalPart * 100 + 0.5) }; // gets the 0.20 then * 100 so int centsNumber stores 20 which we can later print as cents
		m_bankCentsBalance += bCentsNumber;

		m_walletBalance -= bWholeNumber;
		m_walletCentsBalance -= bCentsNumber;
	}
}

void Account::WithdrawMath()
{
	if ((m_bankBalance && m_bankCentsBalance) <= 0.0)
	{
		std::cout << "Your bank balance is: " << m_bankBalance << "." << m_bankCentsBalance << ", you don't have have enough money in your bank to withdraw\n";
	}
	else if ((m_bankBalance || m_bankCentsBalance) >= 0.1)
	{
		int bWholeNumber{ static_cast<int>(m_inputWithdraw) };
		m_bankBalance -= bWholeNumber;

		double bDecimalPart{ m_inputWithdraw - bWholeNumber };

		int bCentsNumber{ static_cast<int>(bDecimalPart * 100 + 0.5) };
		m_bankCentsBalance -= bCentsNumber;

		m_walletBalance += bWholeNumber;
		m_walletCentsBalance += bCentsNumber;
	}
}

void Account::PrintBalance(std::string label, int wholeNumber, int centsNumber)
{
	if (centsNumber < 10)
	{
		std::cout << label << wholeNumber << ".0" << centsNumber << std::endl;
	}
	else if (centsNumber >= 10)
	{
		std::cout << label << wholeNumber << "." << centsNumber << std::endl;
	}
}