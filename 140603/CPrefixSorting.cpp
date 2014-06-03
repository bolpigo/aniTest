#include "CPrefixSorting.h"

//
// �����ӱ���ת��Ϣ
// @param
// pCakeArray �洢�ӱ���������
// nCakeCnt �ӱ�����
//
void CPrefixSorting::Run(int *pCakeArray, int nCakeCnt) {
	Init(pCakeArray, nCakeCnt);
	m_nSearch = 0;
	Search(0);
}

//
//����ӱ����巭ת����
//
void CPrefixSorting::Output() {
	for(int i = 0; i < m_nMaxSwap; ++i) {
		printf("%d ",m_nSwapArray[i]);
	}
	printf("\n |Search Times| : %d\n", m_nSearch);
	printf("Total Swap times = %d\n", m_nMaxSwap);
}

//
// ��ʼ��������Ϣ
// @param
// pCakeArray �洢�ӱ���������
// nCakeCnt �ӱ�����
//
void CPrefixSorting::Init(int *pCakeArray, int nCakeCnt) {
	assert(pCakeArray != NULL);
	assert(nCakeCnt > 0);
	m_nCakeCnt = nCakeCnt;

	//��ʼ���ӱ�����
	m_CakeArray = new int[m_nCakeCnt];
	assert(m_CakeArray != NULL);
	for(int i = 0; i < m_nCakeCnt; ++i) {
		m_CakeArray[i] = pCakeArray[i];
	}

	//������ཻ��������Ϣ
	m_nMaxSwap = UpperBound(m_nCakeCnt);

	//��ʼ�������������
	m_SwapArray = new int[m_nMaxSwap + 1];
	assert(m_SwapArray != NULL);

	//��ʼ���м佻�������Ϣ
	m_ReverseCakeArray = new int[m_nCakeCnt];
	for(int i = 0; i < m_nCakeCnt; ++i) {
		m_ReverseCakeArray[i] = m_CakeArray[i];
	}
	m_ReverseCakeArraySwap = new int[m_nMaxSwap];
}

//Ѱ�ҵ�ǰ��ת�½�
int CPrefixSorting::LowerBound(int *pCakeArray, int nCakeCnt) {
	int t, ret = 0;
	for(int i = 1; i < nCakeCnt; ++i) {
		t = pCakeArray[i] - pCakeArray[i-1];
		if((t == 1) || (t == -1));
		else ++ret;
	}
	return ret;
}

//����������
void CPretixSorting::Search(int step) {
	int i, nEstimate;
	++m_nSearch;

	//���������������Ҫ����С��������
	nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);
	if(step + nEstimate > m_nMaxSwap) return;
	if(IsSorted(m_ReverseCakeArray, m_nCakeCnt)) {
		if(step < m_nMaxSwap) {
			m_nMaxSwap = step;
			for(i = 0; i < m_nMaxSwap; ++i) {
				m_SwapArray[i] = m_ReverseCakeArraySwap[i];
			}
		}
		return;
	}

	//���еݹ鷭ת
	for(i = 1; i < m_nCakeCnt; ++i) {
		Reverse(0,i);
		m_ReverseCakeArraySwap[step] = i;
		Search(step+1);
		Reverse(0,i);
	}
}

//
// true �Ѿ��ź���
// false δ����
//
bool CPrefixSorting::IsSorted(int *pCakeArray, int nCakeCnt) {
	for(int i = 1; i < nCakeCnt; ++i) {
		if(pCakeArray[i-1] > pCakeArray[i]) return false;
	}
	return true;
}

//
// ��ת�ӱ���Ϣ
//
void CPrefixSorting::Reverse(int nBegin, int nEnd) {
	assert(nEnd > nBegin);
	for(int i = nBegin, j = nEnd; i < j; ++i, --j) {
		t = m_ReverseCakeArray[i];
		m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
		m_ReverseCakeArray[j] = t;
	}
}
