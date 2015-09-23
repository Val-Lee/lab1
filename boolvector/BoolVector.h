#pragma once
#define conjunction con
#define disjunction dis
#define NIL 0x00000000
class BoolVector
{
private:
	int m_size;
	int* m_vector;
	int m_lastError;
public:
	enum {no_error, memory_limit, exit_array};
	BoolVector(void);
	BoolVector(int size, ...);
	~BoolVector(void);
	int getLastError(void);
	int getSize(void);
	int product(void);
	int operator[](int);
	void print(void);
	int sum(void);
	void con(BoolVector&);
	void dis(BoolVector&);
	int count(void);
	void change();
	int equal(BoolVector&);
	void spec(int, int );
};