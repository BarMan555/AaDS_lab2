#pragma once
#include <cmath>
#include<iostream>
#include<stdexcept>
#include "summand.cpp"


template<class Data>
class LinkedList {
	struct Node
	{
		Data data;
		Node* next;
	};

	Node* _head = nullptr;

public:

	LinkedList();
	LinkedList(const LinkedList<Data>& other);
	~LinkedList();

	LinkedList<Data> operator+(const LinkedList<Data>& second) const;
	LinkedList<Data>& operator+=(const LinkedList<Data>& second);
	Data& operator[](const int index);
	Data operator[](const int index) const;

	void push_tail(const Data& data);
	void push_tail(const LinkedList<Data> list);
	void push_head(const Data& data);
	void push_head(const LinkedList<Data> list);
	void pop_tail();
	void pop_head();
	bool delete_node(const Data& data);

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList<Data>& list) {
		Node* tmp = list._head->next;
		while (tmp != list._head) {
			stream << tmp->data << "\t";
			tmp = tmp->next;
		}
		return stream;
	}

	template<class U>
	static U calculate_list(const LinkedList<summand<U>> list,const double number) {
		Node* tmp = list._head->next;
		U result = 0;

		while (tmp != list._head) {
			result += tmp->data.coeff * pow(number, tmp->data.degree);
			tmp = tmp->next;
		}

		return result;
	}
};

// -- REALIZATION -- //

template<class Data>
LinkedList<Data>::LinkedList() {
	_head = new Node();
	_head->next = _head;
}

template<class Data>
LinkedList<Data>::LinkedList(const LinkedList<Data>& other) : LinkedList(){
	Node* tmp = other._head->next;
	while (tmp != other._head) {
		this->push_tail(tmp->data);
		tmp = tmp->next;
	}
}

template<class Data>
LinkedList<Data>::~LinkedList() {
	Node* tmp = _head;
	while (tmp->next != _head) {
		tmp = tmp->next;
	}

	tmp->next = nullptr;

	while (_head) {
		Node* count = _head;
		_head = _head->next;
		delete count;
	}
}

template<class Data>
LinkedList<Data>& LinkedList<Data>::operator+=(const LinkedList<Data>& second) {
	int lenght1 = 0;
	int lenght2 = 0;

	Node* tmp1 = _head->next;
	Node* tmp2 = second._head->next;

	while (tmp1 != _head) {
		tmp1 = tmp1->next;
		lenght1++;
	}

	while (tmp2 != second._head)
	{
		tmp2 = tmp2->next;
		lenght2++;
	}

	if (lenght1 != lenght2) throw std::runtime_error("Size first List != size second List");

	tmp1 = _head->next;
	tmp2 = second._head->next;
	while (tmp1 != _head) {
		tmp1->data += tmp2->data;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	return *this;
}

template<class Data>
LinkedList<Data> LinkedList<Data>::operator+(const LinkedList<Data>& second) const {
	LinkedList<Data> tmp(*this);
	LinkedList<Data> new_list(tmp += second);
	return new_list;
}

template<class Data>
Data& LinkedList<Data>::operator[](const int index){
	if(index < 0) throw std::out_of_range("Out of range");
	
	int count = 0;
	Node* tmp = _head->next;

	while (tmp != _head) {
		if (count == index) {
			return tmp->data;
		}
		tmp = tmp->next;
		count++;
	}
	
	throw std::out_of_range("Out of range");
}

template<class Data>
Data LinkedList<Data>::operator[](const int index) const{
	if (index < 0) throw std::runtime_error("Out of range");

	int count = 0;
	Node* tmp = _head->next;

	while (tmp != _head) {
		if (count == index) {
			return tmp->data;
		}
		tmp = tmp->next;
		count++;
	}

	throw std::runtime_error("Out of range");
}

template<class Data>
void LinkedList<Data>::push_tail(const Data& data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = _head;

	Node* tmp = _head;	
	while (tmp->next != _head) {
		tmp = tmp->next;
	}

	new_node->next = _head;
	tmp->next = new_node;

	return;
}

template<class Data>
void LinkedList<Data>::push_tail(const LinkedList<Data> list) {
	Node* tmp = list._head->next;

	while (tmp != list._head) {
		this->push_tail(tmp->data);
		tmp = tmp->next;
	}

	return;
}

template<class Data>
void LinkedList<Data>::push_head(const Data& data) {
	Node* new_node = new Node();
	new_node->data = data;

	new_node->next = _head->next;
	_head->next = new_node;

	return;
}

template<class Data>
void LinkedList<Data>::push_head(const LinkedList<Data> list) {
	Node* tmp = list._head->next;

	while (tmp != list._head) {
		this->push_head(tmp->data);
		tmp = tmp->next;
	}

	return;
}

template<class Data>
void LinkedList<Data>::pop_tail() {

	Node* tmp = _head;
	while (tmp->next->next != _head) {
		tmp = tmp->next;
	}

	delete tmp->next;
	tmp->next = _head;
	
	return;
}

template<class Data>
void LinkedList<Data>::pop_head() {
	Node* tmp = _head->next;
	_head->next = _head->next->next;
	delete tmp;
	return;
}

template<class Data>
bool LinkedList<Data>::delete_node(const Data& data) {
	Node* tmp = _head;
	bool sign = false;

	do{
		if (tmp->next->data == data) {
			Node* deleter = tmp->next->next;
			delete tmp->next;
			tmp->next = deleter;
			sign = true;
		}
		tmp = tmp->next;
	} while (tmp != _head);

	return sign;
}








