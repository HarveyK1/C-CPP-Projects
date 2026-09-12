#pragma once
#include <string>


class Account
{
public:
	Account();
	~Account();

	void Run();
	void Deposit();
	void Withdraw();
	void DepositMath();
	void WithdrawMath();
	void CheckBalacnes();
	void PrintBalance(std::string label, int wholeNumber, int centsNumber);


	int continueChoice{};


private:
	double m_inputDeposit{};
	double m_inputWithdraw{};

	int m_walletBalance{100};
	int m_walletCentsBalance{99};

	int m_bankBalance{};
	int m_bankCentsBalance{};

};