#include "stdafx.h"
#include "../lab_3/TV.h"

TEST_CASE("CTVSet Class Tests")
{
	CTVSet tv;

	//проверка того, что телевизор изначально выключен
	CHECK(tv.isTurnedOn() == false);

	SECTION("Проверка возможности включения и выключения телевизора")
	{
		tv.TurnOn();
		CHECK(tv.isTurnedOn() == true);

		tv.TurnOff();
		CHECK(tv.isTurnedOn() == false);
	}

	tv.TurnOff();
	tv.TurnOn();

	SECTION("Проверка корректности выбора каналов из допустимого диапазона")
	{
		//при первом включении телевизора должен быть 1 канал
		CHECK(tv.GetChannel() == 1);
		
		CHECK(tv.SelectChannel(5) == true);
		CHECK(tv.SelectChannel(1) == true);
		CHECK(tv.SelectChannel(0) == false);
		CHECK(tv.SelectChannel(99) == true);
		CHECK(tv.SelectChannel(100) == false);

	}

	SECTION("Проверка, что после включения телевизора, канал остается таким, каким был ранее")
	{
		tv.SelectChannel(5);
		tv.TurnOff();
		tv.TurnOn();
		CHECK(tv.GetChannel() == 5);
	}

	SECTION("Проверка выбора каналов")
	{
		tv.SelectChannel(75);
		CHECK(tv.GetChannel() == 75);

		//остаемся на том же канале, если вышли из диапазона
		tv.SelectChannel(456);
		CHECK(tv.GetChannel() == 75);
	}

	SECTION("Проверка того, что в выключенном состоянии 0 канал")
	{
		tv.TurnOff();
		CHECK(tv.GetChannel() == 0);
	}
}