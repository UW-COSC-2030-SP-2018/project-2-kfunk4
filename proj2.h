// proj2.h
// header file for project 2  
// Kelby Funk
// project 2
// COSC 2030

#include<vector>
using std::vector;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;
using std::stoi;


void merge(int vec1[], int left, int mid, int right);

/* ------------------- Code I used from lab07 for QuickSort ------------------------------ */
/* ------------------- References included for code from lab07 --------------------------- */

// swaps two values
// code from https://www.geeksforgeeks.org/quick-sort/
void swap(double *xp, double *yp)
{
	double temp = *xp;
	*xp = *yp;
	*yp = temp;
	return;
}

// partitions the vector
// code from https://www.geeksforgeeks.org/quick-sort/
int partition(vector<double>& vec1, int low, int high)
{
	double pivot = vec1[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (vec1[j] <= pivot)
		{
			i++;
			swap(&vec1[i], &vec1[j]);
		}
	}
	swap(&vec1[i + 1], &vec1[high]);
	return (i + 1);
}

// return a sorted vector of doubles
// used code from https://www.geeksforgeeks.org/quick-sort/
vector<double> quickSort(vector<double>& vec1, int low, int high)
{
	if (low < high)
	{
		int pi = partition(vec1, low, high);
		quickSort(vec1, low, pi - 1);
		quickSort(vec1, pi + 1, high);
	}
	return vec1;
}

/* ------------------------------ End of code I used for lab07 --------------------------------- */

/* ------------------------------ Code for Binary Search --------------------------------------- */
/* ---------------------- Got help from Rafer and Professor Borowczak -------------------------- */
/* --------------- referenced https://www.geeksforgeeks.org/binary-search/ --------------------- */
/* ------------ because my original code would break trying to find items not in vector -------- */

// finds the middle value between two given numbers
// modified code a little bit, referenced geeksforgeeks
int middle(int low, int high)
{
	int size = high - low;
	int middle;

	middle = low + ((high - low) / 2);
	
	return middle;
}

/* ------------------------ my explanation of how binary search works --------------------------- */
/* binary search will take in a vector and find the mid point, it will check to see if this value
* is the value it is looking for. If it is not it will check to see if the value is greater than or less
* than the search value. If it is smaller it will take the left half of the vector and keep dividing it in 
* half and seeing if the mid value is equal to the search value and do the same thing if it is larger with the
* upper half. If it gets to only one element it will check the value if it matches it will return true if not
* it then returns false because it did not successfully find the element.
*/

// recursive part of binary search, will search vector for given value
bool binarySearch(const vector<double>& vec1, int low, int high, double searchValue)
{
	bool found = false;
	int mid = middle(low, high);
	// referenced geeksforgeeks for this check
	if (high >= low)
	{
		if (vec1.at(mid) == searchValue)
		{
			found = true;
			return found;
		}
		else if (vec1.at(mid) > searchValue)
		{
			found = binarySearch(vec1, low, mid - 1, searchValue);
			return found;
		}

		else if (vec1.at(mid) < searchValue)
		{
			found = binarySearch(vec1, mid + 1, high, searchValue);
			return found;
		}
		else
			return found;
	}
	return found;
}

/* ------------------------------- End Binary Search ---------------------------------- */

/* ------------------------------- Code for Merge Sort -------------------------------- */
/* ------------- Recieved help from Professor Borowczak and TA Rafer ------------------ */
/* -------- looked at https://www.youtube.com/watch?v=KF2j-9iSf4Q for merge ----------- */
/* ------------------------------- didn't use too much -------------------------------- */
/* -------referenced https://www.geeksforgeeks.org/merge-sort/ which helped a lot ----- */

