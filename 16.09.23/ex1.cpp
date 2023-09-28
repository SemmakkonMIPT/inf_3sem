#include <iostream>

void print(int n){
    std::cout << n << '\n';
}

void printArr(int *arr, int size){
    for(int i = 0; i<size; i++)
    {
        std::cout << arr[i];
    }
    std::cout << '\n';
}

int findMax(int *arr, int size){
    int ans = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i]!=0){
            ans = i-1;
        }
    }
    return ans;
}

auto input(){
    int i{};
    std::cin >> i;
    return i;
}

int makeColac(int n, int *colac, int size){
    if(colac[n-1] != 0)
    {
        //print(n);
        return colac[n-1];
    }
    else
    {
        if(n%2 == 0){
            auto l = makeColac(n/2, colac, size) + 1;
            colac[n-1] = l;
            //print(n);
            return l;
        }
        else{
            auto l = makeColac(n*3+1, colac, size) + 1;
            colac[n-1] = l;
            //print(n);
            return l;
        }
        
    }
    
    
}

int main()
{
    //auto n = input();
    int size = 100000000;
	int *colac = new int[size]{};
    colac[0] = 1;
    //print(makeColac(n, colac, size));
    //printArr(colac, size);
    int maxN = 1;
    int maxL = 1;
    for(int i = 2; i <=10000; i++)
    {
        auto x = makeColac(i, colac, size);
        //print(i);
        if(x > maxL)
        {
            //print(i);
            //print(x);
            
            maxL = x;
            maxN = i;
        }
    }
    std::cout << "The largest sequence with the number: " << maxN << "\n";
    std::cout << "Sequence length: " << maxL << "\n";
    std::cout << "The largest number used: " << findMax(colac, size) << "\n";
    //print(maxN);
    //print(maxL);
    //print(findMax(colac, size));
	return 0;
} 