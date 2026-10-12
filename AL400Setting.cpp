#include "stdafx.h"
#include "AviMove.h"
#include "AL400Setting.h"
#include "KmIniFile.h"
#include "IBaseTool.h"
#include "MoveBase.h"


CAL400Setting::CAL400Setting(void)
{
	m_fScanDistPerStep= 0.01;   //台面毫米和脉冲转换参数
	m_nYSpeedOfScan= 3125;         //台面扫描速度
	m_fStopToScanDist=0;    //挡板到扫描位置
	m_fScanTopToBotDist=60;  //扫描正面到扫描反面
	m_nTidyDelay=0;            //整板延迟
	m_nBetweenDelay=0;         //板间隔延迟

	m_iHandSpeed=0;            //手臂速度
	m_iHandAcc=0;              //手臂加速度
	m_iUpdownSpeed=0;          //料台速度
	m_iUpdownAcc=0;            //料台加速度
	m_iLaserMoveSpeed=0;       //激光平台速度
	m_iLaserMoveAcc=0;         //激光平台加速

	m_f2CCDScanTolTop=0;    //正面补偿
	m_f2CCDScanTolBot=0;    //反面补偿

	m_nLaserMoveInitPos=0;     //激光移动平台初始位置
	m_nLaserMoveCheckCenPos=0;  //激光移动平台到check平台中心位置
	m_nLaserHandScanCenPos=0;         //激光手臂到扫描中心位置
	m_nLaserHandToLaserMoveCenPos=0;  //激光手臂到激光移动平台中心位置
	m_nUnLoadHandCheckCenPos=0;       //出料手臂到check料台位置
	m_nUnLoadHandPassCenPos=0;        //出料手臂到PASS料台位置
	m_nLightUseTime=0;                //LED光源使用时间
    m_bHandLoadIn=false;
	m_bUnLoadFreeDown=false;
	m_bHavePass=false;
    m_bPauseAllHandStop=false;
}


CAL400Setting::~CAL400Setting(void)
{


}

void CAL400Setting::Load()
{
	CKmIniFile file;
	CString strPath = IBaseTool::GetAppPath();
	if (file.ReadFile(strPath + "\\Setting\\AL400Setting"))
	{
		file.GetVarDou("Normal", "m_fScanDistPerStep", m_fScanDistPerStep);
		file.GetVarInt("Normal", "m_nYSpeedOfScan", m_nYSpeedOfScan);
		file.GetVarDou("Normal", "m_fStopToScanDist", m_fStopToScanDist);
		file.GetVarDou("Normal", "m_fScanTopToBotDist", m_fScanTopToBotDist);
		file.GetVarInt("Normal", "m_nTidyDelay", m_nTidyDelay);
		file.GetVarInt("Normal", "m_nBetweenDelay", m_nBetweenDelay);

		file.GetVarInt("Normal", "m_iHandSpeed", m_iHandSpeed);
		file.GetVarInt("Normal", "m_iHandAcc", m_iHandAcc);
		file.GetVarInt("Normal", "m_iUpdownSpeed", m_iUpdownSpeed);
		file.GetVarInt("Normal", "m_iUpdownAcc", m_iUpdownAcc);
		file.GetVarInt("Normal", "m_iLaserMoveSpeed", m_iLaserMoveSpeed);
		file.GetVarInt("Normal", "m_iLaserMoveAcc", m_iLaserMoveAcc);

		file.GetVarDou("Normal", "m_f2CCDScanTolTop", m_f2CCDScanTolTop);
		file.GetVarDou("Normal", "m_f2CCDScanTolBot", m_f2CCDScanTolBot);

		file.GetVarInt("Normal", "m_nLaserMoveInitPos", m_nLaserMoveInitPos);
		file.GetVarInt("Normal", "m_nLaserMoveCheckCenPos", m_nLaserMoveCheckCenPos);
		file.GetVarInt("Normal", "m_nLaserHandScanCenPos", m_nLaserHandScanCenPos);
		file.GetVarInt("Normal", "m_nLaserHandToLaserMoveCenPos", m_nLaserHandToLaserMoveCenPos);
		file.GetVarInt("Normal", "m_nUnLoadHandCheckCenPos", m_nUnLoadHandCheckCenPos);
		file.GetVarInt("Normal", "m_nUnLoadHandPassCenPos", m_nUnLoadHandPassCenPos);

		file.GetVarInt("Normal", "m_nLightUseTime", m_nLightUseTime);
		file.GetVarInt("Normal", "m_bHandLoadIn", m_bHandLoadIn);
		file.GetVarInt("Normal", "m_bUnLoadFreeDown", m_bUnLoadFreeDown);
		file.GetVarInt("Normal", "m_bHavePass", m_bHavePass);

		file.GetVarInt("Normal", "m_bPauseAllHandStop", m_bPauseAllHandStop);
	}
	else
		CMoveBase::LocalMessageBox(IDS_LOAD_SETTING_FAIL);


}