// sorts an array, this part divides the array
// used pseduocode from sheet given by Professor Borowczak in class
// used https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
// for how to pass an array to a function
// used https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
// for how to return an array from a function
void mergeSort(int vec1[], int left, int right)
{
	int mid;
	if (right > left)
	{
		mid = (left + right) / 2;
		mergeSort(vec1, left, mid);
		mergeSort(vec1, mid + 1, right);
		merge(vec1, left, mid, right);
	}
}
/* ----------------- my explanation of how merge and merge sort works --------------- */
/* above merge goes through the array, it first finds the mid point of the array and then it 
* goes through the left half of the array sub dividing it into smaller and smaller pieces,
* it then goes through the right side of the array working its way back up. Basically it is
* doing a pre order traversal through the array. Referenced a few online sources about pre order traversal.
* It then merges everything, to do this it first creates two temporary sub arrays. The portion of the main array
* that is passed into the argument will fill these two temporary arrays. It finds the size of the left portion of the
* array and the right side. It fills the two temporary arrays with this data from the main array that is passed in.
* Next it has a while loop that makes sure that the left index and right index have not passed the size of these temporary
* arrays that were made or essentially that it does not go out of bounds from the main array that is passed in.
* In the loop it then compares the elements from the two temp arrays and depending on which one is smaller it
* puts the smaller element into the main array, and increments the index. Lastly it goes through the main array and
* copies the elements from the two temp arrays just in case it missed any elements.
*/

// part of merge sort that sorts the array
// looked at https://www.youtube.com/watch?v=KF2j-9iSf4Q but didn't help too much
// referenced https://www.geeksforgeeks.org/merge-sort/ which helped a lot
void merge(int vec1[], int left, int mid, int right)
{
	// dynamic array, help from Professor Borowczak
	int * leftArray = NULL;
	int * rightArray = NULL;
	int leftIndex = 0;
	int rightIndex = 0;
	// got size of temp arrays, referenced geeks for geeks for this
	int leftArraySize = mid - left + 1;
	int rightArraySize = right - mid;
	int mergeIndex = left;

	// create two temp arrays, referenced geeksforgeeks for this
	leftArray = new int[leftArraySize];
	rightArray = new int[rightArraySize];

	// get data into temp arrays, referenced geeksforgeeks for this
	for (int i = 0; i < leftArraySize; i++)
		leftArray[i] = vec1[left + i];
	for (int j = 0; j < rightArraySize; j++)
		rightArray[j] = vec1[mid + 1 + j];

 	while (leftIndex < leftArraySize && rightIndex < rightArraySize)
	{
		
		// checking to see if left sub array is less than the other
		// if so put this value into the main array, referenced geeksforgeeks for this
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			vec1[mergeIndex] = leftArray[leftIndex];
			leftIndex++;
			mergeIndex++;
		}
		// checking to see if right sub array index is less than left sub array index
		// if so put that value into the main array, referenced geeksforgeeks for this
		else
		{
			vec1[mergeIndex] = rightArray[rightIndex];
			rightIndex++;
			mergeIndex++;
		}
	}

	// get any missing elements into main array, referenced geeksforgeeks for this
	while (leftIndex < leftArraySize)
	{
		vec1[mergeIndex] = leftArray[leftIndex];
		leftIndex++;
		mergeIndex++;
	}

	// get any missing elements into main array, referenced geeksforgeeks for this
	while (rightIndex < rightArraySize)
	{
		vec1[mergeIndex] = rightArray[rightIndex];
		rightIndex++;
		mergeIndex++;
	}
}

/* ------------------------------- End Merge Sort -------------------------------------- */

/* ---------------------------- Code for Hash Function --------------------------------- */
/* --------------------- Got help from Professor Borowczak ----------------------------- */
/* -------------------- Refernced hashing slides from class ---------------------------- */

// hashes string into an int 
// referenced hashing slides from class for this function
int hashString(string s, int tableSize)
{
	int hash = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		hash = ((hash + s.at(i)) << 5) % tableSize;
	}

	return hash;
}

/* --------------------------------- End Hash Function ----------------------------------- */