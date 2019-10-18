#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthdays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 &&
			year % 4 == 0
			&& year % 100 != 0 || year % 400 == 0) monthdays[2] = 29;
		return monthdays[month];
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year >= 0 && month > 0 && month < 13 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else cout << "ÊäÈë·Ç·¨" << endl;
	}
	Date(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	void print();
private:
	int _year;
	int _month;
	int _day;
};
void Date::print()
{
	cout << _year<<"-" << _month <<"-"<< _day<<endl;
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date Date::operator+(int days)
{
	Date tmp=*this;
	tmp._day += days;
	while (tmp._day >GetMonthDay(tmp._year,tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month > 12) tmp._year++,tmp. _month = 1;
	}
	return tmp;
}
Date Date:: operator-(int days)
{
	Date tmp = *this;
	while (tmp._day - days < 0)
	{
		tmp._day += GetMonthDay(tmp._year, tmp._month--);
		if (tmp._month < 1) tmp._year--, tmp._month = 1;
	}
	tmp._day -= days;
	return tmp;
}
int Date::operator-(const Date& d)
{
	Date tmp = d;
	int count = 0;
	if (_year > d._year)
	{
		while (_year != tmp._year || _month != tmp._month || _day != tmp._day)
		{
			tmp.operator+(1);
			count++;
		}
	}
	else
	{
		while (_year != tmp._year || _month != tmp._month || _day != tmp._day)
		{
			tmp=tmp.operator+(1);
			count++;
		}
	}
	return count;
}
Date& Date:: operator++()
{
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int)
{
	return *this + 1;
}
Date& Date:: operator--()
{
	*this = *this - 1;
	return *this;
}
Date Date::operator--(int)
{
	return *this - 1;
}
bool Date::operator>(const Date& d)const
{
	if (_year > d._year||_year==d._year&&_month>d._month
		|| _year == d._year&&_month == d._month&&_day>d._day) return true;
	else return false;
}
bool Date::operator<(const Date& d)const
{
	if (_year < d._year || _year == d._year&&_month < d._month
		|| _year == d._year&&_month == d._month&&_day < d._day) return true;
	else return false;
}
bool Date::operator>=(const Date& d)const
{
	//return *this > d&&_year == d._year&&_month == d._month&&_day == d._day;
	return !(*this < d);
}
bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}
bool Date::operator==(const Date& d)const
{
	return _year == d._year&&_month == d._month&&_day == d._day;
}
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}
