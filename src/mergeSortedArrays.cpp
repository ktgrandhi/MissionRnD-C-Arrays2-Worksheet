/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isOlder(char *date1, char *date2) {

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


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int indexA = 0, indexB = 0, resultIndex = 0, value;
	struct transaction *Result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	if (A == NULL || B == NULL || ALen<0 || BLen<0)
		return NULL;
	while (indexA < ALen&&indexB < BLen)
	{
		value = isOlder(B[indexB].date, A[indexA].date);
		if (value == 2)
		{
			Result[resultIndex++] = A[indexA];
			indexA++;
		}
		else
		{
			if (value == 1)
			{
				Result[resultIndex++] = B[indexB];
				indexB++;
			}
			else
			{
				if (value == 0)
				{
					Result[resultIndex++] = B[indexB];
					Result[resultIndex++] = A[indexA];
					indexA++;
					indexB++;
				}
			}
		}

	}
	for (; indexA < ALen; indexA++)
		Result[resultIndex++] = A[indexA];
	for (; indexB < BLen; indexB++)
		Result[resultIndex++] = B[indexB];
	return Result;
}
