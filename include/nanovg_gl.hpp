#pragma once

#include "nanovg.hpp"
#include "cinder/gl/gl.h"
#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"

namespace cinder { namespace nvg {

Context createContextGL(bool antiAlias = true, bool stencilStrokes = false) {
  int flags = (antiAlias      ? NVG_ANTIALIAS       : 0) |
              (stencilStrokes ? NVG_STENCIL_STROKES : 0);

  return { Context::BackingCtx{ nvgCreateGL3(flags), nvgDeleteGL3 } };
}
  
}} // cinder::nvg