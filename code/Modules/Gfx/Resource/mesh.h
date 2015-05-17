#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::Mesh
    @ingroup _priv
    @brief geometry mesh for rendering
    
    A Mesh object holds one or more vertex buffers, an optional 
    index buffer, and one or more primitive groups.
    @todo: describe mesh creation etc...
*/
#if ORYOL_OPENGL
#include "Gfx/gl/glMesh.h"
namespace Oryol {
namespace _priv {
class mesh : public glMesh { };
} }
#elif ORYOL_D3D11
#include "Gfx/Resource/meshBase.h"
namespace Oryol {
namespace _priv {
class mesh : public meshBase { };
} }
#else
#error "Target platform not yet supported!"
#endif
