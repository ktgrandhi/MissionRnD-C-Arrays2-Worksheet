/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int DateCheck(char *date)
{
	int index;
	for (index = 0; index < 11; index++)
	{
		if (index == 2 || index == 5)
			if (date[index] != '-')
				return 1;
			else
			{
				if (date[index] <= '0' || date[index] >= '9')
					return 0;
			}

	}
	return 1;
}
int DateIsGreater(char *refDate, char *TransactionDate)
{
	int index;
	for (index = 6; index < 10; index++)
	{
		if (TransactionDate[index] == refDate[index])
			continue;
		else
		{
			if (TransactionDate[index] < refDate[index])
				return 0;
			else
				return 1;
		}
	}
	for (index = 3; index < 5; index++)
	{
		if (TransactionDate[index] == refDate[index])
			continue;
		else
		{
			if (TransactionDate[index] < refDate[index])
				return 0;
			else
				return 1;
		}
	}
	for (index = 0; index < 3; index++)
	{
		if (TransactionDate[index] == refDate[index])
			continue;
		else
		{
			if (TransactionDate[index] < refDate[index])
				return 0;
			else
				return 1;
		}
	}
	return 0;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int index, count = 0;
	if (Arr == nullptr || len<1)
		return NULL;
	for (index = 0; index < len; index++)
	{
		if (DateCheck(Arr[index].date))
			return -1;
	}
	for (index = 0; index < len; index++)
	{
		if (DateIsGreater(date, Arr[index].date))
			count++;
	}
	return count;
}

