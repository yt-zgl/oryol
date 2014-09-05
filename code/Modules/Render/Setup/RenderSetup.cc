//------------------------------------------------------------------------------
//  RenderSetup.cc
//------------------------------------------------------------------------------
#include "Pre.h"
#include "RenderSetup.h"
#include "Core/Assert.h"

namespace Oryol {
namespace Render {
    
using namespace Core;
    
//------------------------------------------------------------------------------
RenderSetup::RenderSetup() :
registryCapacity(1024) {
    for (int32 i = 0; i < ResourceType::NumResourceTypes; i++) {
        this->poolSizes[i] = DefaultPoolSize;
        this->throttling[i] = 0;    // unthrottled
    }
}

//------------------------------------------------------------------------------
RenderSetup
RenderSetup::Windowed(int32 w, int32 h, String title) {
    o_assert((w > 0) && (h > 0));

    RenderSetup setup;
    setup.WindowWidth       = w;
    setup.WindowHeight      = h;
    setup.FramebufferWidth  = w;
    setup.FramebufferHeight = h;
    setup.IsFullscreen      = false;
    setup.WindowTitle       = title;
    return setup;
}

//------------------------------------------------------------------------------
RenderSetup
RenderSetup::Fullscreen(int32 w, int32 h, String title) {
    o_assert((w > 0) && (h > 0));
    
    RenderSetup setup;
    setup.WindowWidth       = w;
    setup.WindowHeight      = h;
    setup.FramebufferWidth  = w;
    setup.FramebufferHeight = h;
    setup.IsFullscreen      = true;
    setup.WindowTitle       = title;
    return setup;
}

//------------------------------------------------------------------------------
DisplayAttrs
RenderSetup::GetDisplayAttrs() const {
    return (DisplayAttrs) *this;
}

//------------------------------------------------------------------------------
void
RenderSetup::SetPoolSize(ResourceType::Code type, int32 size) {
    o_assert_range(type, ResourceType::NumResourceTypes);
    o_assert(size > 0);
    this->poolSizes[type] = size;
}
    
//------------------------------------------------------------------------------
int32
RenderSetup::PoolSize(ResourceType::Code type) const {
    o_assert_range(type, ResourceType::NumResourceTypes);
    return this->poolSizes[type];
}
    
//------------------------------------------------------------------------------
void
RenderSetup::SetThrottling(ResourceType::Code type, int32 maxCreatePerFrame) {
    o_assert_range(type, ResourceType::NumResourceTypes);
    this->throttling[type] = maxCreatePerFrame;
}
    
//------------------------------------------------------------------------------
int32
RenderSetup::Throttling(ResourceType::Code type) const {
    o_assert_range(type, ResourceType::NumResourceTypes);
    return this->throttling[type];
}
    
//------------------------------------------------------------------------------
void
RenderSetup::SetResourceRegistryCapacity(int32 capacity) {
    o_assert(capacity > 0);
    this->registryCapacity = capacity;
}
    
//------------------------------------------------------------------------------
int32
RenderSetup::ResourceRegistryCapacity() const {
    return this->registryCapacity;
}

} // namespace Render
} // namespace Oryol
