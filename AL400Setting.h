#pragma once
#include "..\\AviBaseUI\\SerializeObj.h"

class CAL400Setting : public CSerializeObj
{
	public:
		CAL400Setting(void);
		~CAL400Setting(void);

public:
	double m_fScanDistPerStep;   //台面毫米和脉冲转换参数
	int m_nYSpeedOfScan;         //台面扫描速度
	double m_fStopToScanDist;    //挡板到扫描位置
	double m_fScanTopToBotDist;  //扫描正面到扫描反面
	//////////////////////////////////////////////
	int m_nTidyDelay;            //整板延迟
	int m_nBetweenDelay;         //板间隔延迟
	int m_iHandSpeed;            //手臂速度
	int m_iHandAcc;              //手臂加速度
	int m_iUpdownSpeed;          //料台速度
	int m_iUpdownAcc;            //料台加速度
	int m_iLaserMoveSpeed;       //激光平台速度
	int m_iLaserMoveAcc;         //激光平台加速
	///////////////////////////////////////////
	double m_f2CCDScanTolTop;    //正面补偿
	double m_f2CCDScanTolBot;    //反面补偿
	int m_nLaserMoveInitPos;     //激光移动平台初始位置
	int m_nLaserMoveCheckCenPos;  //激光移动平台到check平台中心位置
	int m_nLaserHandScanCenPos;         //激光手臂到扫描中心位置
	int m_nLaserHandToLaserMoveCenPos;  //激光手臂到激光移动平台中心位置
	int m_nUnLoadHandCheckCenPos;       //出料手臂到check料台位置
	int m_nUnLoadHandPassCenPos;        //出料手臂到PASS料台位置

	BOOL m_bHandLoadIn;                //手动机抓板进板 
	BOOL m_bUnLoadFreeDown;            //出料手臂出料有下压动作   
	BOOL m_bHavePass;                  //有pass板

	BOOL m_bPauseAllHandStop;         //暂停所有轴停止
	int  m_nLaserTime;					//打标时间

	BOOL m_bNgDoPass;				//NG板放PASS台面

	int m_nOutUpDownTime;

	BOOL m_bUpdownCheckSignal;//Check台面不检测出料满板信号
	BOOL m_bOKCheckSignal;//Pass台面不检测出料满板信号

	BOOL m_bLaserHandChecksignanl;
	BOOL m_bCheckHandCheckSignal;
	BOOL m_bLightOffWithStopBelt;

	BOOL m_bOpenLaser;		//是否开启打标
	BOOL m_bTidyBeforeLaser;
	double  m_fLaserTableWidth;  //激光台面宽度

	int m_nLaserTableNeedMoveDis;

	BOOL m_bScanBeltStopByOut;
	BOOL m_bUseInitPos2;
	int m_nLaserMoveInitPos2;
	BOOL m_bNotPrint;

	int m_nNgCountToStop;		//连续N块NG板停止
	BOOL m_bNoScanMode;			//空跑模式，不扫描
	double m_dBoardHeigh;		//板长
	double m_dBoardWidth;		//板宽
	BOOL m_bFreeBoardByNg;		//NG板放Pass台面，其他的放Check台面

