#pragma once

class CAoiErrData;
class IDib;
class CData;
class CAoiGerberData;
class ISurface;
class ILayer;
class IZoom;
class IDraw;
class IPhysicLayer;
class IUnit;
class IDrlLayer;
class ICreateGraphicObj;
class CCoilGerberTileSaver;

class CFmVRS
{
	friend class CCoilGerberTileSaver;
public:
	CFmVRS(void);
	~CFmVRS(void);

	typedef struct
	{
		CRect rcOutline;
		int nThickness;
		int nAdjustNum;
		CPoint ptAdjusts[2];
		CString sJobName;
		CString sLayerName;
		int nRotate; // 相对原始资料

		CPoint ptDrawOffset;
	}HEAD_INFO;

	typedef struct
	{
		CPoint ptOffset;
	}CONVERT_INFO;

	typedef struct
	{
		CData* pData;
		BOOL bTop, bBot;
		BOOL bOffLine;
		CFmVRS* pThis;
	}THREAD_SAVE_LAYER_INFO;

	typedef struct
	{
		int nVersion;
		float fOrgX, fOrgY;
		int nWidth, nHeight;
		float fPrecision;
	}BINARY_DIB_HEADER;

	typedef struct
	{
		////////////////////////////
		// 外加的额外信息
		int nName;
		int nTest;
		BYTE nNum;
		//////////////////////////////////

		int nVersion;
		float fOrgX, fOrgY;

		////////////////////////////
		// 外加的额外信息
		double f2;
		int nTest2;
		float fName2;
		BYTE nNum2;
		double f3;
		//////////////////////////////////

		int nWidth, nHeight;

		////////////////////////////
		// 外加的额外信息
		BYTE nNum3;
		double f4;
		float f5;
		int nDibCount2;
		//////////////////////////////////

		float fPrecision;
		//多加的额外的信息
		int nDibCount;  //一共有多少个Dib

						////////////////////////////
						// 外加的额外信息
		BYTE nName3;
		short nName4;
		float fName5;
		BYTE nNum4;
		double f6;
		float f7;
		float fName6;
		int nTest3;
		BYTE nNum5;
		//////////////////////////////////

		float fEx;
		long lEx;
		int nEx;
	}BINARY_DIB_HEADER2;

	BOOL m_bClearDraw;  //精细画
	CPtrArray	m_aUpdateFmInfos;
private:
	double m_fClearPrecsion;
	double m_fPrecsionFm;
	CMutex	m_mutexData;
	BOOL	m_bUpdating;
	CData*	m_pCurData;
	CStringArray m_aUpdateFmJobList; // 正在更新的job列表，在里面的job不允许旋转，正反对调操作。
	struct KindsInfo
	{
		int    nKind;
		CStringArray aNmes;
	};
	CPtrArray			m_aKindsInfor;
public:
	void SaveErrData(CString& sReportPath, CAoiErrData* pErrData, int nPcbNo, CData* pData, BOOL bTop, int nPlaceType);
	void DeleteFolder(CString directory_path);
	void SaveLayerInfo(CData* pData, BOOL bTop, BOOL bBot);
	BOOL WaitUpdateJobDone(CString sJob, DWORD dwTimeout = INFINITE);
	BOOL IsUpdateJobDone(CString sJob, int& nIndex);
	BOOL FindUpdateFmJob(CString sJob, int &nIndex);
	int  GetAllUpdateDatas(CPtrArray& aDatas);
	BOOL CancelUpdate(int nIndex);

	void CopyErrDataOnlyCoordinate(CString& sReportPathOnlyCoordinate, CString& sReportPath, int nPcbNo, BOOL bTop);
private:
	BOOL IsOverMem(CData* pData);
	void ReportSaveErrDataFail(int nPcbNo);
	void SaveErrJPG(IDib* pDib, CString& sPath, BOOL bA, int iNo);
	int FmXY(int v);
	void GetHeadInfo(HEAD_INFO &info, CData* pData, BOOL bTop, int nPlaceType);
	void GetConvertInfo(CONVERT_INFO &info, CAoiGerberData* pGerberData);

	void ConvertXY(CPoint& pt, CONVERT_INFO& info);
	void ConvertXY(CRect& rc, CONVERT_INFO& info);
	BOOL CreateDrawBufDibs(CSize szDib, CPtrArray& aDibs);

