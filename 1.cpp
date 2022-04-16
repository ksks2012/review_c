#include "header.h"

// add = operator
class CMyString {
	public:
		CMyString(char *pData = NULL);
		CMyString(const CMyString& str);
		~CMyString(void);

		CMyString& operator=(const CMyString& str);

	private:
		char *m_pData;
};

CMyString& CMyString::operator=(const CMyString& str) {
	if(this != &str) {
		CMyString temp(str);

		// swap
		char *pTemp = temp.m_pData;
		temp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}
