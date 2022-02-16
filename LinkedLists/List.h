#pragma once
#include "Iterator.h"

template <typename T>
class List
{
public:
	/// <summary>
	/// Creates a new list with zero elements inside.
	/// </summary>
	List();

	/// <summary>
	/// Creates a new list using the same elements from another list.
	/// </summary>
	List(const List<T>& other);

	/// <summary>
	/// On deletion, calls the list's destroy function.
	/// </summary>
	~List();

	/// <summary>
	/// Deletes all elements of the list.
	/// </summary>
	void destroy();

	/// <summary>
	/// Creates a new iterator that points to the first node in the list.
	/// </summary>
	Iterator<T> begin() const;

	/// <summary>
	/// Creates a new iterator that points to the last node in the list.
	/// </summary>
	Iterator<T> end() const;

	/// <summary>
	/// Returns whether or not a specific item could be found in the list.
	/// </summary>
	bool contains(const T& object) const;

	/// <summary>
	/// Adds a node to the front of the list.
	/// </summary>
	void pushFront(const T& value);

	/// <summary>
	/// Adds a new node to the end of the list.
	/// </summary>
	void pushBack(const T& value);

	/// <summary>
	/// Inserts a given node into the given index if that index is valid.
	/// </summary>
	bool insert(const T& value, int index);

	/// <summary>
	/// Tries to remove the node of the given value from the list.
	/// </summary>
	/// <returns> Whether or not an element was removed. </returns>
	bool remove(const T& value);

	/// <summary>
	/// Prints each element in the linked list.
	/// </summary>
	void print() const;

	/// <summary>
	/// Sets the first and last node to nothing.
	/// </summary>
	void initialize();

	/// <summary>
	/// Finds whether or not the list has any elements.
	/// </summary>
	bool isEmpty() const;

	/// <summary>
	/// Sets the iterator to point at the given index.
	/// </summary>
	bool getData(Iterator<T>& iter, int index);

	/// <summary>
	/// Finds the number of nodes in the list.
	/// </summary>
	int getLength() const;

	/// <summary>
	/// Sets this list equal to the given list.
	/// </summary>
	const List<T>& operator=(const List<T>& otherList);

	/// <summary>
	/// Sorts the list of elements using bubble sort.
	/// </summary>
	void sort();

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	*this = other;
}

template<typename T>
inline List<T>::~List()
{
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	Node<T>* currentNode = m_first;
	Node<T>* nextNode;

	// For each element in the list, it will delete them.
	for (int i = 0; i < getLength(); i++) 
	{
		// Set the nextNode to the currentNode's next.
		nextNode = currentNode->next;
		// Delete the currentNode.
		delete currentNode;
		// Decrement the node count.
		m_nodeCount--;
		// Set the currentNode equal to the nextNode.
		currentNode = nextNode;
	}
	initialize();
}


template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}


template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last);
}

