#pragma once
#include <exception>

class IntArr {
private:
	int m_length = 0;
	int* m_data = 0;

public:
	IntArr() = default;
	IntArr(int length);
	IntArr(const IntArr& a);

	~IntArr() {
		delete[] m_data;
	}

	IntArr& operator = (const IntArr& a);

	void erase();

	int& operator[](int index);

	int getLength() const;

	void reallocate(int newLength);

	void resize(int newLength);

	void insertBefore(int value, int index);

	void remove(int index);

	void insertAtBeginning(int value);

	void insertAtEnd(int value);
	
};