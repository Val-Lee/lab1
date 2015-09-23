// lab2v2.cpp: определяет точку входа для консольного приложения.
//


#include "BoolVector.h"
#include <iostream>
using namespace std;


int main()
{
	const int N=2;
	BoolVector v[N]={BoolVector(3, 1, 1, 1), BoolVector(3, 1, 1, 1)};




	for(int i=0; i<N; i++)
	{cout<<"Vector #"<<i<<": ";
	v[i].print();
	cout<<endl;}

	cout<<"===========================\n";
		int a;
	cout<<"Enter numbers of 0: "; cin>>a;
	cout<<endl;
	for(int i=0; i<N;i++){
		if (v[i].count() == a){
			v[i].print();
			cout<<endl;}
		else{
			cout<<"Is not the same number of zeros\n";}}


	if(v[0].equal(v[1]) == 1){
		cout<<"Vectors are equal \n";}
	else{
		cout<<"Vectors are not equal \n";}

	cout<<"Conjunction (v1 & v2): ";
	v[0].con(v[1]);
	v[0].print();
	cout<<"\nDisjunction (v1 || v2): ";
	v[0].dis(v[1]);
	v[0].print();
	cout<<endl;
	cout<<"Change v2: ";
	v[1].change();
	v[1].print();
	cout<<endl;





	return 0;
}

