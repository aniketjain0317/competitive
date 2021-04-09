#include <iostream>
#include <cassert>
using namespace std;



class DateTime
{
	int Entry=0;

	static bool getBit(int n, int k) {return (n>>k)&1;}
	static void modifyBit(int &n, int k, bool b) {n=(n & ~(1<<k)) | ((b << k) & (1<<k));}
	static bool IsValidDate(const int &year, const int &month, const int &day)
	{
		// 1980 + (0,127) <- range of the year
		if(!(year>=1980 && year<=2107)) return false;
		if(!(month>=1 && month<=12)) return false;
		if(!(day>=0 && day<=31)) return false;
		return true;
	}
	static bool IsValidTime(const int& hour, const int& minute, const int& second)
	{
		// minute/second cannot be 60 as 60===0
		if (!(0<=hour && hour <= 23)) return false;
		if(!(0<=minute && minute <= 59)) return false;
		if(!(0<=second && second <= 59)) return false;
		return true;
	}
	static int MapDate(const int& year, const int& month, const int& day)
	{
		int date=0;
		int yearVal = year-1980;
		for(int i=0;i<5;i++) modifyBit(date,i,getBit(day,i));
		for(int i=0;i<4;i++) modifyBit(date,5+i,getBit(month,i));
		for(int i=0;i<7;i++) modifyBit(date,9+i,getBit(yearVal,i));
		return date;
	}
	static int MapTime(const int& hour, const int& minute, const int& second)
	{
		int time;
		int secondVal = second/2;
		for(int i=0;i<5;i++) modifyBit(time,11+i,getBit(hour,i));
		for(int i=0;i<6;i++) modifyBit(time,5+i,getBit(minute,i));
		for(int i=0;i<5;i++) modifyBit(time,i,getBit(secondVal,i));
		return time;
	}
	// Define more methods for help here
	// ....
public:
	DateTime(const int& Year = 2017, const int& Month = 1, const int& Day = 1,
		const int& Hour = 0, const int& Minute = 0, const int& Second = 0)
	{
		if (!IsValidDate(Year, Month, Day) || !IsValidTime(Hour, Minute, Second))
			cout << "Invaid Timing!!" << endl;

		Entry = MapDate(Year, Month, Day) << 16 | MapTime(Hour, Minute, Second);
		cout << Entry << endl;
	}

	void SetYear(const int& newYear)
	{
		int yearVal = newYear-1980;
		for(int i=0;i<7;i++) modifyBit(Entry,25+i,getBit(yearVal,i));
		// 7 is the number of bits in newYear
		// 25 = 32-7
		// Hence, this for loop sets the 25th to 31st bit as
	}
	void SetMonth(const int& newMonth)
	{
		for(int i=0;i<4;i++) modifyBit(Entry,21+i,getBit(newMonth,i));
	}
	void SetDay(const int& newDay)
	{
		for(int i=0;i<5;i++) modifyBit(Entry,16+i,getBit(newDay,i));
	}
	void SetHour(const int& newHour)
	{
		for(int i=0;i<5;i++) modifyBit(Entry,11+i,getBit(newHour,i));
	}
	void SetMinute(const int& newMinute)
	{
		for(int i=0;i<6;i++) modifyBit(Entry,5+i,getBit(newMinute,i));
	}
	void SetSecond(const int& newSecond)
	{
		int secondVal = newSecond/2;
		for(int i=0;i<5;i++) modifyBit(Entry,i,getBit(secondVal,i));
	}
	void SetDate(const int& newYear, const int& newMonth, const int& newDay)
	{
		SetYear(newYear);
		SetMonth(newMonth);
		SetDay(newDay);
	}
	void SetTime(const int& newHour, const int& newMinute, const int& newSecond)
	{
		SetHour(newHour);
		SetMinute(newMinute);
		SetSecond(newSecond);
	}

	int GetYear()
	{
		int year=0;
		for(int i=0;i<7;i++) modifyBit(year,i,getBit(Entry,25+i));
		year+=1980;
		return year;
	}
	int GetMonth()
	{
		int month=0;
		for(int i=0;i<4;i++) modifyBit(month,i,getBit(Entry,21+i));
		return month;
	}
	int GetDay()
	{
		int day=0;
		for(int i=0;i<5;i++) modifyBit(day,i,getBit(Entry,16+i));
		return day;
	}
	int GetHour()
	{
		int hour=0;
		for(int i=0;i<5;i++) modifyBit(hour,i,getBit(Entry,11+i));
		return hour;
	}
	int GetMinute()
	{
		int minute=0;
		for(int i=0;i<6;i++) modifyBit(minute,i,getBit(Entry,5+i));
		return minute;
	}
	int GetSecond()
	{
		int second=0;
		for(int i=0;i<5;i++) modifyBit(second,i,getBit(Entry,i));
		second*=2;
		return second;
	}
	void GetDate(int& Year, int& Month, int& Day)
	{
		Year = GetYear();
		Month = GetMonth();
		Day = GetDay();
	}
	void GetTime(int& Hour, int& Minute, int& Second)
	{
		Hour = GetHour();
		Minute = GetMinute();
		Second = GetSecond();
	}
};

int main()
{
	DateTime dt(2005,4,1,10,31,44);
	cout << dt.GetSecond() << endl;
}
