/*********************************************************/
//
//烙饼排序，编程之美
//
/*********************************************************/
class CPrefixSorting {
private:
	int *m_CakeArray; //烙饼信息数组
	int m_nCakeCnt;//烙饼个数
	int m_nMaxSwap;//最多交换次数，2 * m_nCakeCnt；
	int *m_SwapArray;//交换结果数组
	int *m_ReverseCakeArray;//当前翻转烙饼信息数组
	int *m_ReverseCakeArraySwap;//当前翻转烙饼交换结果数组
	int m_nSearch;//当前搜索次数信息
public:
	CPrefixSorting():m_nCakeCnt(0),m_nMaxSwap(0){}
	~CPrefixSorting() {
		if(m_CakeArray) delete m_CakeArray;
		if(m_SwapArray) delete m_SwapArray;
		if(m_ReverseCakeArray) delete m_ReverseCakeArray;
		if(m_ReverseCakeArraySwap) delete m_ReverseCakeArraySwap;
	}
	//
	//计算烙饼翻转信息
	//@param
	//pCakeArray 存储烙饼索引数组
	//nCakeCnt 烙饼个数
	//
	void Run(int *pCakeArray, int nCakeCnt);

	//
	//输出烙饼具体翻转次数
	//
	void Output();
private:

	//
	//初始化数组信息
	//@param
	//pCakeArray 存储烙饼索引数组
	//nCakeCnt 烙饼个数
	//
	void Init(int *pCakeArray, int nCakeCnt);
	
	//
	// 寻找当前翻转上界
	// @param
	// nCakeCnt 烙饼个数
	//
	void UpperBound(int nCakeCnt) {
		return nCakeCnt * 2;
	}
	
	//
	// 寻找当前翻转下界
	// @param
	// pCakeArray 存储烙饼索引数组
	// nCakeCnt 烙饼个数
	//
	int LowerBound(int *pCakeArray, int nCakeCnt);

	//
	//排序主函数
	//
	void Search(int step);

	//
	// true 已经排好序
	// false 未排序
	//
	bool IsSorted(int *pCakeArray, int nCakeCnt);

	//
	//翻转烙饼信息
	//
	void Reverse(int nBegin, int nEnd);

};
