#include "../../D3DUtilTools.h"

using namespace DirectX;
class Camera 
{
public:
	Camera();
	~Camera() = default;

	void setPosition(float, float, float);
	XMFLOAT3 getPosition() const;

	void setRotation(float, float, float);
	XMFLOAT3 getRotation() const;

	void move(float, float, float);
	void rotate(float, float, float);

	void render();
	void frame(float frameTime);

	void getViewMatrix(XMFLOAT4X4&) const ;
	void getProjectionMatrix(XMFLOAT4X4&) const;

private:
	float sensitivity;
	float moveSpeed;
	float yaw;
	float pitch;
	float roll;
	XMFLOAT3 forward;
	XMFLOAT3	right;
	XMFLOAT3 up;
	XMFLOAT3 lookAt;
	XMFLOAT3 position;
	XMFLOAT3 rotation;
	XMFLOAT3 velocity;
	XMFLOAT4X4 viewMatrix;
	XMFLOAT4X4 projectionMatrix;
};