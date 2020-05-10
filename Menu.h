#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class Menu
{

public:

	/**
	*	default constructor.
	*/
	Menu();

	Menu(const Menu& src) {
		mCount = src.mCount;
		mName = src.mName;
		mPrice = src.mPrice;
	}

	/**
	*	destructor.
	*/
	~Menu();

	/**
	*	@brief	Get menu name.
	*	@pre	menu name is set.
	*	@post	none.
	*	@return	mName.
	*/
	string GetName();

	/**
	*	@brief	Get menu price.
	*	@pre	menu price is set.
	*	@post	none.
	*	@return	mPrice.
	*/
	int GetPrice();

	/**
	*	@brief	Get menu count.
	*	@pre	menu count is set.
	*	@post	none.
	*	@return	mCount.
	*/
	int GetCount();

	/**
	*	@brief	Print menu record.
	*	@pre	menu record(name, price) is set.
	*	@post	menu record print on the screen.
	*/
	void PrintMenu();

	/**
	*	@brief	Set menu name.
	*	@pre	none.
	*	@post	menu name is set.
	*	@param	inName	menu name.
	*/
	void SetName(string inName);

	/**
	*	@brief	Set menu price.
	*	@pre	none.
	*	@post	menu price is set.
	*	@param	inPrice	menu price.
	*/
	void SetPrice(int inPrice);

	/**
	*	@brief	Set menu count.
	*	@pre	none.
	*	@post	menu count is set.
	*	@param	inCount	menu count.
	*/
	void SetCount(int inCount);

	/**
	*	@brief	Set menu recode.
	*	@pre	none.
	*	@post	menu recode is set.
	*	@param	inCode	menu code.
	*	@param	inName	menu name.
	*	@param	inPrice	menu price.
	*	@param	inCount	menu count.
	*/
	void SetMenu(string inName, int inPrice, int inCount);

	/**
	*	@brief	Set menu name from keyboard.
	*	@pre	none.
	*	@post	menu name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set menu price from keyboard.
	*	@pre	none.
	*	@post	menu price is set.
	*/
	void SetPriceFromKB();

	/**
	*	@brief	Edit menu from keyboard.
	*	@pre	none.
	*	@post	menu(name, price) is reset.
	*/
	void EditMenuFromKB();

	/**
	*	@brief	mCount increases 1.
	*	@pre	none.
	*	@post	mCount increases 1.
	*/
	void Counting();

	/**
	*	@brief	mCount is initialized .
	*	@pre	none.
	*	@post	mCount is reset to 0
	*/
	void InitializeCount();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	menu record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	Menu& operator=(Menu& otherMenu);

	bool operator>(Menu& otherMenu);

	bool operator<(Menu& otherMenu);

	bool operator==(Menu& otherMenu);

	bool operator!=(Menu& otherMenu);


private:
	string mName;	// �޴��� �̸�.
	int mPrice;		// �޴��� ����.
	int mCount;		// �޴��� �ȸ� Ƚ��.
};