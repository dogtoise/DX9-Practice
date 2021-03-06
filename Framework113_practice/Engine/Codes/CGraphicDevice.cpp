#include "Engine.h"
#include "CGraphicDevice.h"

CGraphicDevice* CGraphicDevice::m_pInstance = nullptr;

CGraphicDevice::CGraphicDevice()
{
}

CGraphicDevice::CGraphicDevice(const CGraphicDevice & rObject)
{
	ReleaseGraphicDevice();
}

HRESULT CGraphicDevice::ReadyGraphicDevice(WINMODE eMode, HWND hWnd)
{
	// 장치의 지원 수준을 조사해서 데이터를 보관할 구조체. 
		// 외울 필요는 개뿔. 없음. 
	D3DCAPS9 DeviceCap;
	ZeroMemory(&DeviceCap, sizeof(D3DCAPS9));
	m_pSDK = Direct3DCreate9(D3D_SDK_VERSION);

	if (FAILED(m_pSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &DeviceCap)))
	{
		return E_FAIL;
	}
	DWORD vp = 0;
	// vVERTEXPROCESSING - 정점 변환 + 조명연산을 합쳐 버텍스 프로세싱이라 부름. 
	// 이거 같은 경우에는 대부분의 컴퓨터에서 제공이 되니 원래 else 자체가 필요 없는 문구이기도 하지만 .
	// 혹시나라는게 역시나라는 것이 될 수도 있기 때문에. 
	// 조명연산과 정점 변환을 하드웨어(장치에서)에서 처리할 것인지 아니면 개발자가 소프트웨어(니네 게임)에서 처리할 것인지를 뜻한다. 
	if (DeviceCap.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp |= D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED;
	else
		vp |= D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	d3dpp.BackBufferWidth = 800;
	d3dpp.BackBufferHeight = 600;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;// 여기서 1은 총 2개의 백버퍼를 사용하겠다. 즉 디폴트로 한개 생김. 거기에 +1 임 

	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; // 스왑 체인 방식을 사용하겠다. -> 더블버퍼링의 상위 호환버전. 
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.Windowed = TRUE;// TRUE일 경우 창모드, FALSE일 경우 전체화면 모드 MFC에선 창모드로 사용. 
	d3dpp.EnableAutoDepthStencil = eMode;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;


	if (FAILED(m_pSDK->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, vp, &d3dpp, &m_pDevice)))
	{
		return E_FAIL;
	}
	if (FAILED(D3DXCreateSprite(m_pDevice, &m_pSprite)))
	{
		return E_FAIL;
	}
	D3DXFONT_DESCW tFontInfo;
	ZeroMemory(&tFontInfo, sizeof(D3DXFONT_DESCW));
	tFontInfo.Height = 20;
	tFontInfo.Width = 10;
	tFontInfo.Weight = FW_HEAVY;
	tFontInfo.CharSet = HANGUL_CHARSET;
	lstrcpy(tFontInfo.FaceName, L"맑은 고딕");

	if (FAILED(D3DXCreateFontIndirect(m_pDevice, &tFontInfo, &m_pFont)))
	{
		return E_FAIL;
	}
	if (FAILED(D3DXCreateLine(m_pDevice, &m_pLine)))
	{
		return E_FAIL;
	}

	return S_OK;
}

void CGraphicDevice::ReleaseGraphicDevice()
{
	if (m_pFont)
		m_pFont->Release();
	if (m_pSprite)
		m_pSprite->Release();
	if (m_pDevice)
		m_pDevice->Release();
	if (m_pSDK)
		m_pSDK->Release();
}



void CGraphicDevice::RenderBegin()
{
	m_pDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(255, 0, 0, 255), 1.f, 0);
	m_pDevice->BeginScene();
	//m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void CGraphicDevice::RenderEnd(HWND hWnd)
{
	m_pDevice->EndScene();
	m_pDevice->Present(nullptr, nullptr, hWnd, nullptr);
}
