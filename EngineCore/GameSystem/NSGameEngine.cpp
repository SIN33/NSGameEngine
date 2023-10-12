
#include "NSGameEngine.h"
#include "Timer.h"
#include "D3D.h"
 
// �Q�[���̏����ݒ���s��
void NSGameEngine::Initialize()
{
	//Todo : set Direct X Or Open Gl
}
 
// �Q�[�����[�v���̃��C������
//���L�̏������s��
//�@1.�L�[���� ProcessInput()
//�@2.�Q�[���I�u�W�F�N�g�X�V UpdateGame()
//�@3.�`����o�� GenerateOutput() Direct X/ Open Gl�ɂ��o�b�N�o�b�t�@�`��@���@�Q�[���I�u�W�F�N�g�̕`��  �� �o�b�t�@�̐؂�ւ�
//  4. �����X�V�@Timer:;timeproc 

void NSGameEngine::Execute()
{
	//ProcessInput();

	//UpdateGame();

	//��GenerateOutput();
	//�����p�ADirectX�ɂ��`��(Rendering)
	//To do �����I�ɂ�Interface�����Open GL��DirectX��؂�ւ���悤�ɂ���
	float color[4] = { 0.2f, 0.2f, 0.8f, 1.0f }; //bule
	 // clear back buffer
	D3D.ClearRenderTargetView(color);

	// draw shader
    {
		struct VertexType
		{
			DirectX::XMFLOAT3 Pos;
		};

		//direct x�͍�����W�n
		//��{�I�ɂ́A���v���Ɏˉe���W��ݒ肷��B
		//����́A�v���~�e�B�u�g�|���W�[�ɂ��ύX�\
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

	//��GenerateOutput();

	auto timer = Timer();
	timer.TickProc();


}