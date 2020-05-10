#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Client.h"
#include "shop.h"
#include "Tree.h"
#include "ClientLinkedList.h"

class Application {
public:
	Application() {
		Clients = new CList;
		Stores = Tree::getInstance();
		pn = NULL;
		m_nCurCommand = 0;
        // ���� �� �޴� �ʱ�ȭ

// �ѽ� ���� �߰� 
        shop* korean1;
        korean1 = new shop;
        korean1->SetShopName("����");
        // �޴� �߰�
        Menu tmp;
        tmp.SetMenu("����ġ��", 9000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean1->SetShopMenu(tmp);
        tmp.SetMenu("�Ұ�ⵤ��", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean1->SetShopMenu(tmp);
        tmp.SetMenu("�����α�", 7000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean1->SetShopMenu(tmp);
        tmp.SetMenu("���������ͺ����", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean1->SetShopMenu(tmp);
        tmp.SetMenu("�����ָԽӹ�", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean1->SetShopMenu(tmp);

        // ���� �߰� 
        shop* korean2;
        korean2 = new shop;
        korean2->SetShopName("���ڹ��");
        // �޴� �߰�
        tmp.SetMenu("�������", 5500, 0); // �̸�, ����, �ȸ� Ƚ��
        korean2->SetShopMenu(tmp);
        tmp.SetMenu("������������", 7500, 0); // �̸�, ����, �ȸ� Ƚ��
        korean2->SetShopMenu(tmp);
        tmp.SetMenu("������ɵ������", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean2->SetShopMenu(tmp);
        tmp.SetMenu("���������", 8500, 0); // �̸�, ����, �ȸ� Ƚ��
        korean2->SetShopMenu(tmp);
        tmp.SetMenu("������ġ�", 7500, 0); // �̸�, ����, �ȸ� Ƚ��
        korean2->SetShopMenu(tmp);

        // ���� �߰� 
        shop* korean3;
        korean3 = new shop;
        korean3->SetShopName("��޻���������");
        // �޴� �߰�
        tmp.SetMenu("��������", 15400, 0); // �̸�, ����, �ȸ� Ƚ��
        korean3->SetShopMenu(tmp);
        tmp.SetMenu("���", 15900, 0); // �̸�, ����, �ȸ� Ƚ��
        korean3->SetShopMenu(tmp);
        tmp.SetMenu("�ݹ�", 21900, 0); // �̸�, ����, �ȸ� Ƚ��
        korean3->SetShopMenu(tmp);
        tmp.SetMenu("�Ļ��", 16400, 0); // �̸�, ����, �ȸ� Ƚ��
        korean3->SetShopMenu(tmp);
        tmp.SetMenu("���̸�����", 5400, 0); // �̸�, ����, �ȸ� Ƚ��
        korean3->SetShopMenu(tmp);

        // ���� �߰� 
        shop* korean4;
        korean4 = new shop;
        korean4->SetShopName("�̾��װ��Ĵ�");
        // �޴� �߰�
        tmp.SetMenu("��ä�����������", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean4->SetShopMenu(tmp);
        tmp.SetMenu("���������������", 9000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean4->SetShopMenu(tmp);
        tmp.SetMenu("�Ѹ����ڴٸ�����", 9000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean4->SetShopMenu(tmp);
        tmp.SetMenu("�谡���δ��", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean4->SetShopMenu(tmp);
        tmp.SetMenu("�ÿ�ĮĮ���κ��", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean4->SetShopMenu(tmp);

        // ���� �߰� 
        shop* korean5;
        korean5 = new shop;
        korean5->SetShopName("�����̰���������");
        // �޴� �߰�
        tmp.SetMenu("���������", 20000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean5->SetShopMenu(tmp);
        tmp.SetMenu("�����Ѹ�����Ǻ�����", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean5->SetShopMenu(tmp);
        tmp.SetMenu("���������ɵ�����", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        korean5->SetShopMenu(tmp);
        tmp.SetMenu("���������Ƶ����", 7500, 0); // �̸�, ����, �ȸ� Ƚ��
        korean5->SetShopMenu(tmp);
        tmp.SetMenu("�����Ѹ�������", 7500, 0); // �̸�, ����, �ȸ� Ƚ��
        korean5->SetShopMenu(tmp);


        //�߽� ���� �߰� 
        shop* chinese1;
        chinese1 = new shop;
        chinese1->SetShopName("�뼺��");
        // �޴� �߰�
        tmp.SetMenu("�ſ�«��", 9000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese1->SetShopMenu(tmp);
        tmp.SetMenu("�ſ�¥��", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese1->SetShopMenu(tmp);
        tmp.SetMenu("���κ�«��", 10000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese1->SetShopMenu(tmp);
        tmp.SetMenu("�Ｑ«��", 9000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese1->SetShopMenu(tmp);
        tmp.SetMenu("��«��", 9000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese1->SetShopMenu(tmp);

        // ���� �߰� 
        shop* chinese2;
        chinese2 = new shop;
        chinese2->SetShopName("����ö����");
        // �޴� �߰�
        tmp.SetMenu("¥���", 5000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese2->SetShopMenu(tmp);
        tmp.SetMenu("«��", 6000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese2->SetShopMenu(tmp);
        tmp.SetMenu("������", 7000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese2->SetShopMenu(tmp);
        tmp.SetMenu("���Ƕ��̽�", 8000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese2->SetShopMenu(tmp);
        tmp.SetMenu("�ᳪ��«��", 9000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese2->SetShopMenu(tmp);

        // ���� �߰� 
        shop* chinese3;
        chinese3 = new shop;
        chinese3->SetShopName("��í��");
        // �޴� �߰�
        tmp.SetMenu("¥���", 5000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese3->SetShopMenu(tmp);
        tmp.SetMenu("�Ｑ«��", 8500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese3->SetShopMenu(tmp);
        tmp.SetMenu("����������", 16000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese3->SetShopMenu(tmp);
        tmp.SetMenu("�����������", 7500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese3->SetShopMenu(tmp);
        tmp.SetMenu("������ä��", 7500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese3->SetShopMenu(tmp);

        // ���� �߰� 
        shop* chinese4;
        chinese4 = new shop;
        chinese4->SetShopName("����«��");
        // �޴� �߰�
        tmp.SetMenu("����«��", 7500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese4->SetShopMenu(tmp);
        tmp.SetMenu("��«��", 8500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese4->SetShopMenu(tmp);
        tmp.SetMenu("����¥��", 6000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese4->SetShopMenu(tmp);
        tmp.SetMenu("����������", 14000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese4->SetShopMenu(tmp);
        tmp.SetMenu("������", 30000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese4->SetShopMenu(tmp);

        // ���� �߰� 
        shop* chinese5;
        chinese5 = new shop;
        chinese5->SetShopName("ȫ�����0410");
        // �޴� �߰�
        tmp.SetMenu("¥���", 4500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese5->SetShopMenu(tmp);
        tmp.SetMenu("«��", 5500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese5->SetShopMenu(tmp);
        tmp.SetMenu("¥���", 6500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese5->SetShopMenu(tmp);
        tmp.SetMenu("������", 11000, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese5->SetShopMenu(tmp);
        tmp.SetMenu("����«��", 6500, 0); // �̸�, ����, �ȸ� Ƚ��
        chinese5->SetShopMenu(tmp);

        //�н� ���� �߰� 
        shop* snack1;
        snack1 = new shop;
        snack1->SetShopName("���Ǿƶ�����");
        // �޴� �߰�
        tmp.SetMenu("���Ǿƶ�����", 12000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack1->SetShopMenu(tmp);
        tmp.SetMenu("���Ǿư�ⶱ����", 16000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack1->SetShopMenu(tmp);
        tmp.SetMenu("�ſ���߹�", 20000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack1->SetShopMenu(tmp);
        tmp.SetMenu("�ſ����������", 24000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack1->SetShopMenu(tmp);
        tmp.SetMenu("�ſ�ߺ�����", 24000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack1->SetShopMenu(tmp);

        // ���� �߰� 
        shop* snack2;
        snack2 = new shop;
        snack2->SetShopName("�����Ź�&������");
        // �޴� �߰�
        tmp.SetMenu("�ķ�豹��������", 4000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack2->SetShopMenu(tmp);
        tmp.SetMenu("�����Ź�", 5000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack2->SetShopMenu(tmp);
        tmp.SetMenu("�����Ź�", 5000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack2->SetShopMenu(tmp);
        tmp.SetMenu("ġ��߰����Ź�", 6000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack2->SetShopMenu(tmp);
        tmp.SetMenu("��¥���Ժ񿣳��Ź�", 6500, 0); // �̸�, ����, �ȸ� Ƚ��
        snack2->SetShopMenu(tmp);

        // ���� �߰� 
        shop* snack3;
        snack3 = new shop;
        snack3->SetShopName("��������");
        // �޴� �߰�
        tmp.SetMenu("��⸸��", 4500, 0); // �̸�, ����, �ȸ� Ƚ��
        snack3->SetShopMenu(tmp);
        tmp.SetMenu("��ġ����", 4500, 0); // �̸�, ����, �ȸ� Ƚ��
        snack3->SetShopMenu(tmp);
        tmp.SetMenu("������", 5000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack3->SetShopMenu(tmp);
        tmp.SetMenu("�߰��̸�", 5500, 0); // �̸�, ����, �ȸ� Ƚ��
        snack3->SetShopMenu(tmp);
        tmp.SetMenu("��⸸�α�", 6000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack3->SetShopMenu(tmp);

        // ���� �߰� 
        shop* snack4;
        snack4 = new shop;
        snack4->SetShopName("�����нļ�");
        // �޴� �߰�
        tmp.SetMenu("��¡��~Ƣ��", 2500, 0); // �̸�, ����, �ȸ� Ƚ��
        snack4->SetShopMenu(tmp);
        tmp.SetMenu("��¡���ߵ���SET", 23000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack4->SetShopMenu(tmp);
        tmp.SetMenu("���������", 18000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack4->SetShopMenu(tmp);
        tmp.SetMenu("���������", 17000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack4->SetShopMenu(tmp);
        tmp.SetMenu("ġ��ߺ�����", 19000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack4->SetShopMenu(tmp);

        // ���� �߰� 
        shop* snack5;
        snack5 = new shop;
        snack5->SetShopName("���붱����");
        // �޴� �߰�
        tmp.SetMenu("ġ�����", 15000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack5->SetShopMenu(tmp);
        tmp.SetMenu("�ع�ġ�����", 18000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack5->SetShopMenu(tmp);
        tmp.SetMenu("ī��ġ�����", 15000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack5->SetShopMenu(tmp);
        tmp.SetMenu("¥��ġ�����", 15000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack5->SetShopMenu(tmp);
        tmp.SetMenu("�ع�ġ�����", 18000, 0); // �̸�, ����, �ȸ� Ƚ��
        snack5->SetShopMenu(tmp);

        //ġŲ ���� �߰� 
        shop* chicken1;
        chicken1 = new shop;
        chicken1->SetShopName("60��ġŲ");
        // �޴� �߰�
        tmp.SetMenu("����ġŲ", 18900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken1->SetShopMenu(tmp);
        tmp.SetMenu("����ġŲ", 18900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken1->SetShopMenu(tmp);
        tmp.SetMenu("�Ķ��̵�", 16900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken1->SetShopMenu(tmp);
        tmp.SetMenu("�彺ġŲ", 18900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken1->SetShopMenu(tmp);
        tmp.SetMenu("���ġŲ", 17900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken1->SetShopMenu(tmp);

        // ���� �߰� 
        shop* chicken2;
        chicken2 = new shop;
        chicken2->SetShopName("BHC��õ��");
        // �޴� �߰�
        tmp.SetMenu("�Ѹ�Ŭ", 17000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken2->SetShopMenu(tmp);
        tmp.SetMenu("����ĭ", 18000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken2->SetShopMenu(tmp);
        tmp.SetMenu("ġ�Ͽ�", 18000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken2->SetShopMenu(tmp);
        tmp.SetMenu("����ŷ", 17000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken2->SetShopMenu(tmp);
        tmp.SetMenu("�Ķ��̵�", 15000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken2->SetShopMenu(tmp);

        // ���� �߰� 
        shop* chicken3;
        chicken3 = new shop;
        chicken3->SetShopName("����ġŲ");
        // �޴� �߰�
        tmp.SetMenu("������Ͽ�������", 15000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken3->SetShopMenu(tmp);
        tmp.SetMenu("��������޺�", 18000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken3->SetShopMenu(tmp);
        tmp.SetMenu("�����Ķ��̵�", 15000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken3->SetShopMenu(tmp);
        tmp.SetMenu("���̿�������", 15000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken3->SetShopMenu(tmp);
        tmp.SetMenu("���̻��", 16000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken3->SetShopMenu(tmp);

        // ���� �߰� 
        shop* chicken4;
        chicken4 = new shop;
        chicken4->SetShopName("�׳�ġŲ");
        // �޴� �߰�
        tmp.SetMenu("����ġ�����", 17000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken4->SetShopMenu(tmp);
        tmp.SetMenu("������ġŲ", 17000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken4->SetShopMenu(tmp);
        tmp.SetMenu("������Ż�Ĵ�", 17000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken4->SetShopMenu(tmp);
        tmp.SetMenu("����ġŲ", 17000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken4->SetShopMenu(tmp);
        tmp.SetMenu("���ϵ�ġŲ", 15000, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken4->SetShopMenu(tmp);

        // ���� �߰� 
        shop* chicken5;
        chicken5 = new shop;
        chicken5->SetShopName("ġŲ�÷���");
        // �޴� �߰�
        tmp.SetMenu("����ŷ", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken5->SetShopMenu(tmp);
        tmp.SetMenu("����ũ���̾�Ͼ�ġŲ", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken5->SetShopMenu(tmp);
        tmp.SetMenu("����ġŲ", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken5->SetShopMenu(tmp);
        tmp.SetMenu("���ġŲ", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken5->SetShopMenu(tmp);
        tmp.SetMenu("���ſ�ġŲ", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        chicken5->SetShopMenu(tmp);


        //���� ���� �߰� 
        shop* pizza1;
        pizza1 = new shop;
        pizza1->SetShopName("�ݿø����ڼ�");
        // �޴� �߰�
        tmp.SetMenu("������ũġ���", 21900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza1->SetShopMenu(tmp);
        tmp.SetMenu("��������", 23900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza1->SetShopMenu(tmp);
        tmp.SetMenu("�ݹ�����", 16900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza1->SetShopMenu(tmp);
        tmp.SetMenu("�����������", 19900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza1->SetShopMenu(tmp);
        tmp.SetMenu("�Ұ������", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza1->SetShopMenu(tmp);

        // ���� �߰� 
        shop* pizza2;
        pizza2 = new shop;
        pizza2->SetShopName("��������");
        // �޴� �߰�
        tmp.SetMenu("��������", 22900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza2->SetShopMenu(tmp);
        tmp.SetMenu("�ٻ��ѽ�������ġŲ", 22900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza2->SetShopMenu(tmp);
        tmp.SetMenu("�޴��Ѱ���", 19900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza2->SetShopMenu(tmp);
        tmp.SetMenu("�����հ���", 19900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza2->SetShopMenu(tmp);
        tmp.SetMenu("��������������", 17900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza2->SetShopMenu(tmp);

        // ���� �߰� 
        shop* pizza3;
        pizza3 = new shop;
        pizza3->SetShopName("û������");
        // �޴� �߰�
        tmp.SetMenu("�Ҷ�Ұ��", 13900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza3->SetShopMenu(tmp);
        tmp.SetMenu("��¥��������", 13900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza3->SetShopMenu(tmp);
        tmp.SetMenu("����ġ������", 12900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza3->SetShopMenu(tmp);
        tmp.SetMenu("����Ұ������", 13900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza3->SetShopMenu(tmp);
        tmp.SetMenu("��ä����", 13900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza3->SetShopMenu(tmp);

        // ���� �߰� 
        shop* pizza4;
        pizza4 = new shop;
        pizza4->SetShopName("���ھ˺���");
        // �޴� �߰�
        tmp.SetMenu("��ȣ������", 18000, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza4->SetShopMenu(tmp);
        tmp.SetMenu("�������", 24000, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza4->SetShopMenu(tmp);
        tmp.SetMenu("������", 18000, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza4->SetShopMenu(tmp);
        tmp.SetMenu("�λ�����", 26000, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza4->SetShopMenu(tmp);
        tmp.SetMenu("��������", 24000, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza4->SetShopMenu(tmp);

        // ���� �߰� 
        shop* pizza5;
        pizza5 = new shop;
        pizza5->SetShopName("������������");
        // �޴� �߰�
        tmp.SetMenu("�������", 20900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza5->SetShopMenu(tmp);
        tmp.SetMenu("ĥ����������������", 20900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza5->SetShopMenu(tmp);
        tmp.SetMenu("������ü������", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza5->SetShopMenu(tmp);
        tmp.SetMenu("������������", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza5->SetShopMenu(tmp);
        tmp.SetMenu("ũ��ġ�����", 14900, 0); // �̸�, ����, �ȸ� Ƚ��
        pizza5->SetShopMenu(tmp);


        // ī�װ� �߰�
        Stores->InsertCate("�ѽ�");
        Stores->InsertCate("�߽�");
        Stores->InsertCate("�н�");
        Stores->InsertCate("ġŲ");
        Stores->InsertCate("����");

        pn = Stores->ReturnRoot();

        // �ѽ� ���� �߰� 
        Stores->InsertShop(1, korean1);
        Stores->InsertShop(1, korean2);
        Stores->InsertShop(1, korean3);
        Stores->InsertShop(1, korean4);
        Stores->InsertShop(1, korean5);

        // �߽� ���� �߰� 
        Stores->InsertShop(2, chinese1);
        Stores->InsertShop(2, chinese2);
        Stores->InsertShop(2, chinese3);
        Stores->InsertShop(2, chinese4);
        Stores->InsertShop(2, chinese5);

        // �н� ���� �߰� 
        Stores->InsertShop(3, snack1);
        Stores->InsertShop(3, snack2);
        Stores->InsertShop(3, snack3);
        Stores->InsertShop(3, snack4);
        Stores->InsertShop(3, snack5);

        // ġŲ ���� �߰� 
        Stores->InsertShop(4, chicken1);
        Stores->InsertShop(4, chicken2);
        Stores->InsertShop(4, chicken3);
        Stores->InsertShop(4, chicken4);
        Stores->InsertShop(4, chicken5);

        // ���� ���� �߰� 
        Stores->InsertShop(5, pizza1);
        Stores->InsertShop(5, pizza2);
        Stores->InsertShop(5, pizza3);
        Stores->InsertShop(5, pizza4);
        Stores->InsertShop(5, pizza5);
    }

	~Application() {
        delete Clients;
        delete Stores;
        delete pn;
    }

	void Run();

	int GetCommand();

	void ClientMode();

	void StoreMode();

private:
	CList* Clients;
	Tree* Stores;
	shop* pn;
	int m_nCurCommand;
};