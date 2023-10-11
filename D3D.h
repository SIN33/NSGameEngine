#pragma once
 
#include "D3DUtilTools.h"
#include "CommonTools.h"

//can set comptr
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;
 

//MACRO (Šy‚É‚·‚é‚½‚ß)
#define D3D Direct3D::GetInstance()

//=========================================
// Direct3D class 
// singleton class
//=========================================
class Direct3D : public Singleton<Direct3D> //CRTP
{
	friend class Singleton<Direct3D>;

public:
	//members

   // Direct3D device
	ComPtr<ID3D11Device>		m_device;
	// Direct3D device context
	ComPtr<ID3D11DeviceContext>	m_deviceContext;
	// swap chain (switch current buffer back buffer)
	ComPtr<IDXGISwapChain>		m_swapChain;
	// swap chain view (handle back buffer)
	ComPtr<ID3D11RenderTargetView> m_backBufferView;


private:
	Direct3D() = default;

public:
	static Direct3D* CreateInstance() //override
	{
		return new Direct3D();
	}

public:
	void ClearRenderTargetView(const FLOAT* Color)
	{
		D3D.m_deviceContext->ClearRenderTargetView(D3D.m_backBufferView.Get(), Color);
	}

	void CreateBuffer(const D3D11_BUFFER_DESC* vbDesc, const D3D11_SUBRESOURCE_DATA* initData, ID3D11Buffer** vb)
	{
		D3D.m_device->CreateBuffer(vbDesc, initData, vb);
	}

	void  PresentBySwapChain(UINT SyncInterval, UINT Flags = 0)
	{
		D3D.m_swapChain->Present(SyncInterval, Flags);
	}


	bool Initialize(HWND hWnd, int width, int height);

	// Shader for 2D
	ComPtr<ID3D11VertexShader>	m_spriteVS = nullptr;	// vertex shader
	ComPtr<ID3D11PixelShader>	m_spritePS = nullptr;	// pixcel shader
	ComPtr<ID3D11InputLayout>	m_spriteInputLayout = nullptr;// input layout
};

