#ifndef DATE_H
#define DATE_H
#include <string>
#include <sstream>

using namespace std;

class aDate
{
	private:
		int day, month, year;
		
		string to_string(int n){
			ostringstream stm ;
	        stm << n ;
	        return stm.str() ;
		}
		
		string monthInWords(int m){
			string Month;
			
			switch(m){
				case 1:
					Month = "January";
					break;
				case 2:
					Month = "February";
					break;
				case 3:
					Month = "March";
					break;
				case 4:
					Month = "April";
					break;
				case 5:
					Month = "May";
					break;
				case 6:
					Month = "June";
					break;
				case 7:
					Month = "July";
					break;
				case 8:
					Month = "August";
					break;
				case 9:
					Month = "September";
					break;
				case 10:
					Month = "October";
					break;
				case 11:
					Month = "November";
					break;
				case 12:
					Month = "December";
					break;
				default:
					Month = "error";
					break;
			}
			return Month;
		}
		
	public:
		
		int getDay(){
			return this->day;
		}
		void setDay(int day){
			this->day = day;
		}
		
		void setDate(int month, int day, int year){
			if(day > 0 && day <= 31){
				this->day = day;
			}else{
				this->day = 0;
			}
			
			if(month > 0 && month <= 12){
				this->month = month;
			}else{
				this->month = 0;
			}
			
			this->year = year;
		};
		
		//Validate the day		
		int validateDay(int day){
			if(day > 0 && day <= 31){
				this->day = day;
			}else{
				this->day = 0;
			}
			
			return this->day;
		};
		//Validate the month
		int validateMonth(int day){
			if(month > 0 && month <= 12){
				this->month = month;
			}else{
				this->month = 0;
			}
			
			return this->month;
		};
		
		
		string shortDate(){
			string date, month = this->monthInWords(this->month);
			if((this->validateDay(this->day) == 0) || (this->validateMonth(this->month) == 0)  || month == "error"){
				date = "Invalid Date Entered";
			}else{
				date = to_string(this->month) + "/" + to_string(this->day) + "/" + to_string(this->year);
			}
			
			return date;
		}
		
		string LongDate(){
			string date, month = this->monthInWords(this->month);
			if(this->validateDay(this->day) == 0 || this->validateMonth(this->month) == 0 || month == "error"){
				date = "Invalid Date Entered";
			}else{
				date = to_string(this->day) + " " + month + " " + to_string(this->year);
			}
			
			return date;
		}
		
		
		string fullDate(){
			string date, month = this->monthInWords(this->month);
			if(this->validateDay(this->day) == 0 || this->validateMonth(this->month) == 0 || month == "error"){
				date = "Invalid Date Entered";
			}else{
				date = month + " " + to_string(this->day) + ", " + to_string(this->year);
			}
			
			return date;
		}
		
//		Advanced Started Here
		aDate nextDateValidation(aDate d){
			aDate newDate;
			int remainingDays = 0, noMonths = 0;
			//Validate days according to number of days within the months
			if(d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12){
				//These are months with 31 days. So, validate day as 31 day (i.e if it is more than, spilled it to next month
				if(d.day > 31){
					noMonths = d.day / 31;
					remainingDays = d.day % 31;
					newDate.day = remainingDays;
				}else{
					newDate.day = d.day;
				}
				
				if((d.month + noMonths) > 12){
					newDate.month = (d.month + noMonths) % 12;
					newDate.year = d.year + ((d.month + noMonths) / 12);
				}else{
					newDate.month = d.month + noMonths;
					newDate.year = d.year;
				}			
			}else if(d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11){
				//These are months with 28 days. So, validate day as 28 day (i.e if it is more than, spilled it to next month
				if(d.day > 30){
					noMonths = d.day / 30;
					remainingDays = d.day % 30;
					newDate.day = remainingDays;
				}else{
					newDate.day = d.day;
				}
				
				if((d.month + noMonths) > 12){
					newDate.month = (d.month + noMonths) % 12;
					newDate.year = d.year + ((d.month + noMonths) / 12);
				}else{
					newDate.month = d.month + noMonths;
					newDate.year = d.year;
				}
				
			}else if(d.month == 2){
				//These are months with 31 days. So, validate day as 31 day (i.e if it is more than, spilled it to next month
				if(d.day > 28){
					noMonths = d.day / 28;
					remainingDays = d.day % 28;
					newDate.day = remainingDays;
				}else{
					newDate.day = d.day;
				}
				
				if((d.month + noMonths) > 12){
					newDate.month = (d.month + noMonths) % 12;
					newDate.year = d.year + ((d.month + noMonths) / 12);
				}else{
					newDate.month = d.month + noMonths;
					newDate.year = d.year;
				}
			}else{
				newDate = d;	
			}
			return newDate;
		}
		
		//Overloading
			friend aDate operator +(aDate &d, int value);
			friend aDate operator -(aDate &d, int value);
			friend int operator -(aDate &d1, aDate &d2);
			friend aDate operator ++(aDate &d);
			friend aDate operator++(aDate &d, int);
			friend ostream& operator<< (ostream& out, aDate &d);	
			friend istream& operator>> (istream& in, aDate &d);	

	protected:
		
};


	//Freind Functions Content
	aDate operator+(aDate &d, int value){
		aDate newDate = d;
		newDate.setDay(d.getDay() + value);
		newDate = newDate.nextDateValidation(newDate);
		return newDate;
	}
	
	aDate operator-(aDate &d, int value){
		aDate newDate = d;
		newDate.setDay(d.getDay() - value);
		newDate = newDate.nextDateValidation(newDate);
		return newDate;
	}
	
	aDate operator++(aDate &d){
		aDate newDate = d + 1;
		newDate = newDate.nextDateValidation(newDate);
		return newDate;
	}
	
	aDate operator++(aDate &d, int){
		aDate newDate = d + 1;
		newDate = newDate.nextDateValidation(newDate);
		return newDate;
	}
	
	aDate operator--(aDate &d){
		aDate newDate = d - 1;
		newDate = newDate.nextDateValidation(newDate);
		return newDate;
	}
	
	aDate operator--(aDate &d, int){
		aDate newDate = d - 1;
		newDate = newDate.nextDateValidation(newDate);
		return newDate;
	}
	
	int operator -(aDate &d1, aDate &d2){
		int numberOfDays;
		numberOfDays = d1.getDay() - d2.getDay();
	}
	
	ostream& operator<< (ostream& out, aDate &d) {
        out << d.fullDate();
        return out;
    }
    
    istream& operator>> (istream& in, aDate &d){
    	in >> d.day;
    	in >> d.month;
    	in >> d.year;
    	return in;
    }


#endif
