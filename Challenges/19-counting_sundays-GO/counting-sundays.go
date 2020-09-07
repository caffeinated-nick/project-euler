package main

import (
	"fmt"
	// "math"
)

/** 
	- 1 Jan 1900 was a Monday.
	
	- Thirty days has September,
		April, June and November.
		All the rest have thirty-one,
		Saving February alone,
		Which has twenty-eight, rain or shine.
		And on leap years, twenty-nine.

	- A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

	How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

var months = [12]string {
	"jan",
	"feb",
	"mar",
	"apr",
	"may",
	"jun",
	"jul",
	"aug",
	"sep",
	"oct",
	"nov",
	"dec",
}

var daysInMonth = map[string]int {
	"jan" : 31,
	"feb" : 28,
	"mar" : 31,
	"apr" : 30,
	"may" : 31,
	"jun" : 30,
	"jul" : 31,
	"aug" : 31,
	"sep" : 30,
	"oct" : 31,
	"nov" : 30,
	"dec" : 31,
}

var daysOfTheWeek = [7]string {
	"sun",
	"mon",
	"tue",
	"wed",
	"thu",
	"fri",
	"sat",
}
var daysInWeek = 7
var weeksInYear = 52
var daysInYear = 365

var startingYear = 1901;
var endingYear = 2001;

func main() {
	count := calculateStartingSundaysPerYear();
	
	fmt.Printf("Looks like there were %d starting Sundays between %d and %d\n", count, startingYear, endingYear);
	fmt.Println();
}

func calculateStartingSundaysPerYear() (count int) {
	count = 0;
	firstDay := 2; // 1901 started on Tuesday
	for year := startingYear; year < endingYear; year++ {
		fmt.Printf("Looks like the first day of %d was %s\n", year, daysOfTheWeek[firstDay]);
		var startingSundaysForYear, nextFirstDay = getStartingSundaysForYear(firstDay, year);
		fmt.Printf("Looks like the first day of next year will be %s\n", daysOfTheWeek[nextFirstDay]);
		count += startingSundaysForYear;
		firstDay = nextFirstDay;
	}
	return
}

func getStartingSundaysForYear(firstDay, year int) (count, nextFirstDay int) {
	count = 0;
	for month := 0; month < 12; month++ {
		fmt.Printf("The first day of %s %d was %s\n", months[month], year, daysOfTheWeek[firstDay])
		if(firstDay == 0) {
			fmt.Printf("Found a starting Sunday in %s %d\n", months[month], year);
			count++;
		}
		nextFirstDay = getNextMonthStart(firstDay, month, year);
		fmt.Printf("nextFIrstDay: %d\n", nextFirstDay);
		firstDay = nextFirstDay;
	}
	return count, nextFirstDay;
}

func getNextMonthStart(oldFirstDay, month, year int) (int) {
	var newStartDay = oldFirstDay - 1 + daysInMonth[months[month]];
	if (months[month] == "feb" && year % 4 == 0) {
		newStartDay++;
	}
	return interceptArrayOverflow(newStartDay);
}

func interceptArrayOverflow(input int) (int) {	
	for; input >= 6; {
		fmt.Printf("Input: %d\n", input)
		input -= 7;
	}
	return input + 1;
}
