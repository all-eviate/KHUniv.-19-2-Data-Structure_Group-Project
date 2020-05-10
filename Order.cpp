#include "Order.h"


//Constructor
Order::Order(string clientid, string shopid_)
{
	oId = clientid;
	shopid = shopid_;
	SetOrderTotalPrice();
	SetOrderTime();
}

/**
*   @brief   Order�� Client�� Id�� ��ȯ
*   @pre   order�� client�� ����
*   @post   none
*   @param   none
*   @return order�� client�� id�� ��ȯ
*/
string Order::GetClientId() const {
	return oId;
}

/**
*   @brief   Order�� Shop�� Id�� ��ȯ
*   @pre   order�� Shop�� ����
*   @post   none
*   @param   none
*   @return order�� shop�� id�� ��ȯ
*/
string Order::GetShopId() const {
	return shopid;
}

/**
*   @brief   Order�� ������ ���� (MenuList���� �޴��� ������ ��ȯ�Ͽ�)
*   @pre   MenuList�� �ʱ�ȭ
*   @post   none
*   @param   none
*   @return Order�� ������ ����
*/
void Order::SetOrderTotalPrice() {
	oTotalPrice = menuList.GetTotal();
}

/**
*   @brief   Order�� ������ ��ȯ
*   @pre   MenuList�� �ʱ�ȭ
*   @post   none
*   @param   none
*   @return Order�� ������ ��ȯ
*/
int Order::GetOrderTotalPrice() const {
	return oTotalPrice;
}

/**
*   @brief   Order�� �ð��� ����
*   @pre   order ��ü�� ����
*   @post   none
*   @param   none
*   @return none
*/
void Order::SetOrderTime() {
	oTime = time(NULL);
}

/**
*   @brief   Order�� �ð��� ���
*   @pre   order ��ü�� ����
*   @post   none
*   @param   none
*   @return none
*/
void Order::PrintOrderTime() {
	struct tm* date;
	date = localtime(&oTime);
	//��/��/�� ��:��:�� �������� ���
	printf("%d/%d/%d %d:%d:%d\n", date->tm_year + 1900, date->tm_mon + 1, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);
}

string Order::ReturnOrderTime() {
	struct tm* date;
	date = localtime(&oTime);
	string t, y, m, d, h, min, s;
	y = to_string(date->tm_year + 1900);
	m = to_string(date->tm_mon + 1);
	d = to_string(date->tm_mday);
	h = to_string(date->tm_hour);
	min = to_string(date->tm_min);
	s = to_string(date->tm_sec);
	t = y + "�� " + m + "�� " + d + "�� " + h + "�� " + min + "�� " + s + "��";
	return  t;
}

/**
*   @brief   Order�� �ð��� time_t �������� ��ȯ
*   @pre   order ��ü�� ����
*   @post   none
*   @param   none
*   @return Order�� �ð��� ��ȯ
*/
time_t Order::GetOrderTime() const {
	return oTime;
}

/**
*   @brief   Order�� ������ ���
*   @pre   order���� menulist�� �ʱ�ȭ
*   @post   none
*   @param   none
*   @return Order�� ������ ���
*/
void Order::PrintOrder() {
	this->SetOrderTotalPrice();
	cout << endl;
	cout << "### Order ID : " << oId << endl;
	cout << "### Order Total Price : " << oTotalPrice << endl;
	menuList.PrintMenuList();
}

void Order::SetShopName(string _name) {
	shopid = _name;
}

void Order::OrderEnlist(Menu _Menu) {
	menuList.Add(_Menu);
}

/**
*	@brief	Order ��ü ���� menulist�� ����
*	@param	menulist�� ����ų pointer
*	@return	menulist�� ����
*/
int Order::GetOrderArray(SortedMenuList*& pointer) {
	pointer = &menuList;
	return menuList.GetLength();
}