
#include "BoolVector.h"
#include <iostream>
using namespace std;
BoolVector::BoolVector(void)
{
	m_vector = NIL;
	m_size = 0;
	m_lastError = no_error;
}
BoolVector::BoolVector(int size, ...)
{
	m_vector = new int[size];
	m_size = size;
	int* marker = &size;
	marker++;
	while (size != 0)
	{
		m_vector[m_size-size] = *marker;
		marker++;
		size--;
	}
	m_lastError = no_error;
}
BoolVector::~BoolVector(void)
{
	delete [] m_vector;
}
int BoolVector::getLastError(void)
{
	int vp = m_lastError;
	m_lastError = no_error;
	return vp;
}
int BoolVector::getSize(void)
{
	return m_size;
}
int BoolVector::operator[](int index)
{
	if (index<0 || index>m_size-1)
	{
		m_lastError = exit_array;
		return NULL;
	}
	return m_vector[index];
}
void BoolVector::print(void)
{
	for (int i = 0; i < m_size; i++) 
		cout << m_vector[i]<< " ";

}

int BoolVector::sum(void)
{
	int s = 0;
	for (int i = 0; i < m_size; i++) s += m_vector[i];
	return s;
}

int BoolVector::product(void)
{
	int p = 1;
	for (int i = 0; i < m_size; i++) p *= m_vector[i];
	return p;
}

//////////////////////////////////////////////

void BoolVector::con(BoolVector& n )
{

	for (int i = 0; i < m_size && i<n.m_size ; i++) 
		m_vector[i] = (m_vector[i] & n.m_vector[i]);
}

void BoolVector::dis(BoolVector& n )	
{

	for (int i = 0; i < m_size && i<n.m_size ; i++) 
		m_vector[i] = (m_vector[i] || n.m_vector[i]);
}


int BoolVector::count(void)//pods4et 1 i 0
{
	int a = 0, b = 0;
	for (int i = 0; i < m_size; i++)
	{	if(m_vector[i]==0)
	a++;
	else{
		if(m_vector[i] == 1)
			b++;}
	}
	return b ;	
}

void BoolVector::change()//otricanie vektorov
{
	for(int i = 0; i< m_size; i++)
		if (m_vector[i] == 0){
			m_vector[i] = 1;}
		else{

			if (m_vector[i] == 1)
			{m_vector[i] = 0;}}
}



int BoolVector::equal(BoolVector& m)//sravnenie vektorov
{
	for(int i = 0; i < m_size;)
	{if (m_vector[i] == m.m_vector[i])
	i++;
	else{
		return 0;}}
	return *m_vector;
}

