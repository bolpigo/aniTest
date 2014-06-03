/*********************************************************/
//
//�ӱ����򣬱��֮��
//
/*********************************************************/
class CPrefixSorting {
private:
	int *m_CakeArray; //�ӱ���Ϣ����
	int m_nCakeCnt;//�ӱ�����
	int m_nMaxSwap;//��ཻ��������2 * m_nCakeCnt��
	int *m_SwapArray;//�����������
	int *m_ReverseCakeArray;//��ǰ��ת�ӱ���Ϣ����
	int *m_ReverseCakeArraySwap;//��ǰ��ת�ӱ������������
	int m_nSearch;//��ǰ����������Ϣ
public:
	CPrefixSorting():m_nCakeCnt(0),m_nMaxSwap(0){}
	~CPrefixSorting() {
		if(m_CakeArray) delete m_CakeArray;
		if(m_SwapArray) delete m_SwapArray;
		if(m_ReverseCakeArray) delete m_ReverseCakeArray;
		if(m_ReverseCakeArraySwap) delete m_ReverseCakeArraySwap;
	}
	//
	//�����ӱ���ת��Ϣ
	//@param
	//pCakeArray �洢�ӱ���������
	//nCakeCnt �ӱ�����
	//
	void Run(int *pCakeArray, int nCakeCnt);

	//
	//����ӱ����巭ת����
	//
	void Output();
private:

	//
	//��ʼ��������Ϣ
	//@param
	//pCakeArray �洢�ӱ���������
	//nCakeCnt �ӱ�����
	//
	void Init(int *pCakeArray, int nCakeCnt);
	
	//
	// Ѱ�ҵ�ǰ��ת�Ͻ�
	// @param
	// nCakeCnt �ӱ�����
	//
	void UpperBound(int nCakeCnt) {
		return nCakeCnt * 2;
	}
	
	//
	// Ѱ�ҵ�ǰ��ת�½�
	// @param
	// pCakeArray �洢�ӱ���������
	// nCakeCnt �ӱ�����
	//
	int LowerBound(int *pCakeArray, int nCakeCnt);

	//
	//����������
	//
	void Search(int step);

	//
	// true �Ѿ��ź���
	// false δ����
	//
	bool IsSorted(int *pCakeArray, int nCakeCnt);

	//
	//��ת�ӱ���Ϣ
	//
	void Reverse(int nBegin, int nEnd);

};
