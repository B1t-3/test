#pragma once
#include "EapImpl.h"
#include <afxinet.h>
class CEap_AnJieLi :public CEapImpl
{
public:
	struct THREAD_PARA
	{
		CEap_AnJieLi * pEap;
		CPtrArray pErrItems;
	};
	CEap_AnJieLi(void);
	~CEap_AnJieLi(void);
	virtual void SetErrItems(CPtrArray& pErrIems);


	enum { WORKING, IDLE, ABNORMAL };
	void DeviceStatusinsert(const int& iStatus);
	//设备发生报警时调用
	virtual void AlarmUpLoad(int nStatus, BYTE cType, BYTE cStart);// Status:命令字,cType:设备状态， cStart 1、报警开始 0、报警结束
private:
	/*虚函数*/
	virtual void Setting();
	virtual BOOL Initialize(IMes* pMes, LPVOID lpCallbackParam, CString sJobPath, CString sCarPath, CString sLogPath, BOOL bForCar);
	virtual void OnMoveStatusChanged(int iStatus);
	void FtpsUpload(CPtrArray & aItems);
	virtual void Show();
	//上传数据
	bool upload_image(std::vector<CString> vDibPath, std::vector<CString> vRemotePath);
	BOOL PostXML(const CString& sUrl, const CString& val, std::string& buffer);
	//设定一个回调函数，执行libcurl在接受到数据后用户想进行的操作，通常函数多做数据保存的功能
	static size_t OnWriteResult(void *ptr, size_t size, size_t nmemb, std::string * buffer);
	static UINT ProductDataThread(LPVOID lpParam);
	void FtpUpload(CPtrArray & aItems);
	int GetLevel(const int nCmd, const int nLevel);
	CString GetAlarmID(const int nCmd, const int nType);
	std::string  BuildSendDecodeInfoXML(CString sCreatedatetime, CString sLine, CString sserial, CString sSn, CString sLotnoJob, CString sLayer);
};