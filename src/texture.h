/*****************************************************************************
Copyright (c) 2025  Alberto Mardegan (mardy@users.sourceforge.net)
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

#ifndef OPENGX_TEXTURE_H
#define OPENGX_TEXTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <GL/gl.h>
#include <stdbool.h>
#include <stdint.h>

/* The GX API allow storing a void * for user data into the GXTexObj; but for
 * now we don't need a pointer, just some bits of information. Let's store them
 * in the space reserved for the pointer, then. */
typedef union {
    void *ptr;
    struct {
        unsigned is_reserved: 1;
        unsigned is_alpha: 1;
    } d;
} OgxTextureUserData;

#define TEXTURE_USER_DATA(texobj) \
    ((OgxTextureUserData)GX_GetTexObjUserData(texobj))
#define TEXTURE_IS_USED(texture) \
    (GX_GetTexObjData(&texture.texobj) != NULL)
#define TEXTURE_IS_RESERVED(texture) \
    (TEXTURE_USER_DATA(&texture.texobj).d.is_reserved)
#define TEXTURE_RESERVE(texture) \
    { \
        GX_InitTexObj(&(texture).texobj, NULL, 0, 0, 0, \
                      GX_REPEAT, GX_REPEAT, 0); \
        OgxTextureUserData ud = { .ptr = NULL }; \
        ud.d.is_reserved = 1; \
        GX_InitTexObjUserData(&(texture).texobj, ud.ptr); \
    }

typedef struct {
    void *texels;
    uint16_t width, height;
    uint8_t format, wraps, wrapt, mipmap;
    uint8_t min_filter, mag_filter;
    uint8_t minlevel, maxlevel;
    OgxTextureUserData ud;
} OgxTextureInfo;

bool _ogx_texture_get_info(GLuint texture_name, OgxTextureInfo *info);

#ifdef __cplusplus
} // extern C
#endif

#endif /* OPENGX_TEXTURE_H */
