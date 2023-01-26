#include <iostream>

using namespace std;


class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
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

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

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
