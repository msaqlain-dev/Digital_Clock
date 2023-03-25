#include <iostream>
#include <windows.h>
#include <conio.h>
#include <dos.h>
using namespace std;
int main()
{
		
	int hr,min,sec;
	string am_pm;
	int day,month,year,input;
	cout<<"\n\t  __________________________________________________\n";
	cout<<"\t |                                                  |\n";
	cout<<"\t |                  Welcome to                      |\n";
	cout<<"\t |                                                  |\n";
	cout<<"\t |      *****   *          *****    *****   *    *  |\n";
	cout<<"\t |     *     *  *         *     *  *     *  *   *   |\n";
	cout<<"\t |     *        *         *     *  *        *  *    |\n";
	cout<<"\t |     *        *         *     *  *        * *     |\n";
	cout<<"\t |     *        *         *     *  *        *  *    |\n";
	cout<<"\t |     *     *  *      *  *     *  *     *  *   *   |\n";
	cout<<"\t |      *****    ******    *****    *****   *    *  |\n";
	cout<<"\t |                                               Me |\n";
	cout<<"\t |__________________________________________________|\n\n";
	
	system("color 0a");
	cout<<"\n\n\n\t\t\t    Please wait while loading\n\n";
 	char a=177, b=219;
 	cout<<"\t\t\t\t";
 	for (int i=0;i<=15;i++)
 	cout<<a;
 	cout<<"\r";
 	cout<<"\t\t\t\t";
 	for (int i=0;i<=15;i++)
 	{
  	cout<<b;
  	Sleep(500);
 	}
	system("cls");
			
	cout<<"\n\t1. Import System Time \n\n";
	cout<<"\t2. Set New Time \n\n";
	cout<<"\t3. Exit \n\n\n";
	cout<<"\tSelect Option : ";cin>>input;
	system("cls");	

	if(input==2)
	{	
		cout<<"\n\t <---Set Your Time---> \n";
		cout<<"\n\t Hour  : ";
		cin>>hr;
		cout<<"\n\t Min   : ";
		cin>>min;
		cout<<"\n\t Sec   : ";
		cin>>sec;
		cout<<"\n\t am/pm : ";
		cin>>am_pm;
		system("cls");
	
		cout<<"\n\t <---Set Your Date---> \n";
		cout<<"\n\t Day: ";
		cin>>day;
		cout<<"\n\t Month: ";
		cin>>month;
		cout<<"\n\t Year: ";
		cin>>year;
		system("cls");
		
		system("color 0a");
		cout<<"\n\n\n\t\t\t     Please wait while loading\n\n";
 		char a=177, b=219;
	 	cout<<"\t\t\t\t";
 		for (int i=0;i<=15;i++)
 		cout<<a;
 		cout<<"\r";
 		cout<<"\t\t\t\t";
		for (int i=0;i<=15;i++)
		{
			cout<<b;
			Sleep(500);
		}
	system("cls");
	}

	if(input==1)
	{
	   	COORD coord={30,10};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    	
   		system("color 0a");
		cout<<"\n\n\n\t\t\t    Importing Time Please Wait\n\n";
 		char c=177, b=219;
 		cout<<"\t\t\t\t";
 		for (int i=0;i<=15;i++)
 		cout<<c;
 		cout<<"\r";
 		cout<<"\t\t\t\t";
 		for (int i=0;i<=15;i++)
 		{
  			cout<<b;
  			Sleep(500);
	 	}
		system("cls");
   	
		SYSTEMTIME a;
		GetLocalTime(&a);
		//for date
		day=a.wDay;
		month=a.wMonth;
		year=a.wYear;
		//for time
		hr=a.wHour;
		min=a.wMinute;
		sec=a.wSecond;
		if(hr>12)
		{
			am_pm="pm";
		}
		if(hr<12)
		{
			am_pm="am";
		}
		for(;;)
		{
			PCONSOLE_FONT_INFOEX console_info = new CONSOLE_FONT_INFOEX;
    		console_info->cbSize = sizeof(CONSOLE_FONT_INFOEX);
			GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, console_info);
			console_info->dwFontSize.X = 8; //default 8
    		console_info->dwFontSize.Y = 18; //default 12 
    		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, console_info);
    	
			COORD coord={30,10};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"----------------------";
		
			coord={30,11};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"Time = "<<hr<<" : "<<min<<" : "<<sec<<" "<<am_pm;
		
			coord={30,12};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"Date = "<<day<<" / "<<month<<" / "<<year;
		
			coord={30,13};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"----------------------";
			sec++;
		
			if(sec==59)
			{
				min++;
				sec=00;
			}
			
			if(min==60)
			{
			 	hr++;
				min=00;
				sec=00;
			}
		
			if(hr>12)
			{
		 		hr=hr-12;
			}
		 
			if(hr==12 && min==0 && sec==0 && am_pm=="pm")
			{
				am_pm="am";
			}
		
			else if(hr==12 && min==0 && sec==0 && am_pm=="am")
			{
				am_pm="pm";
			}
		
			if(hr==12 && min==0 && sec==0 && am_pm=="am")
			{
				day++;
			}
			
			if(day==32 && (month==1||month==3||month==5||month==7||month==8||month==10||month==12))
			{
				month++;
				day=1;
			} 
		
			if(day==31 && (month==4||month==6||month==9||month==11))
			{
				month++;
				day=1;
			}
		
			if(day==29 && month==2)
			{
				month++;
				day=1;
			}
		
			if(day==1 && month==13)
			{
				year++;
				month=1;
				day=1;
				coord={30,15};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			}
			
			if(day==1 && month==1)
			{	
				coord={30,15};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
				cout<<"<--- HAPPY NEW YEAR --->";
			}
			coord={15,17};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"PROJECT BY : Muhammad Saqlain";
		
			Sleep(1000);
			system("cls");
		}
	}

	if(input==2)
	{
		PCONSOLE_FONT_INFOEX console_info = new CONSOLE_FONT_INFOEX;
    	console_info->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, console_info);
		console_info->dwFontSize.X = 8; //default 8
    	console_info->dwFontSize.Y = 18; //default 12 
    	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, console_info);
    
		for(;;)
		{
			COORD coord={30,10};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"----------------------";
		
			coord={30,11};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"Time = "<<hr<<" : "<<min<<" : "<<sec<<" "<<am_pm;
		
			coord={30,12};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"Date = "<<day<<" / "<<month<<" / "<<year;
		
			coord={30,13};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"----------------------";
			sec++;
		
			if(sec==59)
			{
				min++;
				sec=00;
			}
			
			if(min==60)
			{
			 	hr++;
				min=00;
				sec=00;
			}
		
			if(hr==13)
			{
		 		hr=1;
				min=00;
				sec=00;
			}
		 
			if(hr==12 && min==0 && sec==0 && am_pm=="pm")
			{
				am_pm="am";
			}
		
			else if(hr==12 && min==0 && sec==0 && am_pm=="am")
			{
				am_pm="pm";
			}
		
			if(hr==12 && min==0 && sec==0 && am_pm=="am")
			{
				day++;
			}
			
			if(day==32 && (month==1||month==3||month==5||month==7||month==8||month==10||month==12))
			{
				month++;
				day=1;
			} 
		
			if(day==31 && (month==4||month==6||month==9||month==11))
			{
				month++;
				day=1;
			}
		
			if(day==29 && month==2)
			{
				month++;
				day=1;
			}
		
			if(day==1 && month==13)
			{
				year++;
				month=1;
				day=1;
				coord={30,15};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			}
			
			if(day==1 && month==1)
			{	
				coord={30,15};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
				cout<<"<--- HAPPY NEW YEAR --->";
			}
			coord={15,17};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
			cout<<"PROJECT BY : Muhammad Saqlain";
		
			Sleep(1000);
			system("cls");
		}
	}
}
