#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

template <class elemType>
class orderedArrayListType : public arrayListType<elemType>
{
public:
    void insertOrd(const elemType &);

    int binarySearchWithNumberOfComparison(const elemType &item);

    int sequentialSearchWithNumberOfComparison(const elemType &item);

    orderedArrayListType(int size = 100);

    int noOfComparisons() const;
    void initializeNoOfComparisons();

private:
    int comparisons;
};

template <class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType &item)
{
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    if (this->length == 0)
    {
        this->list[0] = item;
        this->length++;
    }
    else if (this->length == this->maxSize)
        cerr << "Cannot insert into a full list." << endl;
    else
    {
        while (first <= last && !found)
        {
            mid = (first + last) / 2;

            if (this->list[mid] == item)
                found = true;
            else if (this->list[mid] > item)
                last = mid - 1;
            else
                first = mid + 1;
        } // end while

        if (found)
            cerr << "The insert item is already in the list. "
                 << "Duplicates are not allowed." << endl;
        else
        {
            if (this->list[mid] < item)
                mid++;

            this->insertAt(mid, item);
        }
    }
} // end insertOrd

template <class elemType>
int orderedArrayListType<elemType>::binarySearchWithNumberOfComparison(const elemType &item)
{
    int count;
    int mid;
    int first = 0;
    int last = this->length - 1;
    // std::cout << "Implement bineary search with the number of comparisons" << std::endl;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (this->list[mid] < item)
        {
            count++;
            first = mid + 1;
        }
        else if (this->list[mid] == item)
        {
            count++;
            cout << "\nThe item found at " << mid + 1;
            cout << " number of comparison : " << count;
            break;
        }
        else if (this->list[mid] > item)
            last = mid - 1;
        else
        {
            cout << "\nItem not in the list. " << endl;
            cout << endl;
        }
    }

    return -1;
}

template <class elemType>
int orderedArrayListType<elemType>::sequentialSearchWithNumberOfComparison(const elemType &item)
{
    int count;
    // std::cout << "Implement sequential search function and count number of comparisons " << std::endl;
    for (int i = 0; i < this->length; i++)
    {
        if (this->list[i] == item)
        {
            count++;
            cout << "Item found at " << i + 1 << endl;
            cout << "Number of comparisons " << count << endl;
            break;
        }
        if (i == this->length)
        {
            count++;
            cout << "Item not in the list." << endl;
            cout << "Number of comparisons " << count << endl;
        }
    }

    return -1;
}

template <class elemType>
int orderedArrayListType<elemType>::noOfComparisons() const
{
    return comparisons;
}

template <class elemType>
void orderedArrayListType<elemType>::initializeNoOfComparisons()
{
    comparisons = 0;
}

template <class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
    : arrayListType<elemType>(size)
{
    comparisons = 0;
}

#endif