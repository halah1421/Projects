#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono> 

using namespace std::chrono;
using namespace std;
#define size 50

void naive(int mat1[][size], int mat2[][size], int res[][size]){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = 0;
            for (int k = 0; k < size; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }}
    cout << "\n\n*************** \n";
    cout << "Result of multiplication matrix : "; //print loop
    cout << "\n\n*************** \n\n"; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }}

void strassens(int a[][size], int b[][size], int row, int col, int c1){
   int c[size][size];
    //input 0 for all values of c, in order to remove
    //the garbage values assigned earlier
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
           c[i][j]=0;
        }}
    //we apply the same formula as above
   for(int i=0; i<row; i++){
       for(int j=0; j<col; j++){
            for(int k=0; k<c1; k++){ //columns of first matrix || rows of second matrix
                c[i][j]+=a[i][k]*b[k][j];
            } }}
    cout << "\n\n*************** \n";
    cout << "Result of multiplication matrix :"; //print loop
    cout << "\n\n*************** \n\n"; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            cout << c[i][j] << " "; }
        cout << "\n";
    }}

void write(int Array[size][size]) {
    ofstream put("Array.txt");
    for (int i = 0; i < size; i++) { //loop to put into array
        for (int j = 0; j < size; j++) {
            put << Array[i][j]<<" ";
        }
    }
    put.close(); }

void read(int Array[size][size]) {
    ifstream take;
    take.open("Array.txt"); //creating an object 
    if (take.fail()) {
        cerr << "file creation has failed" << endl;
        exit(1);
    }
    while (!take.eof()) {
        for (int i = 0; i < size; i++) { //loop to put into array
            for (int j = 0; j < size; j++) {
                take >> Array[i][j];
     }}}}

int main(){ 
    cout << "\n\t\t\t\t\t\t---- Matrix Multiplication ----\n";
    int Array1[size][size];
    int Array2[size][size];
    int result[size][size]; // To store result
    int row1 = size ;
    int col1 = size;
    int row2 = size ;
    int col2 = size ;

    //Array1
    for(int i=0;i<size;i++){ //loop to put into array
        for (int j=0;j<size;j++){
            Array1[i][j] = (rand()%10);
        }}

    //write inside file 
    write(Array1);
    //read from file function
    read(Array1); 
    cout << "\n\n*************** \n";
    cout << " Matrix 1 : ";
     cout << "\n\n*************** \n\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << Array1[i][j] << " ";
        cout << "\n";
    }

    ///Array 2
    for(int i=0;i<size;i++){ //loop to put into array
        for (int j=0;j<size;j++){
            Array2[i][j] = (rand()%10);
        }}

    //write inside file 
    write(Array2);
    //read from file function
    read(Array2); 
    
    cout << "\n\n*************** \n";
    cout << " Matrix 2 : ";
    cout << "\n\n*************** \n\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << Array2[i][j] << " ";
        cout << "\n";
    }
     int choice;
     do{
    cout << "\n\n********************************************************************* \n";
    cout<<"\nChoose what you want type of matrix multiplication\n1-naïve matrix multiplication.\n2-Strassen matrix multiplication..\n3-Exit\n";
    cout << "\n\n********************************************************************* \n";
    cin>>choice;
    switch(choice){
        case 1 :{
            auto begin = std::chrono::high_resolution_clock::now();//start counting time using chrono library (to compute time)
            naive(Array1, Array2, result); //calling on function to multiply 
            auto end = std::chrono::high_resolution_clock::now(); //time when operation ends
            auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); //subtract start time from end time and store it in (time) 
            cout << "\n\nTotal execution Time naïve matrix ms is : " << time.count() << "\n"; //print it 
            break;
        }
        case 2 :{
            auto begin2 = high_resolution_clock::now();//start counting time using chrono library (to compute time complexity)
	        strassens(Array1, Array2, row1, col2, col1);//doing the sort during counting time 
	        auto end2 = high_resolution_clock::now();//time when sort ends 
            auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2); //subtract start time from end time and store it in (time) 
            cout << "\n\nTotal execution Time Strassen matrix ms is " << time2.count() << "\n"; //print it 
            break;
        }
        case 3 : cout << "EXIT .. Good buy .\n";break;
        default : cout << "INVALID CHOICE PLEASE ENTER AGAIN .. \n";break;}
    } while (choice!=3);
    return 0;
}