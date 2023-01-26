/*****************************************************************************
*                    
*  Author:           Sudhir Ray
*  Email:            raysudhir30@gmail.com/ sray0228@my.msutexas.edu  
*  Label:            A03
*  Title:            Basic Project Organization
*  Course:           CMPS 3013
*  Semester:         Spring 2023
* 
*  Description:
*        This program implements the concept of circular array queue. The program has a push function to add items in the queue 
*        as well as a pop function to remove items from the queue. The program also prints all the items in the queue at the end.
*       
* 
*  Usage:
*       - create instance of CircularArrayQue
*       - push function to add item into the queue
*       - pop function to remove item from the queue
*  
* 
*  Files:           
*        main.cpp      :        driver program 
*****************************************************************************/


#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      This is a class that demontrates the concept of circular array queue. It has public methods like push and pop 
 *      to add and remove items from the queue simultaneously. 
 * Public Methods:
 *                              CircularArrayQue()
 *                              CircularArrayQue(int)
 *          void                Push(int item)
 *          int                 Pop()
 *          friend ostream      &operator << (ostream &, const CircularArrayQue)            
 * 
 * Private Methods:
 *          void                init(int size = 0)
 *          bool                Full()
 * 
 * Usage: 
 * 
 *  CircularArrayQue()  // creates an instance of CircularArrayQue
 *  push (int item)     // inserts item in the queue 
 *  pop ()              // removes item from the queue
 *
 */
class CircularArrayQue {
private:
    int *Container;    //pointer pointing to the items in the list
    int Front;         // item at the front of the queue
    int Rear;          // item at the back of the queue
    int QueSize;       // size of the queue
    int CurrentSize;   // the current size of the queue
    
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
    
    /**
     * Public : push
     * 
     * Description:
     *      The function adds item in the queue
     * 
     * Params:
     *      int     :  the item to be added in the queue.
     * 
     * Returns:
     *      void
     */


    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
    
    /**
     * Public : pop
     * 
     * Description:
     *      The function removes item from the front of the queue.
     * 
     * Params:
     *     None
     * 
     * Returns:
     *      int : the item that has been removed from the queue.
     */


    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    
    
    
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5); //creating an instance of the queue

    

    C1.Push(1); //pushing items into the queue
    C1.Push(2);
    C1.Push(3);
    
    cout << C1 << endl; //printing items in queue

    


}
