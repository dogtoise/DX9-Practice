#include "stdafx.h"
#include "MainApp.h"
#include "CGraphicDevice.h"

#include "Triangle.h"
#include "Cube.h"
#include "Teapot.h"
#include "DemoManager.h"
#include "MeshesDemo.h"
#include "ColorTriangle.h"

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
	//cube = new Cube();
	//cube->Setup();
	//teapot = new Teapot();
	//teapot->Setup();
	demoManager = new DemoManager();
	// todo : demoManager->push(new Teapot)
	//demoManager->Push(new MeshesDemo());
	demoManager->Push(new ColorTriangle());
	demoManager->SetupDemo();

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
	//cube->Display();
	//teapot->Display();
	demoManager->DisplayDemo();
	m_pGraphicDevice->RenderEnd();
}

void CMainApp::ReleaseMainApp()
{
	m_pGraphicDevice->Destroy();
	//triangle->Cleanup();
	//cube->Cleanup();
	//teapot->Cleanup();
	demoManager->CleanupDemo();
}