	static UINT ThreadSaveLayerInfo(LPVOID lpParam);
    IDib* CreatePreviewDib(IDib* pDib, int nPreviewScale);
	void DoUpdateFmData();
	void DoSaveLayerInfo(CData* pData, BOOL bTop);
	BOOL DoSaveLayerInfo_Preview(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_PreviewEx(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveConvexLayer(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveDrlLayer(CAoiGerberData* pGerberData, CString sPath, IDrlLayer* pDrlLayer);
	BOOL DoSaveLayerInfo_Preview_Mask(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_Preview_Slot(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_PreviewEx_Mask(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_PreviewEx_Slot(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_Adjust(CAoiGerberData* pGerberData, int iAdjust, CString sPath);
	BOOL DoSaveLayerInfo_Ini(CData* pData, CAoiGerberData* pGerberData, BOOL bTop, CString sPath);
	BOOL DoSaveLayerInfo_Outline(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_OutlineWithName(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_OutlineWithName_Old(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_Drl(CAoiGerberData* pGerberData, CString sPath, BOOL bDrled, BOOL bBlind, CString sExPath);
	BOOL DoSaveLayerInfo_NoDrl(CAoiGerberData* pGerberData, CString sPath, BOOL bDrled, BOOL bBlind, CString sExPath) ;
	BOOL DoSaveLayerInfo_Pofv(CAoiGerberData* pGerberData, CString sPath, CString sExPath);
	BOOL DoSaveLayerInfo_Solt(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_Resin(CAoiGerberData* pGerberData, CString sPath, CString sExPath);//树脂塞孔
	BOOL DoSaveLayerInfo_Resin2(CAoiGerberData* pGerberData, CString sPath, CString sExPath);//树脂塞孔
	BOOL DoSaveLayerInfo_Back(CAoiGerberData* pGerberData, CString sPath, CString sExPath);  //背钻孔
	BOOL DoSaveLayerInfo_CSlot(CAoiGerberData* pGerberData, CString sPath);  //控深铣
	BOOL DoSaveLayerInfo_NTR(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_Punch(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveLayerInfo_LaserDrl(CAoiGerberData* pGerberData, CString sPath, CString sExPath);
	BOOL DoSaveLayerInfo_Etch(CAoiGerberData* pGerberData, CString sPath);  //二次蚀刻
	BOOL DoSaveLayerInfo_Display(CAoiGerberData* pGerberData, CString sPath);  //显示层
	IDrlLayer* ComposeDrlLayers(CPtrArray& aDrlLayers, ICreateGraphicObj* pCreater);
	void CopyFeatureToDrlLayer(IDrlLayer *pSrcLayer, IDrlLayer *pDestLayer);
	void GetLayerSide(BOOL& bTop, CAoiGerberData* pGerberData);    //给红板增加的

	//高精度
	BOOL DoSaveLayerInfo_PreviewEx_Mask_High(CAoiGerberData* pGerberData, CString sPath, CCoilGerberTileSaver* pCoilSaver = NULL);
	BOOL DoSaveLayerInfo_PreviewEx_Slot_High(CAoiGerberData* pGerberData, CString sPath, CCoilGerberTileSaver* pCoilSaver = NULL);
	BOOL DoSaveLayerInfo_PreviewEx_High(CAoiGerberData* pGerberData, CString sPath, CCoilGerberTileSaver* pCoilSaver = NULL);
	BOOL DoSaveLayerInfo_CoilGerber(CAoiGerberData* pGerberData, CString sPath, BOOL bSaveSlot, BOOL bSaveMask);
	BOOL DoSaveConvexLayer_High(CAoiGerberData* pGerberData, CString sPath);
	BOOL DoSaveDrlLayer_High(CAoiGerberData* pGerberData, CString sPath, IDrlLayer* pDrlLayer, CString sType);
	BOOL SaveBinaryDib_High(IDib* pDib, CString& sPath, CPoint ptOrg, double fPrecsion, int nCount);

	BOOL SaveBinaryDib(IDib* pDib, CString& sPath, CPoint ptOrg, double fPrecsion);
	void DoSaveLayerInfo_Outline_One(CStdioFile& file, ISurface* pOutline, IUnit* pUnit, CString sName, CONVERT_INFO& info);
void DoSaveLayerInfo_Outline_OneWithName(CStdioFile& file, ISurface* pOutline, IUnit* pUnit, CString sName, CONVERT_INFO& info);
	void DoSaveLayerInfo_NTR_One(CStdioFile& file, IPhysicLayer* pLayer, IUnit* pUnit, CONVERT_INFO& info);

	void DrawCopper(CAoiGerberData* pGerberData, IDib* pDib, IZoom* pZoom, double fPrecsion);
	void DrawDrl(CAoiGerberData* pGerberData, IDib* pDib, IZoom* pZoom, IDrlLayer* pDrlLayer);
	BOOL DrawMask(CAoiGerberData* pGerberData, IDib* pDib, IZoom* pZoom, double fPrecsion);
	BOOL DrawSlot(CAoiGerberData* pGerberData, IDib* pDib, IZoom* pZoom, double fPrecsion);
	BOOL DrawLayerNeg(IDraw* pDraw, CDC* pDC, IZoom* pZoom, ILayer* pLayer, ISurface* pOutline, COLORREF cr);
	static void NegDib(IDib* pDib, IDib* pBuffDib);
	void NegDib(IDib* pDib, COLORREF cr);
	void CopyImageDib_Inter3(IDib* pDstDib, IDib* pSrcDib);
	void CopyImageDib_Inter4(IDib* pDstDib, IDib* pSrcDib);
	void WriteStringToFile(CString value, CStdioFile& file, const CString& header);
#ifdef _DEBUG
	BOOL LoadBinaryDib(IDib* pDib, CString& sPath, CPoint& ptOrg, double& fPrecsion);
	void DebugDibToBmp(IDib* pDib, CString sName, BOOL bSplitByY, BOOL bMirrorY);
#endif
};

