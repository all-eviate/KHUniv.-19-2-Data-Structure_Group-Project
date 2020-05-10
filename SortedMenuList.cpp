#include "SortedMenuList.h"

/**
*	Relation between two items.
*/
//enum RelationType { LESS, GREATER, EQUAL };


// Make list empty.
void SortedMenuList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int SortedMenuList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool SortedMenuList::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int SortedMenuList::Add(Menu inData)
{
	if (IsFull()) {
		return 0;
	}

	bool moreToSearch;
	int location = 0;
	moreToSearch = (location < m_Length);
	while (moreToSearch) {
		if (inData < m_Array[location]) {
			moreToSearch = false;
		}
		else {
			location++;
			moreToSearch = (location < m_Length);
		}
	}

	for (int i = m_Length; i > location; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	m_Array[location] = inData;
	m_Length++;
	return 1;
}


// Initialize list iterator.
void SortedMenuList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int SortedMenuList::GetNextItem(Menu& data)
{
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
int SortedMenuList::Get(Menu& data)
{
	Menu tmp;

	ResetList();
	GetNextItem(tmp);
	while (m_CurPointer < m_Length) {
		if (tmp == data) {
			data = tmp;
			return 1;
		}
		else if (tmp > data)
			return 0;
		else {
			GetNextItem(tmp);
		}
	}
	return 0;
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
int SortedMenuList::Delete(Menu data)
{
	if (Get(data)) {
		for (int i = m_CurPointer; i < m_Length; i++) {
			m_Array[i] = m_Array[i + 1];
		}
		m_Length--;
		return 1;
	}
	else
		return 0;
}

//id�� ��ġ�ϴ� list�� item�� ã�Ƽ� �����Ѵ�.
int SortedMenuList::Replace(Menu data)
{
	Menu tmp = data;
	if (Get(tmp)) {
		m_Array[m_CurPointer] = data;
		return 1;
	}
	else
		return 0;
}

//����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
int SortedMenuList::GetBinarySearch(Menu& data) {
	int mid;
	int first = 0;
	int last = m_Length - 1;
	bool moreToSearch = (first <= last);
	bool found = false;

	while (moreToSearch && !found) {

		mid = (first + last) / 2;
		if (data < m_Array[mid]) {
			last = mid - 1;
			moreToSearch = (first <= last);
		}
		else if (data > m_Array[mid]) {
			first = mid + 1;
			moreToSearch = (first <= last);
		}
		else {
			found = true;
			data = m_Array[mid];
			return 1;
		}
	}
	return 0;
}

//�޴� ����Ʈ ���� �޴� ������ ������ ��ȯ
int SortedMenuList::GetTotal() {
	int total = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		total += m_Array[i].GetPrice();
	}

	return total;
}

//�޴� ����Ʈ ���� �޴��� ���
void SortedMenuList::PrintMenuList()
{
	cout << endl;
	cout << "### [Menu List] ###" << endl;
	for (int i = 0; i < m_Length; i++) {
		cout << i + 1<<". ";
		m_Array[i].PrintMenu();
	}
	cout << endl;
}

Menu SortedMenuList::returnmenu(int index) {
	return m_Array[index];
}