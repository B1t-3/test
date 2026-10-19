#pragma once

#include "..\\AviBaseUI\\SerializeObj.h"

class CH900Setting : public CSerializeObj
{
public:
	CH900Setting(void);
	~CH900Setting(void);

public:
	int m_nScanSpeed;					// 扫描轴扫描时运动速度(脉冲/秒)
	int m_nScanAccelSpeed;			// 扫描加速度
	double m_dPlusePerStep;				// 扫描轴每毫米脉冲
	double		m_f2CCDScanTolsTop[7];	// CCD扫描补偿
	int			m_nCcdType;				// CCD类型0 7K， 1 15K
	BOOL		m_bUseGm;
	BOOL		m_bAdjustWidth;
	BOOL		m_bBWCam;				// 黑白相机

	double m_dTableTotalDis;			// 台面总行程
	double m_dOrgToScanDis;				// 原点到扫描
	int m_nFastSpeed;					// 空跑速度
	int m_nFastAccelSpeed;				// 空跑加速度
	double m_dAccelDis;					// 加减速距离
	int m_nMaxScanBoardCount;			// 最多扫描片数
	double m_dScanDis;					// 扫描长度
	int m_nAdjustOneStep;				// 调焦步长
	int m_nAdjustCount;					// 调焦次数
	double	m_dAdjustBoardHight;
	int m_nAdjustAxisMMPerPluse;
	int m_nAdjustBaseStep;
	BOOL m_bAdjustCCDByInput;
	double m_dCurrBoardHeight;


	// 可调新光源
	BOOL m_nLightType2;					// 恒流源
	int m_nLightChannelNum;				// 通道数
	int m_nLightDegreeIndex;			// 哪一组光源亮度

	int m_nNewLightCom1;
	int m_nNewLightCom2;
	int m_nNewLightT1[10];
	int m_nNewLightT2[10];
	int m_nNewLightT3[10];
	int m_nNewLightT4[10];
	int m_nNewLightT5[10];
	int m_nNewLightT6[10];
	int m_nNewLightB1[10];
	int m_nNewLightB2[10];
	int m_nNewLightB3[10];
	int m_nNewLightB4[10];
	int m_nNewLightB5[10];
	int m_nNewLightB6[10];
public:
	void Load();
	void Save();

	virtual BOOL Serialize(CArchive& ar);
};

