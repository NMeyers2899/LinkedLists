#pragma once
#include "Node.h"

template <typename T>
class Iterator
{
public:
	/// <summary>
	/// Creates a new iterator with no current node.
	/// </summary>
	Iterator();

	/// <summary>
	// Creates a new iterator pointing to a certain node.
	/// </summary>
	Iterator(Node<T>* node);

	/// <summary>
	/// Finds the next index in the list if there is one.
	/// </summary>
	Iterator<T> operator++();

	/// <summary>
	/// Finds the previous index in the list if there is one.
	/// </summary>
	Iterator<T> operator--();

	/// <summary>
	/// Finds if two iterators are pointing to the same node.
	/// </summary>
	const bool operator==(const Iterator<T>& iter);

	/// <summary>
	/// Finds if two iterators are pointing to different nodes.
	/// </summary>
	const bool operator!=(const Iterator<T> iter);

	/// <summary>
	/// Returns the data at the node the iterator is pointing to.
	/// </summary>
	T operator*();

private:
	Node<T>* m_current;
};

template<typename T>
inline Iterator<T>::Iterator()
{
	m_current = nullptr;
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	// If the iterator's current does not have a next...
	if (m_current == nullptr)
		// ...keep the iterator pointing at its current.
		return Iterator<T>(m_current);
	// If the iterator does have a next...
	else
		// ...change its current to the node's next.
		return Iterator<T>(m_current = m_current->next);
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	// If the iterator's current does not have a previous...
	if (m_current->previous == nullptr)
		// ...keep the iterator pointing at its current.
		return Iterator<T>(m_current);
	// If it does have a previous...
	else
		// ...change its current to the node's previous.
		return Iterator<T>(m_current = m_current->previous);
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	// Return if the data, next, and previous of the currents are all the same.
	return m_current->data == iter.m_current->data && 
		m_current->next == iter.m_current->next && 
		m_current->previous == iter.m_current->previous;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T> iter)
{
	// If the current is null xor the other's current is null...
	if (m_current == nullptr ^ iter.m_current == nullptr)
		// ...return true.
		return true;
	// If the other's current is null...
	if (iter.m_current == nullptr)
		// ...return false.
		return false;
	// Return if the data, next, and previous of the currents are all different
	return m_current->data != iter.m_current->data ||
	m_current->next != iter.m_current->next ||
	m_current->previous != iter.m_current->previous;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return T(m_current->data);
}
