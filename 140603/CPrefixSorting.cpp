#include "CPrefixSorting.h"

//
// 计算烙饼翻转信息
// @param
// pCakeArray 存储烙饼索引数组
// nCakeCnt 烙饼个数
//
void CPrefixSorting::Run(int *pCakeArray, int nCakeCnt) {
	Init(pCakeArray, nCakeCnt);
	m_nSearch = 0;
	Search(0);
}

//
//输出烙饼具体翻转次数
//
void CPrefixSorting::Output() {
	for(int i = 0; i < m_nMaxSwap; ++i) {
		printf("%d ",m_nSwapArray[i]);
	}
	printf("\n |Search Times| : %d\n", m_nSearch);
	printf("Total Swap times = %d\n", m_nMaxSwap);
}

//
// 初始化数组信息
// @param
// pCakeArray 存储烙饼索引数组
// nCakeCnt 烙饼个数
//
void CPrefixSorting::Init(int *pCakeArray, int nCakeCnt) {
	assert(pCakeArray != NULL);
	assert(nCakeCnt > 0);
	m_nCakeCnt = nCakeCnt;

	//初始化烙饼数组
	m_CakeArray = new int[m_nCakeCnt];
	assert(m_CakeArray != NULL);
	for(int i = 0; i < m_nCakeCnt; ++i) {
		m_CakeArray[i] = pCakeArray[i];
	}

	//设置最多交换次数信息
	m_nMaxSwap = UpperBound(m_nCakeCnt);

	//初始化交换结果数组
	m_SwapArray = new int[m_nMaxSwap + 1];
	assert(m_SwapArray != NULL);

	//初始化中间交换结果信息
	m_ReverseCakeArray = new int[m_nCakeCnt];
	for(int i = 0; i < m_nCakeCnt; ++i) {
		m_ReverseCakeArray[i] = m_CakeArray[i];
	}
	m_ReverseCakeArraySwap = new int[m_nMaxSwap];
}

//寻找当前翻转下界
int CPrefixSorting::LowerBound(int *pCakeArray, int nCakeCnt) {
	int t, ret = 0;
	for(int i = 1; i < nCakeCnt; ++i) {
		t = pCakeArray[i] - pCakeArray[i-1];
		if((t == 1) || (t == -1));
		else ++ret;
	}
	return ret;
}

//排序主函数
void CPretixSorting::Search(int step) {
	int i, nEstimate;
	++m_nSearch;

	//估算这次搜索所需要的最小交换次数
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

	//进行递归翻转
	for(i = 1; i < m_nCakeCnt; ++i) {
		Reverse(0,i);
		m_ReverseCakeArraySwap[step] = i;
		Search(step+1);
		Reverse(0,i);
	}
}

//
// true 已经排好序
// false 未排序
//
bool CPrefixSorting::IsSorted(int *pCakeArray, int nCakeCnt) {
	for(int i = 1; i < nCakeCnt; ++i) {
		if(pCakeArray[i-1] > pCakeArray[i]) return false;
	}
	return true;
}

//
// 翻转烙饼信息
//
void CPrefixSorting::Reverse(int nBegin, int nEnd) {
	assert(nEnd > nBegin);
	for(int i = nBegin, j = nEnd; i < j; ++i, --j) {
		t = m_ReverseCakeArray[i];
		m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
		m_ReverseCakeArray[j] = t;
	}
}
