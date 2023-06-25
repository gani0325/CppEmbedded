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
	T				m_Data;		// 실제 데이터를 저장할 변수
	CLinkedNode<T>* m_pNext;	// 다음 노드의 주소를 저장할 변수
	CLinkedNode<T>* m_pPrev;	// 이전 노드의 주소를 저장할 변수
};

template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		// 처음에는 추가된 노드가 없으므로 Begin 다음으로 End 지정
		// End 이전으로 Begin 지정
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

		// 뒤에 추가 해야하므로 End의 이전 노드 얻어오기
		PNODE pPrev = m_pEnd->m_pPrev;

		// 얻어온 이전 노드와 End 노드 사이에 새로 생성한 노드 추가
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		// End 노드와 새로운 노드 연결
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const T& data)
	{
		PNODE	pNode = new NODE;
		pNode->m_Data = data;

		// Begin 과 Begin 의 다음 노드 사이에 새로 생성한 노드 추가
		PNODE	pNext = m_pBegin->m_pNext;
		// 새로 생성한 노드의 다음 노드로 Begin 의 다음 노드 준다
		// Begin의 다음 노드의 이전 노드로 새로 생성한 노드 준다
		pNode->m_pNext = pNext;
		pNext->m_pPrev = pNode;
		// Begin의 다음 노드로 새로 생성한 노드를 준다
		// 새로 생성한 노드의 이전 노드로 Begin 을 준다
		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_iSize;
	}

	void pop_back()
	{
		if (empty())
			assert(false);

		// 가장 마지막 노드 지워야하므로 End 이전 노드 얻기
		PNODE	pDeleteNode = m_pEnd->m_pPrev;
		// 지울 노드의 이전 노드
		PNODE	pPrev = pDeleteNode->m_pPrev;
		// 이전 노드의 다음을 End, End 이전으로 이전 노드
		pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pPrev;

		// 노드 지우기
		delete pDeleteNode;

		--m_iSize;
	}

	void pop_front()
	{
		if (empty())
			assert(false);

		// 지울 노드
		PNODE	pDeleteNode = m_pBegin->m_pNext;
		// 지울 노드의 이전 노드
		PNODE	pNext = pDeleteNode->m_pNext;
		// 위 노드와 Begin 노드 연결
		pNext->m_pNext = m_pBegin;
		m_pBegin->m_pPrev = pNext;

		// 노드 지우기
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

	// Begin 과 End 를 제외한 실제 추가한 노드의 삭제 기능
	void clear()
	{
		PNODE	pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			// 현재 노드의 다음 노드 얻기
			PNODE	pNext = pNode->m_pNext;
			// 현재 노드 지우기
			delete pNode;
			// pNode에 다음 노드의 주소 넣기
			pNode = pNext;
		}

		m_iSize = 0;

		// Begin과 End 서로 연결
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}

	int size()	const
	{
		return m_iSize;
	}

	// 리스트가 비어있을 경우 true, 아니면 false
	bool empty()	const
	{
		return m_iSize = 0;
	}
};

