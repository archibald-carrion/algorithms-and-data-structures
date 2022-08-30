#include <iostream>

void towerOfHanoi(int disk, char fromRod, char toRod, char AuxRod){
    if(disk!=0){
        towerOfHanoi(disk-1, fromRod, AuxRod, toRod);
        std::cout<<"Move disk "<<disk<<" from rod "<<fromRod<< " to rod " <<toRod<<std::endl; 
        towerOfHanoi(disk-1, AuxRod, toRod, fromRod); 
    }
}

int main(){
    int cantityDisks = 4;
    towerOfHanoi(cantityDisks, 'A', 'B', 'C');
    return 0;
}