// 1st file
#include <iostream>
#include "orderedArrayListType.h"
using namespace std;

const int SIZE = 1024;

void printListInfo(orderedArrayListType<int> &listInfo);
void fill(orderedArrayListType<int> &listInfo);

int main()
{
        int num;
        int loc;
        orderedArrayListType<int> intList(SIZE);
        fill(intList);

        cout << "intList: " << endl;
        printListInfo(intList);

        cout << "Enter search item: ";
        cin >> num;
        cout << endl;

        cout << "*****Using binary search*****" << endl;

        orderedArrayListType<int> obj;
        obj.binarySearchWithNumberOfComparison(num);

        cout << "*****Using sequential search*****" << endl;

        orderedArrayListType<int> obj1;
        obj.sequentialSearchWithNumberOfComparison(num);

        cout << "hocam implement ettim ama calismiyor nedenini anlayamadim.kod ustunden degerlendirebilir misiniz ?";
        return 0;
}

void printListInfo(orderedArrayListType<int> &listInfo)
{
        cout << "List: ";
        listInfo.print();

        cout << "List Size: " << listInfo.listSize() << endl;
        cout << "Max List Size: " << listInfo.maxListSize() << endl;
}

void fill(orderedArrayListType<int> &listInfo)
{
        int seed = 3;
        int multiplier = 17;
        int addOn = 122;

        while (listInfo.listSize() < SIZE)
        {
                listInfo.insertOrd(seed);
                seed = int((seed * multiplier + addOn) % 100000);
        }
        cout << endl;
}