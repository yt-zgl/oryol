#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::d3d11Mesh
    @ingroup _priv
    @brief D3D11 implementation of mesh

    NOTE: in the D3D11 renderer, the vertex layout (== input layout object)
    is part of the drawState, since it needs to match the shader
*/
#include "Gfx/Resource/meshBase.h"
#include "Gfx/d3d11/d3d11_decl.h"

namespace Oryol {
namespace _priv {

class d3d11Mesh : public meshBase {
public:
    /// constructor
    d3d11Mesh();
    /// destructor
    ~d3d11Mesh();

    /// clear the object (called from meshFactory::DestroyResource())
    void Clear();

    /// pointer to vertex buffer object
    ID3D11Buffer* d3d11VertexBuffer;
    /// pointer to index buffer object
    ID3D11Buffer* d3d11IndexBuffer;
    /// optional instance data mesh
    const d3d11Mesh* instanceMesh;
};

} // namespace _priv
} // namespace Oryol