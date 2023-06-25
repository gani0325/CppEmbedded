#pragma once
#include <assert.h>

template <typename T>
class CLinkedNode
{
	template <typename T>
	friend class CLinkedList;

private:
	CLinkedNode()
	{
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
	~CLinkedNode()
	{

	}
private:
	T				m_Data;		// ���� �����͸� ������ ����
	CLinkedNode<T>* m_pNext;	// ���� ����� �ּҸ� ������ ����
	CLinkedNode<T>* m_pPrev;	// ���� ����� �ּҸ� ������ ����
};

template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		// ó������ �߰��� ��尡 �����Ƿ� Begin �������� End ����
		// End �������� Begin ����
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_iSize = 0;
	}
	~CLinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
	}

private:
	typedef CLinkedNode<T>	NODE;
	typedef CLinkedNode<T>* PNODE;
private:
	PNODE	m_pBegin;
	PNODE	m_pEnd;
	int		m_iSize;

public:
	void push_back(const T& data)
	{
		PNODE	pNode = new NODE;
		pNode->m_Data = data;

		// �ڿ� �߰� �ؾ��ϹǷ� End�� ���� ��� ������
		PNODE pPrev = m_pEnd->m_pPrev;

		// ���� ���� ���� End ��� ���̿� ���� ������ ��� �߰�
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		// End ���� ���ο� ��� ����
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const T& data)
	{
		PNODE	pNode = new NODE;
		pNode->m_Data = data;

		// Begin �� Begin �� ���� ��� ���̿� ���� ������ ��� �߰�
		PNODE	pNext = m_pBegin->m_pNext;
		// ���� ������ ����� ���� ���� Begin �� ���� ��� �ش�
		// Begin�� ���� ����� ���� ���� ���� ������ ��� �ش�
		pNode->m_pNext = pNext;
		pNext->m_pPrev = pNode;
		// Begin�� ���� ���� ���� ������ ��带 �ش�
		// ���� ������ ����� ���� ���� Begin �� �ش�
		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_iSize;
	}

	void pop_back()
	{
		if (empty())
			assert(false);

		// ���� ������ ��� �������ϹǷ� End ���� ��� ���
		PNODE	pDeleteNode = m_pEnd->m_pPrev;
		// ���� ����� ���� ���
		PNODE	pPrev = pDeleteNode->m_pPrev;
		// ���� ����� ������ End, End �������� ���� ���
		pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pPrev;

		// ��� �����
		delete pDeleteNode;

		--m_iSize;
	}

	void pop_front()
	{
		if (empty())
			assert(false);

		// ���� ���
		PNODE	pDeleteNode = m_pBegin->m_pNext;
		// ���� ����� ���� ���
		PNODE	pNext = pDeleteNode->m_pNext;
		// �� ���� Begin ��� ����
		pNext->m_pNext = m_pBegin;
		m_pBegin->m_pPrev = pNext;

		// ��� �����
		delete pDeleteNode;

		--m_iSize;
	}

	T front()	const
	{
		if (empty())
			assert(false);

		return m_pBegin->m_pNext->m_Data;
	}

	T back()	const
	{
		if (empty())
			assert(false);

		return m_pEnd->m_pPrev->m_Data;
	}

	// Begin �� End �� ������ ���� �߰��� ����� ���� ���
	void clear()
	{
		PNODE	pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			// ���� ����� ���� ��� ���
			PNODE	pNext = pNode->m_pNext;
			// ���� ��� �����
			delete pNode;
			// pNode�� ���� ����� �ּ� �ֱ�
			pNode = pNext;
		}

		m_iSize = 0;

		// Begin�� End ���� ����
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}

	int size()	const
	{
		return m_iSize;
	}

	// ����Ʈ�� ������� ��� true, �ƴϸ� false
	bool empty()	const
	{
		return m_iSize = 0;
	}
};

