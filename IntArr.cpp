#include "IntArr.h"
#include "bad.h"

IntArr::IntArr(int length) : m_length(length) {
	if (length <= 0) {
		throw bad_range();
	}
	else {
		m_data = new int[length];
	}
}
IntArr::IntArr(const IntArr& a) {
	reallocate(a.getLength());

	for (int index = 0; index < m_length; ++index) {
		m_data[index] = a.m_data[index];
	}
}

IntArr& IntArr::operator = (const IntArr& a) {//!!
	if (&a == this) {
		return *this;
	}

	reallocate(a.getLength());

	for (int index = 0; index < m_length; ++index) {
		m_data[index] = a.m_data[index];
	}

	return *this;
}

void IntArr::erase() {
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& IntArr::operator[](int index) {//!!
	if (index >= 0 && index < m_length) {
		return m_data[index];
	}
}

int IntArr::getLength() const {
	return m_length;
}

void IntArr::reallocate(int newLength) {
	erase();

	if (newLength <= 0) {
		return;
	}

	m_data = new int[newLength];
	m_length = newLength;
}

void IntArr::resize(int newLength) {
	if (newLength == m_length) {
		return;
	}

	if (newLength <= 0) {
		erase();
		return;
	}

	int* data = new int[newLength];

	if (m_length > 0) {
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;

		for (int index = 0; index < elementsToCopy; ++index) {
			data[index] = m_data[index];
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}
}

void IntArr::insertBefore(int value, int index) {
	if (index <= 0 && index >= m_length) {
		throw bad_length();
	};

	int* data = new int[m_length + 1];

	for (int before = 0; before < index; ++before) {
		data[before] = m_data[before];
	}

	data[index] = value;

	for (int after = index; after < m_length; ++after) {
		data[after + 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntArr::remove(int index) {
	if (index <= 0 && index >= m_length) {
		throw bad_length();
	};

	if (m_length == 1) {
		erase();
		return;
	}

	int* data = new int[m_length - 1];

	for (int before = 0; before < index; ++before) {
		data[before] = m_data[before];
	}

	for (int after = index + 1; after < m_length; ++after) {
		data[after - 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	--m_length;
}

void IntArr::insertAtBeginning(int value) {
	insertBefore(value, 0);
}

void IntArr::insertAtEnd(int value) {
	insertBefore(value, m_length);
}