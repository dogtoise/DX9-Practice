#include "stdafx.h"
#include "MainApp.h"
#include "CGraphicDevice.h"

#include "Triangle.h"
#include "Cube.h"
CMainApp::CMainApp()
	: m_pGraphicDevice(CGraphicDevice::Get())
{

}


CMainApp::~CMainApp()
{
	
}

HRESULT CMainApp::ReadyMainApp()
{
	if (m_pGraphicDevice->ReadyGraphicDevice(CGraphicDevice::MODE_WIN, g_hWnd))
	{
		return E_FAIL;
	}
	cube = new Cube();
	cube->Setup();
	
	return S_OK;
}

void CMainApp::UpdateMainApp()
{
}

void CMainApp::LateUpdateMainApp()
{
}

void CMainApp::RenderMainApp()
{
	m_pGraphicDevice->RenderBegin();
	//triangle->Display(0);
	cube->Display();
	m_pGraphicDevice->RenderEnd();
}

void CMainApp::ReleaseMainApp()
{
	m_pGraphicDevice->Destroy();
	//triangle->Cleanup();
	cube->Cleanup();
}
