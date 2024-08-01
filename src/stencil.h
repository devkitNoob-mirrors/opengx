/*****************************************************************************
Copyright (c) 2011  David Guillen Fandos (david@davidgf.net)
Copyright (c) 2024  Alberto Mardegan (mardy@users.sourceforge.net)
All rights reserved.

Attention! Contains pieces of code from others such as Mesa and GRRLib

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of copyright holders nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#ifndef OPENGX_STENCIL_H
#define OPENGX_STENCIL_H

#include "opengx.h"

#include <malloc.h>
#include <stdbool.h>

extern OgxStencilFlags _ogx_stencil_flags;

void _ogx_stencil_enabled(void);
void _ogx_stencil_disabled(void);
void _ogx_stencil_update(void);
void _ogx_stencil_clear(void);

bool _ogx_stencil_setup_tev(int *stages, int *tex_coords, int tex_map);

/* This callback should draw the current primitive with no color, lighting or
 * textures */
typedef void (*OgxStencilDrawCallback)(void *data);
void _ogx_stencil_draw(OgxStencilDrawCallback callback, void *cb_data);

#endif /* OPENGX_STENCIL_H */