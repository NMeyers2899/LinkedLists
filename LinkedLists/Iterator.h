#pragma once
#include "Node.h"

template <typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T>* node);

	Iterator<T> operator++();
	Iterator<T> operator--();
	const bool operator==(const Iterator<T>& iter);
	const bool operator!=(const Iterator<T> iter);
	T operator*();

private:
	Node<T>* m_current;
};

/// <summary>
///  Creates a new iterator with no current node.
/// </summary>
template<typename T>
inline Iterator<T>::Iterator()
{
	m_current = nullptr;
}

/// <summary>
/// Creates a new iterator pointing to a certain node.
/// </summary>
template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

/// <summary>
/// Finds the next index in the list if there is one.
/// </summary>
template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	if (m_current->next == nullptr)
		return Iterator<T>(m_current = m_current->next);
	else
		return m_current;
}

/// <summary>
/// Finds the previous index in the list if there is one.
/// </summary>
template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	if (m_current->previous == nullptr)
		return Iterator<T>(m_current = m_current->previous);
	else
		return m_current;
}

/// <summary>
/// Finds if two iterators are pointing to the same node.
/// </summary>
template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return m_current->data == iter.m_current->data && 
		m_current->next == iter.m_current->next && 
		m_current->previous == iter.m_current->previous;
}

/// <summary>
/// Finds if two iterators are pointing to different nodes.
/// </summary>
template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T> iter)
{
	return m_current->data != iter.m_current->data ||
		m_current->next != iter.m_current->next ||
		m_current->previous != iter.m_current->previous;
}

/// <summary>
/// Returns the data at the node the iterator is pointing to.
/// </summary>
template<typename T>
inline T Iterator<T>::operator*()
{
	return T(m_current->data);
}
