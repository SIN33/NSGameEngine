
#include "NSGameEngine.h"
#include "Timer.h"
#include "D3D.h"
 
// ゲームの初期設定を行う
void NSGameEngine::Initialize()
{
	//Todo : set Direct X Or Open Gl
}
 
// ゲームループ内のメイン処理
//下記の処理を行う
//　1.キー操作 ProcessInput()
//　2.ゲームオブジェクト更新 UpdateGame()
//　3.描画情報出力 GenerateOutput() Direct X/ Open Glによるバックバッファ描画　→　ゲームオブジェクトの描画  → バッファの切り替え
//  4. 時刻更新　Timer:;timeproc 

void NSGameEngine::Execute()
{
	//ProcessInput();

	//UpdateGame();

	//▼GenerateOutput();
	//実験用、DirectXによる描画(Rendering)
	//To do 将来的にはInterfaceを介してOpen GLとDirectXを切り替えるようにする
	float color[4] = { 0.2f, 0.2f, 0.8f, 1.0f }; //bule
	 // clear back buffer
	D3D.ClearRenderTargetView(color);

	// draw shader
    {
		struct VertexType
		{
			DirectX::XMFLOAT3 Pos;
		};

		//direct xは左手座標系
		//基本的には、時計回りに射影座標を設定する。
		//動作は、プリミティブトポロジーにより変更可能
		//VertexType v[3] = {
		//	{{0,0,0}},
		//	{{1,-1,0}},
		//	{{-1,-1,0}},
		//};

		VertexType v[4] =
		{
			{{-0.5f, -0.5f, 0}},
			{{-0.5f,  0.5f, 0}},
			{{ 0.5f, -0.5f, 0}},
			{{ 0.5f,  0.5f, 0}},
		};
 
		//set vertexbuffer req info
		D3D11_BUFFER_DESC vbDesc = {};
		vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;	
		vbDesc.ByteWidth = sizeof(v);					
		vbDesc.MiscFlags = 0;							
		vbDesc.StructureByteStride = 0;					
		vbDesc.Usage = D3D11_USAGE_DEFAULT;				
		vbDesc.CPUAccessFlags = 0;
 
		ComPtr<ID3D11Buffer> vb;
		D3D11_SUBRESOURCE_DATA initData = { &v[0], sizeof(v), 0};	//written data 

		// create vertex buffe
		D3D.CreateBuffer(&vbDesc, &initData, &vb);
 
		UINT stride = sizeof(VertexType);
		UINT offset = 0;
		D3D.m_deviceContext->IASetVertexBuffers(0, 1, vb.GetAddressOf(), &stride, &offset);

		//set using vertexes
		D3D.m_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
 
		//Set Shader
		D3D.m_deviceContext->VSSetShader(D3D.m_spriteVS.Get(), 0, 0);
		D3D.m_deviceContext->PSSetShader(D3D.m_spritePS.Get(), 0, 0);
		D3D.m_deviceContext->IASetInputLayout(D3D.m_spriteInputLayout.Get());
 
 
		// execute draw
		D3D.m_deviceContext->Draw(4, 0);
 
	}

	// swap 
	D3D.PresentBySwapChain(1, 0);

	//▲GenerateOutput();

	auto timer = Timer();
	timer.TickProc();


}