#pragma once
#include <vector>

using std::vector;
typedef CArray<int, int> CIntArray;

class CDefectStatistics
{
public:
	CDefectStatistics(void);
	virtual ~CDefectStatistics(void);

public:
	//缺陷
	CStringArray   m_aErrTexts;
	int m_nVerSion;

	class CBaseItem
	{
	public:
		CBaseItem()
		{
			m_nTestTimeSec = 0;
			m_fArea = 0.0;
			m_nTestWaitTimeSec = 0;
			m_nTotalNum = 0;
			m_nPassNum = 0;
			m_nNgNum = 0;
			m_nTopErrCount = 0;
			m_nBotErrCount = 0;
			m_bOnceTestTwoBoard = FALSE;
			m_sAOIScanBoardCount = "0";
			m_nErrCount = 0;    //所有点数
			m_nTopTrueErrCount = 0;	//正面真点
			m_nBotTrueErrCount = 0;	//反面真点
			m_nTopFakeErrCount = 0;	//正面假点
			m_nBotFakeErrCount = 0;
			m_sPcbNo = "";
			m_sJob = "";
			m_sPL = "";
		}
		CIntArray       m_aTopErrTotals;
		CIntArray       m_aBotErrTotals;
		CStringArray	m_aPLNo;		//批量号 2020年8月6日13:16:29新增加，单独保存
		CString			m_sAOIScanBoardCount;	//在线AOI扫描板数,2020年8月26日11:39:38新增加
		int             m_nTestTimeSec; //测试时间
		double          m_fArea;        //测试面积
		int             m_nTestWaitTimeSec; //测试中等待上下板的时间
		BOOL			m_bOnceTestTwoBoard;	//一次测试两片板
		int             m_nPassNum;     //Pass板数
		int             m_nNgNum;       //NG板数

		// 2022.04.12 南通深南
		CString         m_sJob;      // 料号
		CString         m_sPL;       // 批次号
		CString         m_sPcbNo;       // 板号
		int             m_nTopErrCount;	//正面报点
		int             m_nBotErrCount;	//反面报点
		int             m_nTotalNum;    //测板数量
		int             m_nErrCount;    //所有点数
		int             m_nTopTrueErrCount;	//正面真点
		int             m_nBotTrueErrCount;	//反面真点
		int             m_nTopFakeErrCount;	//正面假点
		int             m_nBotFakeErrCount;	//反面假点
		void SetSize(int i)
		{		
			m_aTopErrTotals.SetSize(i);
			m_aBotErrTotals.SetSize(i);
			for(int i = 0; i < m_aTopErrTotals.GetSize(); i++)
			{
				m_aTopErrTotals[i] = 0;
				m_aBotErrTotals[i] = 0;
			}
		}
		void RemoveAll()
		{
			m_aTopErrTotals.RemoveAll();
			m_aBotErrTotals.RemoveAll();
		}
		void Copy(CBaseItem* pItem)
		{
		   m_sJob = pItem->m_sJob;
		   m_nTestTimeSec = pItem->m_nTestTimeSec;
		   m_fArea = pItem->m_fArea;
		   m_nTestWaitTimeSec = pItem->m_nTestWaitTimeSec;
		   m_nTotalNum = pItem->m_nTotalNum;
		   m_bOnceTestTwoBoard = pItem->m_bOnceTestTwoBoard;
		   m_nPassNum = pItem->m_nPassNum;
		   m_nNgNum = pItem->m_nNgNum;
		   m_nTopErrCount = pItem->m_nTopErrCount;
		   m_nBotErrCount = pItem->m_nBotErrCount;
		   for(int i = 0; i < m_aTopErrTotals.GetSize(); i++)
		   {
			   m_aTopErrTotals[i] = pItem->m_aTopErrTotals[i];
			   m_aBotErrTotals[i] = pItem->m_aBotErrTotals[i];
		   }
		}
	};

	class CItem
	{
	public:
		CString         m_sBeginTime;
		CString         m_sEndTime;
		CBaseItem       m_baseItem;	
	};