void CAL400Setting::Save()
{
	CString strPath = IBaseTool::GetAppPath();
	strPath += "\\Setting\\AL400Setting";

	CKmIniFile file;
	////////////////////////////////////////////////////////////////
	file.SetVarDou("Normal", "m_fScanDistPerStep", m_fScanDistPerStep);
	file.SetVarInt("Normal", "m_nYSpeedOfScan", m_nYSpeedOfScan);
	file.SetVarDou("Normal", "m_fStopToScanDist", m_fStopToScanDist);
	file.SetVarDou("Normal", "m_fScanTopToBotDist", m_fScanTopToBotDist);
	file.SetVarInt("Normal", "m_nTidyDelay", m_nTidyDelay);
	file.SetVarInt("Normal", "m_nBetweenDelay", m_nBetweenDelay);

	file.SetVarInt("Normal", "m_iHandSpeed", m_iHandSpeed);
	file.SetVarInt("Normal", "m_iHandAcc", m_iHandAcc);
	file.SetVarInt("Normal", "m_iUpdownSpeed", m_iUpdownSpeed);
	file.SetVarInt("Normal", "m_iUpdownAcc", m_iUpdownAcc);
	file.SetVarInt("Normal", "m_iLaserMoveSpeed", m_iLaserMoveSpeed);
	file.SetVarInt("Normal", "m_iLaserMoveAcc", m_iLaserMoveAcc);

	file.SetVarDou("Normal", "m_f2CCDScanTolTop", m_f2CCDScanTolTop);
	file.SetVarDou("Normal", "m_f2CCDScanTolBot", m_f2CCDScanTolBot);

	file.SetVarInt("Normal", "m_nLaserMoveInitPos", m_nLaserMoveInitPos);
	file.SetVarInt("Normal", "m_nLaserMoveCheckCenPos", m_nLaserMoveCheckCenPos);
	file.SetVarInt("Normal", "m_nLaserHandScanCenPos", m_nLaserHandScanCenPos);
	file.SetVarInt("Normal", "m_nLaserHandToLaserMoveCenPos", m_nLaserHandToLaserMoveCenPos);
	file.SetVarInt("Normal", "m_nUnLoadHandCheckCenPos", m_nUnLoadHandCheckCenPos);
	file.SetVarInt("Normal", "m_nUnLoadHandPassCenPos", m_nUnLoadHandPassCenPos);

	file.SetVarInt("Normal", "m_nLightUseTime", m_nLightUseTime);
	file.SetVarInt("Normal", "m_bHandLoadIn", m_bHandLoadIn);
	file.SetVarInt("Normal", "m_bUnLoadFreeDown", m_bUnLoadFreeDown);
	file.SetVarInt("Normal", "m_bHavePass", m_bHavePass);

	file.SetVarInt("Normal", "m_bPauseAllHandStop", m_bPauseAllHandStop);
	////////////////////////////////////////////////////////////////
	if (!file.WriteFile(strPath))
		CMoveBase::LocalMessageBox(IDS_SAVE_SETTING_FAIL);

}
