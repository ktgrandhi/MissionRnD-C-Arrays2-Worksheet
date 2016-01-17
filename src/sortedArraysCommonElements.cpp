/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int CompDate(char *date1, char *date2)
{
	int index;
	for (index = 0; index < 10; index++)
	{
		if (date1[index] != date2[index])
			return 0;
	}
	return 1;
}
int Greater(char *date1, char *date2) {

	int index;
	for (index = 0; index < 10; index++)
	{
		if (index == 2 || index == 5)
		{
			if (date1[index] != '-' || date2[index] != '-')
				return -1;
		}
		else
		{
			if (date1[index]<'0' || date1[index]>'9' || date2[index]<'0' || date2[index]>'9')
				return -1;
		}
	}

	for (index = 6; index < 10; index++)
	{
		if (date1[index]>date2[index])
			return 2;
		else
		{
			if (date1[index] < date2[index])
				return 1;
		}
	}
	for (index = 3; index < 5; index++)
	{
		if (date1[index]>date2[index])
			return 2;
		else
		{
			if (date1[index] < date2[index])
				return 1;
		}
	}
	for (index = 0; index < 2; index++)
	{
		if (date1[index]>date2[index])
			return 2;
		else
		{
			if (date1[index] < date2[index])
				return 1;
		}
	}
	return 0;

}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int index, Aindex, Bindex, innerIndex = 0, resultIndex = 0;
	struct transaction *Result;
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;
	for (index = 0; index < ALen; index++)
	{
		if (Greater(A[index].date, B[BLen - 1].date) == 2)
			break;
	}
	Aindex = index;
	for (index = 0; index < BLen; index++)
	{
		if (Greater(B[index].date, A[ALen - 1].date) == 2)
			break;
	}
	Bindex = index;
	if (Aindex <= 0 || Bindex <= 0)
		return NULL;
	if (Aindex >= Bindex)
	{
		Result = (struct transaction *)malloc(sizeof(struct transaction)*Aindex);
		for (index = 0; index < Bindex; index++)
		{
			for (; innerIndex < ALen; innerIndex++)
			{
				if (CompDate(B[index].date, A[innerIndex].date) == 1)
				{
					Result[resultIndex++] = B[index];
					break;
				}
			}
		}
	}
	else
	{
		Result = (struct transaction *)malloc(sizeof(struct transaction)*Bindex);
		for (index = 0; index < Aindex; index++)
		{
			for (; innerIndex < BLen; innerIndex++)
			{
				if (CompDate(A[index].date, B[innerIndex].date) == 1)
				{
					Result[resultIndex++] = A[index];
					break;
				}
			}
		}
	}
	return Result;

}