template<typename T>
inline bool List<T>::contains(const T& object) const
{
	Node<T>* currentNode = m_first;
	for (int i = 0; i < getLength(); i++) 
	{
		// If the data inside the current node is equal to the given object...
		if (currentNode->data == object) 
			// ...return true.
			return true;
		// Otherwise, set the currentNode equal to its own next.
		currentNode = currentNode->next;
	}

	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	// Creates a new node that will go in front of the list.
	Node<T>* newFirst = new Node<T>(value);
	// Changes the next of the new first to m_first.
	if(m_first != nullptr)
		newFirst->next = m_first;
	// Changes m_first to the new first.
	m_first = newFirst;
	// Changes the original m_first's previous to the new first.
	if (newFirst->next != nullptr)
		newFirst->next->previous = newFirst;
	else
		m_last = newFirst;

	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	// Creates a new node that will go at the end of the list.
	Node<T>* newLast = new Node<T>(value);
	// Changes the previous of the new last to m_last.
	newLast->previous = m_last;
	// Changes m_last to the new last.
	m_last = newLast;
	// Changes the original m_last's next to the new last.
	if (newLast->previous != nullptr)
		newLast->previous->next = newLast;
	else
		m_first = newLast;

	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	bool nodeInserted = false;
	Node<T>* newNode = new Node<T>(value);
	Node<T>* currentNode = m_first;
	// If the index is not within the current length...
	if (index < getLength() || index > getLength())
		// ...it returns false.
		return nodeInserted;
	// If the index is zero...
	if (index == 0) 
	{
		// ...it pushes the value to the front of the list.
		pushFront(value);
		return true;
	}
	// If the index is the same as the node count...
	else if (index == m_nodeCount) 
	{
		// ...it pushes the value to the back of the list.
		pushBack(value);
		return true;
	}

	// Iterates through the list of node until it reaches the specified index.
	for (int i = 0; i < index; i++)
		currentNode = currentNode->next;
		
	// Insert the new node into the space where the current node was.
	newNode->next = currentNode;
	newNode->previous = currentNode->previous;
	currentNode->previous->next = newNode;
	currentNode->previous = newNode;

	m_nodeCount++;
	return nodeInserted;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	bool objectRemoved = false;
	Node<T>* nodeToRemove = m_first;
	// Iteratates through the list.
	for (int i = 0; i < m_nodeCount; i++) 
	{
		// If the data in the node equals the value change the elements around it as follows.
		if (nodeToRemove->data == value) 
		{
			// If the node is not the last index...
			if (nodeToRemove->next != nullptr)
				// ...set its next's previous to its own previous.
				nodeToRemove->next->previous = nodeToRemove->previous;
			// If it is the last element...
			else
				// ...set the last element in the list to its previous.
				m_last = nodeToRemove->previous;
			// If the node is not the first element in the list...
			if (nodeToRemove->previous != nullptr)
				// ... set its previous' next to its own next.
				nodeToRemove->previous->next = nodeToRemove->next;
			// If it is the first element in the list...
			else
				// ...set it's next to become the first element.
				m_first = nodeToRemove->next;
			delete nodeToRemove;
			m_nodeCount--;
			break;
		}
		nodeToRemove = nodeToRemove->next;
	}

	return objectRemoved;
}

template<typename T>
inline void List<T>::print() const
{
	Node<T>* currentNode = m_first;
	for (int i = 0; i < m_nodeCount; i++) 
	{
		std::cout << currentNode->data << std::endl;
		currentNode = currentNode->next;
	}
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return (m_first == nullptr && m_last == nullptr && m_nodeCount == 0);
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	if (index > getLength() || index < getLength())
		return false;

	Iterator<T> tempIter = begin();
	for (int i = 0; i < index; i++) 
	{
		// As long as the tempIter and iter point to the same node...
		if (tempIter == iter)
			// ...iterate them both until they reach the given index.
			++iter;
		++tempIter;
	}

	return true;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	// Destroy's the list.
	destroy();
	Node<T>* currentNode = otherList.m_first;
	for (int i = 0; i < otherList.getLength(); i++)
	{
		// Creates a copy of the data in the nodes of other and inserts them into this list.
		insert(currentNode->data, i);
		currentNode = currentNode->next;
	}
	return *this;
}

template<typename T>
inline void List<T>::sort()
{	
	Node<T>* currentNode = m_first;
	Node<T>* tempNode = new Node<T>();

	for (int i = 0; i < getLength() - 1; i++) 
	{
		currentNode = m_first;
		for (int j = 0; j < getLength() - 1; j++) 
		{
			// If the data of the currentNode is less than the data of its next...
			if (currentNode->data > currentNode->next->data) 
			{
				// ...swap the two.
				tempNode->data = currentNode->next->data;
				currentNode->next->data = currentNode->data;
				currentNode->data = tempNode->data;
			}
			currentNode = currentNode->next;
		}
	}
}