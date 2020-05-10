#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "SortedMenuList.h"
using namespace std;

class Order {
public:

	//Constructor
	Order(string clientid = "null", string shopid_ = "null");

	Order(Order& src) {
		menuList = src.menuList;
		oId = src.oId;
		oTime = src.oTime;
		oTotalPrice = src.oTotalPrice;
		shopid = src.shopid;
	}

	/**
	*   @brief   Order�� Client�� Id�� ��ȯ
	*   @pre   order�� client�� ����
	*   @post   none
	*   @param   none
	*   @return order�� client�� id�� ��ȯ
	*/
	string GetClientId() const;

	/**
	*   @brief   Order�� Shop�� Id�� ��ȯ
	*   @pre   order�� Shop�� ����
	*   @post   none
	*   @param   none
	*   @return order�� shop�� id�� ��ȯ
	*/
	string GetShopId() const;

	/**
	*   @brief   Order�� ������ ���� (MenuList���� �޴��� ������ ��ȯ�Ͽ�)
	*   @pre   MenuList�� �ʱ�ȭ
	*   @post   none
	*   @param   none
	*   @return Order�� ������ ����
	*/
	void SetOrderTotalPrice();

	/**
	*   @brief   Order�� ������ ��ȯ
	*   @pre   MenuList�� �ʱ�ȭ
	*   @post   none
	*   @param   none
	*   @return Order�� ������ ��ȯ
	*/
	int GetOrderTotalPrice() const;
	/**
	*   @brief   Order�� �ð��� ����
	*   @pre   order ��ü�� ����
	*   @post   none
	*   @param   none
	*   @return none
	*/
	void SetOrderTime();

	/**
	*   @brief   Order�� �ð��� ���
	*   @pre   order ��ü�� ����
	*   @post   none
	*   @param   none
	*   @return none
	*/
	void PrintOrderTime();

	string ReturnOrderTime();

	/**
	*   @brief   Order�� �ð��� time_t �������� ��ȯ
	*   @pre   order ��ü�� ����
	*   @post   none
	*   @param   none
	*   @return Order�� �ð��� ��ȯ
	*/
	time_t GetOrderTime() const;

	void SetShopName(string _name);

	void OrderEnlist(Menu _Menu);

	/**
	*   @brief   Order�� ������ ���
	*   @pre   order���� menulist�� �ʱ�ȭ
	*   @post   none
	*   @param   none
	*   @return Order�� ������ ���
	*/
	void PrintOrder();

	/**
	*	@brief	Order ��ü ���� menulist�� ����
	*	@param	menulist�� ����ų pointer
	*	@return	menulist�� ����
	*/
	int GetOrderArray(SortedMenuList*& pointer);



private:
	SortedMenuList menuList;
	string oId; // client id 
	string shopid; // shop id 
	int oTotalPrice;// total price of order
	time_t oTime; // client�� order�� �ð� 
};