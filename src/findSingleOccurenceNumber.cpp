/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include<stdio.h>
int findSingleOccurenceNumber(int *A, int len) {
	int index = 0, Ref[100] = { 0 };
	if (A == NULL || len<0)
		return -1;
	for (index = 0; index < len; index++)
	{
		Ref[A[index]]++;
	}
	for (index = 0; index < 100; index++)
	{
		if (Ref[index] == 1)
			return index;
	}
	return NULL;
}
