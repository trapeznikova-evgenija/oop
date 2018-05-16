#include "stdafx.h"
#include "../lab_3/TV.h"

TEST_CASE("CTVSet Class Tests")
{
	cout << "CTVSet Class Tests" << endl;
	CTVSet tv;

	//�������� ����, ��� ��������� ���������� ��������
	cout << "-- Checking that the TV is initially off" << endl;
	CHECK(tv.isTurnedOn() == false);

	cout << "-- The TV can be turned on and off" << endl;
	SECTION("�������� ����������� ��������� � ���������� ����������")
	{
		tv.TurnOn();
		CHECK(tv.isTurnedOn() == true);

		tv.TurnOff();
		CHECK(tv.isTurnedOn() == false);
	}

	tv.TurnOff();
	tv.TurnOn();

	cout << "-- Verify that channels can only be selected in the valid range" << endl;
	SECTION("�������� ������������ ������ ������� �� ����������� ���������")
	{
		cout << "" << endl;


		//��� ������ ��������� ���������� ������ ���� 1 �����
		CHECK(tv.GetChannel() == 1);
		cout << "-- 1 channel on first power-up" << endl;

		CHECK(tv.SelectChannel(5) == true);
		CHECK(tv.SelectChannel(1) == true);
		CHECK(tv.SelectChannel(0) == false);
		CHECK(tv.SelectChannel(99) == true);
		CHECK(tv.SelectChannel(100) == false);

	}

	cout << "-- After turning the TV off and on, the channel has not changed" << endl;
	SECTION("��������, ��� ����� ��������� ����������, ����� �������� �����, ����� ��� �����")
	{
		tv.SelectChannel(5);
		tv.TurnOff();
		tv.TurnOn();
		CHECK(tv.GetChannel() == 5);
	}

	cout << "-- Check that the channels in the TV are switched" << endl;
	SECTION("�������� ������ �������")
	{
		tv.SelectChannel(75);
		CHECK(tv.GetChannel() == 75);

		//�������� �� ��� �� ������, ���� ����� �� ���������


		tv.SelectChannel(456);
		CHECK(tv.GetChannel() == 75);
	}

	cout << "-- When TV is off 0 channel" << endl;
	SECTION("�������� ����, ��� � ����������� ��������� 0 �����")
	{
		tv.TurnOff();
		CHECK(tv.GetChannel() == 0);
	}
}