	double m_dUnloadHandMMPluas;//出料手臂脉冲距离
	double m_dIsThickCuoweiDis; //板翘错位放板距离
	int m_nLoadBeltSpeed;		//进料皮带运动速度
	int m_nDustSpeed;			//粘尘运动速度
	double m_dLoadBeltMMPluas;	//进料皮带脉冲距离(mm/脉冲)
	BOOL m_bHaveThickCtrl;		//有板翘结构
	int m_nComPort;				//板翘COM口
	BOOL m_bCheckBoardThick;	//检测板翘
	double m_dStopToThickDist;	//距离板翘感应器的距离
	double m_dGetDataThickMore; //板翘多检测距离
	BOOL m_bChkNetConnect;		//网口连接
	CString m_strNetIP;			//板翘IP
	double m_dThickOffset;		//补偿值
	double m_dThickRealValue;	//标准块1测量值
	double m_dThickRealValue2;	//标准块2测量值
	double m_dThickValue;		//标准块1板厚
	double m_dThickValue2;		//标准块2板厚
	double m_dBeltThickMax;		//测试的皮带翘曲最大值
	double m_dFreeBoardPos;	//进料皮带尾部距离测试机手臂中心的距离
	double m_dStopToDustDist;	//进料皮带尾部距离粘尘的距离
	int m_nYSpeedOfScan2;		//扫描皮带2运动速度
	int m_nYSpeedOfScan3;		//扫描皮带3运动速度
	BOOL m_bHaveWaterCooling;	//使用水冷灯箱
	BOOL m_bUseTriggOut;		//使用外触发
	double m_f3CCDScanTolTop;	//第3列正面扫描补偿
	double m_f3CCDScanTolBot;   //第3列反面扫描补偿
	double m_f4CCDScanTolTop;	//第4列正面扫描补偿
	double m_f4CCDScanTolBot;   //第4列反面扫描补偿
	int m_nLaserHandStartSpeed;	//激光手臂初速度
	int m_nLaserHandStopSpeed;	//激光手臂末速度
	int m_nLaserHandAccSpeed;	//激光手臂加速度
	int m_nLaserHandGohomeSpeed;//激光手臂回零速度
	int m_nUnloadHandStartSpeed;//出料手臂初速度
	int m_nUnloadHandStopSpeed;	//出料手臂末速度
	int m_nUnloadHandAccSpeed;	//出料手臂加速度
	int m_nUnloadHandGohomeSpeed;	//出料手臂回零速度
	int m_nLaserTableStartSpeed;//激光平台初速度
	int m_nLaserTableStopSpeed;	//激光平台末速度
	int m_nLaserTableAccSpeed;	//激光平台加速度
	int m_nLaserTableGohomeSpeed;	//激光平台回零速度
	int m_nUpdownTableStartSpeed;	//升降台面初速度
	int m_nUpdownTableStopSpeed;	//升降台面末速度
	int m_nUpdownTableAccSpeed;		//升降台面加速度
	int m_nUpdownTableGohomeSpeed;		//升降台面回零速度

	BOOL m_bPassNotHaveOutBelt;		//Pass台面没有出料皮带
	double m_dBeltOffset;			//进料皮带补偿值(最大值加最小值)
	BOOL m_bHasWarpPlc;			//PLC连接板翘
	BOOL m_bAnalogMode;//模拟量模式
	BOOL m_bYKTecmode;			//研控TEC测板翘
	double m_dYKTecDK;			//研控TEC比例系数
	BOOL m_bScanThenCly;		//先开扫描再抬挡板气缸
	BOOL m_bHaveBotFocus;		//有反面调焦轴
	BOOL m_bManualSuckBoard;	//手动收板模式
	BOOL m_bCheckTableIsLeft;		//镜像机,出料在操作台左边

	int m_nLarserNum;			//激光打标次数
	CString m_sLaserJobFileName;	//需要打标的资料名文件路径
	BOOL m_bUsePassTable;			//使用Pass台面出板
	BOOL m_bThickBoardFreePass;		//翘板放Pass台面，错开放
	BOOL m_bLaserParaSaveByJob;		//激光打标按料号保存
	BOOL m_bNeedCheckOutBoardSingle;//收板机收板
	int m_nPrintAfterTidy;			//! 激光打标整板完成后延时多久后再打标(ms)
	double m_dLaserHandPluseEqual;	//! 激光手臂脉冲当量
	BOOL m_blUseOldMoveHand;		//! 是否使用旧版机器的移动手臂方式- 该方式切换料号后需要手动调整位置
	BOOL m_blHaveTidyAxis;			//! 是否有整板轴 
	double m_dTidyPluseEqual;		//! 整板轴脉冲当量 mm/脉冲
	double m_dTidyPos;				//! 整版轴整板总行程mm
	double m_dTidyWaitPos;			//! 整版轴等待位mm
	int m_nTidyStartSpeed;			//! 整版轴启动速度
	int m_nTidyStopSpeed;			//! 整版轴停止速度
	int m_nTidyAccSpeed;			//! 整版轴加速度
	int m_nTidyHomeSpeed;			//! 整版轴回零速度
	BOOL m_bPrintBarcode;			//! 打印条形码
	BOOL m_blDoorPauseAsSudden;		//! 门控作急停(true）
	int m_nNoLaserTableStopSpeed;	//不打标-激光平台末速度

public:
	void Load();
	void Save();
	void LoadOtherPara();
	void SaveOtherPara();
	CString m_csJobName;
	void SetJobName(CString csJobName);
	void LoadJobCfg();
	void SaveJobCfg();
	virtual BOOL Serialize(CArchive& ar) { return true; };
};

