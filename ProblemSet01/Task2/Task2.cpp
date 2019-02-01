#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

/******************************************
Part A. Date Related Functions
******************************************/
struct Date {
	int day;
	int month;
	int year;
};

void make_date( Date* pNewDate, 
		int year, int month, int day )
{
	pNewDate->day = day;
	pNewDate->month = month;
	pNewDate->year = year;
}

int compare_date( Date* pDateA,  Date* pDateB )
 {
	int num1= pDateA->day + (pDateA->month*30) + (pDateA->year*30);
	int num2= pDateB->day + (pDateB->month*30) + (pDateB->year*30);
	if (num1 > num2){
		return 1;
	}
	else if(num2>num1){
		return -1;
	}else{
		return 0;
	}
}

/******************************************
Part B. Time Related Functions
******************************************/
struct Time {
	int hour;
	int minute;
};

void make_time( Time* pNewTime, int hour, int minute)
{
	pNewTime->hour = hour;
	pNewTime->minute = minute;
}

int compare_time( Time* pTimeA, Time* pTimeB)
{
	int time1 = (pTimeA->hour)*60 + pTimeA->minute;
	int time2 = (pTimeB->hour)*60 + pTimeB->minute;
	if (time2>time1){
		return -1;
	}
	else if ( time1>time2){
		return 1;
	}
	else {
		return 0;
	}
}


/******************************************
Part C. Appointmnet Related Functions
******************************************/

struct Appointment {
	struct Date Tdate;
	struct Time STime;
	struct Time ETime;
	string desc;
};

void make_appointment( Appointment* pNewApt,
             string description, 
             int year, int month, int day,
             int startHour, int startMinute,
             int endHour, int endMinute ) 
{
	make_date(&pNewApt->Tdate,year,month,day);
	make_time(&pNewApt->STime,startHour,startMinute);
	make_time(&pNewApt->ETime,endHour,endMinute);
	pNewApt->desc = description;
}


bool has_conflict( Appointment* pAptA, Appointment* pAptB)
{
	if(compare_date(&(pAptA->Tdate),&(pAptB->Tdate))==0)
	{
		if(
		((compare_time(&(pAptA->STime),&(pAptB->STime)) < 1) && (compare_time(&(pAptA->ETime),&(pAptB->STime)) < 1 ))
			||
		((compare_time(&(pAptB->STime),&(pAptA->STime)) < 1 ) && (compare_time(&(pAptB->ETime),&(pAptA->STime)) < 1 ))
		) 
		{
			return false;
		}
		return true;
	}
	return false;
}

int main()
{
	//Comment / modify the following statements to test
	//Note: you should test beyond these cases
	//Note2: you should consider implement additional useful helper
	//       functions

	/*****************
     *Testing Part A.*
	 *****************/

	struct Date dateOne, dateTwo;
	make_date(&dateOne, 2018, 1, 23);
	make_date(&dateTwo, 2018, 1, 24);
	//cout<< dateOne.day << dateOne.month << dateOne.year << endl;
	//cout<< dateTwo.day << dateTwo.month << dateTwo.year << endl;
	//Should be 0 for the sample test values above
	//printf("Date compare result = %d\n", 
	//		compare_date(&dateOne, &dateTwo) );
	

	/*****************
     *Testing Part B.*
	 *****************/

	//struct Time timeOne, timeTwo;
	//make_time(&timeOne, 11, 30);
	//make_time(&timeTwo,13, 45);

	//Should be -1 for the sample test values above
	//printf("Time compare result = %d\n", 
	//			compare_time(&timeOne, &timeTwo) );
	
	/*****************
     *Testing Part C.*
	 *****************/
	struct Appointment aptOne, aptTwo;
	make_appointment(&aptOne, "Appointment One",
					2018, 1, 24, 00, 00, 23, 59);

	make_appointment(&aptTwo, "Appointment Two",
					2018, 1, 23, 00, 20, 00, 30);

	// Should be Fine for the sample test values above
	// Make sure you test all possibilities
	if (has_conflict( &aptOne, &aptTwo)){
			printf("Appointments CLASH!\n");
	} else {
			printf("Appointments Fine!\n");
	}

	return 0;
}
