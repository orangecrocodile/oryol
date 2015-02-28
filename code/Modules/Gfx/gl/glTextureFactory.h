#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::glTextureFactory
    @ingroup _priv
    @brief private: GL implementation of textureFactory
*/
#include "IO/Stream/Stream.h"
#include "Gfx/Resource/texture.h"
#include "Resource/Core/ResourceStreamTarget.h"

namespace Oryol {
namespace _priv {

class renderer;
class texture;
class textureLoaderBase;
class displayMgr;
class texturePool;
    
class glTextureFactory {
public:
    /// constructor
    glTextureFactory();
    /// destructor
    ~glTextureFactory();
    
    /// setup with a pointer to the state wrapper object
    void Setup(class renderer* rendr, displayMgr* displayMgr, texturePool* texPool);
    /// discard the factory
    void Discard();
    /// return true if the object has been setup
    bool IsValid() const;

    /// setup resource
    bool SetupResource(texture& tex);
    /// setup with input data
    bool SetupResource(texture& tex, const Ptr<Stream>& data);
    /// multi-threaded resource setup
    bool InitResourceThreaded(int32 threadIndex, texture& tex, const Ptr<Stream>& data);
    /// discard the resource
    void DestroyResource(texture& tex);
    
    /// generate a new GL texture and bind to texture unit 0 (called by texture loaders)
    GLuint glGenAndBindTexture(GLenum target);

private:
    /// create a render target
    bool createRenderTarget(texture& tex);
    /// create texture from raw pixel data
    bool createFromPixelData(texture& tex, const Ptr<Stream>& data);

    class renderer* renderer;
    displayMgr* displayManager;
    texturePool* texPool;
    bool isValid;
};
    
} // namespace _priv
} // namespace Oryol

