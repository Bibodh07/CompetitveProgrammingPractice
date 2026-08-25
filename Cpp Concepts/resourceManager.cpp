#include <iostream>
#include <vector>


class IntArray {

    private:

        int arraySize;
        int *data;



    public:

        IntArray(int size)
        :arraySize{size},  data{new int[arraySize]}
        {
           
        }


        int& operator[](int index)
        {
            return data[index];
        }

        int getSize() const
        {
            return arraySize;
        }


        

        ~IntArray()
        {
            delete[] data;
        }



};


class IntArrayV2 {
private:
    int arraySize;
    std::unique_ptr<int[]> data;   // <-- the key change

public:
    IntArrayV2(int size)
        : arraySize{size}, data{std::make_unique<int[]>(size)}
    {
    }

    int& operator[](int index)
    {
            return data[index];
    }

    int getSize() const
    {
        return arraySize;
    }

    // No destructors needed because uniqueptr is smart.
};





int main() {

    return 0;
}