	//统计结果,包含起止统计时间，每种资料的测试情况
	class CStatistics
	{
	public:
		CStatistics()
		{
		   m_ListStatisticsItem.reserve(100);
		}
		CString		   m_sBeginTime;
		CString        m_sEndTime;
		CString        m_sMaterial;     // 料号
		CString        m_sPcbNum;       // 检板数量
		CString        m_sPL;           // 批量
		CString        m_sScanOperator; // 扫描人员
		CString        m_sScanTime;     // 扫描时间
		CString        m_sCheckOperator; // 检板人员
		CString        m_sCheckTime;    // 检板时间
		CString        m_sAveragePointNum;  // 平均点数
		CString        m_sTAverPointNum;   // T面平均点数
		CString        m_sBAverPointNum;   // T面平均点数
		CString        m_sTAverTruePointNum;  // T面平均真点数
		CString        m_sBAverTruePointNum;  // B面平均真点数
		CString        m_sTAverFakePointNum;  // T面平均假点数
		CString        m_sBAverFakePointNum;  // B面平均假点数
		vector<CBaseItem*> m_ListStatisticsItem;
		~CStatistics()
		{
			for(vector<CBaseItem*>::iterator it = m_ListStatisticsItem.begin(); it != m_ListStatisticsItem.end(); it++)
			{
				delete (*it);
			}
		}
		
	};
	vector<CString> m_vecDateFile;
	vector<CString> m_vecMaterials;

	class EXPORT_ITEM	//用于导出时排序
	{
	public:
		CString  sErrText;
		int      nCount;
		static void Exchange(EXPORT_ITEM* a, EXPORT_ITEM* b)
		{
			CString sTemp;
			int nTemp;
			sTemp = a->sErrText;
			nTemp = a->nCount;
			a->sErrText = b->sErrText;
			a->nCount = b->nCount;
			b->sErrText = sTemp;
			b->nCount = nTemp;
		}

	};

	CTime           m_beginTime;    //开始测板时间
	CTime			m_endTime;		//结束测板时间
	CItem		    m_DefectItem;	//存
	vector<CStatistics*>   m_ListDefect;	//读
	CMapStringToString m_mapPL;		//批量号
	CMapStringToString m_mapScan;	//在线扫描板数
public:
	void CopyErrText(CStringArray& aErrTexts); //获取所有的缺陷类型
	void SaveDefectStatistics(CString& sPath,bool bOneTimeTestTwoBoard = false);
	void ResetStatisticsInfo(); //重置
	void Begin(){ m_beginTime = CTime::GetCurrentTime(); }
	void End(int nTestWaitTimeSec);
	void SetPcbInfo(CString& sJob, double fArea); //板信息
	void AddOnePcb(BOOL bPass, BOOL bNG, int nTopErrCount, int nBotErrCount, CIntArray& aTopErrTotals, CIntArray& aBotErrTotals); //增加一块
	BOOL GetDefectStaticsFromFile(CString& sPath); //从文件读保存的测板数据
	BOOL GetDateFromFiles(CString sPath);    // 从指定文件夹获取数据文件
	void Separate(CString strSrc,CStringArray& arData);	//后续增加在这里增加 2020年8月6日20:18:11
	CStatistics* AddDefectItems();
	CStatistics* AddDefectItems(int from, int to);  //
	//CStatistics* AddDefectItems(CString& sJob,CString sPath);     //按资料名统计
	void AddDefectItems(CString& sJob, CString sPath);
	CStatistics* AddDefectItems(CString& sJob,CTime& tBeginTime,CTime& tEndTime);     //按资料名和指定时间统计
	void ExportToCSV(CTime& cTime, CString& sPath);		//导出离给定天20天之内最近有测板记录的一天
	void CopyItem(CItem* pDet, CItem* pSrc);

private:
	int  GetTotalTime(CTime& beginTime, CTime& endTime);
	void SetErrTextArray(CString& sErrText);
	void SetItemFormText(CItem* pItem, CString& sItemText);
	void AddBaseItem(CBaseItem* pDes, CBaseItem* pItem);
	BOOL FindDayFromFile(CTime& cTime, CTime& t);  //找出离给定日期之前20天之内最近的有测板记录的一天
};

