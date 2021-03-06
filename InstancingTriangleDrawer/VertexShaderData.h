#pragma once

#include <DirectXMath.h>

#include <ShaderResourcesManager/Buffer.h>
#include <Utils/Assert.h>

struct ID3D11Buffer;
struct ID3D11Device1;
struct ID3D11DeviceContext1;
struct ID3D11InputLayout;
struct ID3D11VertexShader;

namespace InstancingTriangleDrawer {
	class VertexShaderData {
	public:
		VertexShaderData();

		void PreDraw(ID3D11Device1& device, ID3D11DeviceContext1& context);
		void Draw(ID3D11DeviceContext1& context);
		void PostDraw(ID3D11DeviceContext1& context);

		DirectX::XMFLOAT4X4& WorldViewProjection() { return mCBuffer.mData.mWorldViewProjection; }

		ID3D11Buffer* &VertexBuffer() { return mVertexBuffer; }
		ID3D11Buffer* &IndexBuffer() { return mIndexBuffer; }
		ID3D11Buffer* &InstanceBuffer() { return mInstanceBuffer; }
		void SetIndicesCount(const unsigned int count) { mIndicesCount = count; }
		void SetInstancesCount(const unsigned int count) { mInstancesCount = count; }

	private:
		void InitializeShader();
		void InitializeCBuffers();

		ID3D11InputLayout* mInputLayout;
		ID3D11VertexShader* mShader;

		struct CBufferPerFrameData {
			DirectX::XMFLOAT4X4 mWorldViewProjection;
		};
		Buffer<CBufferPerFrameData> mCBuffer;

		ID3D11Buffer* mVertexBuffer;
		ID3D11Buffer* mIndexBuffer;
		ID3D11Buffer* mInstanceBuffer;
		unsigned int mIndicesCount;
		unsigned int mInstancesCount;
	};
}
