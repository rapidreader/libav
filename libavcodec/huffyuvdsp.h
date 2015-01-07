/*
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_HUFFYUVDSP_H
#define AVCODEC_HUFFYUVDSP_H

#include <stdint.h>

typedef struct HuffYUVDSPContext {
    void (*add_bytes)(uint8_t *dst /* align 16 */, uint8_t *src /* align 16 */,
                      int w);
    void (*add_hfyu_median_pred)(uint8_t *dst, const uint8_t *top,
                                 const uint8_t *diff, int w,
                                 int *left, int *left_top);
    int (*add_hfyu_left_pred)(uint8_t *dst, const uint8_t *src,
                              int w, int left);
    void (*add_hfyu_left_pred_bgr32)(uint8_t *dst, const uint8_t *src,
                                     int w, int *red, int *green,
                                     int *blue, int *alpha);
} HuffYUVDSPContext;

void ff_huffyuvdsp_init(HuffYUVDSPContext *c);
void ff_huffyuvdsp_init_ppc(HuffYUVDSPContext *c);
void ff_huffyuvdsp_init_x86(HuffYUVDSPContext *c);

#endif /* AVCODEC_HUFFYUVDSP_H */