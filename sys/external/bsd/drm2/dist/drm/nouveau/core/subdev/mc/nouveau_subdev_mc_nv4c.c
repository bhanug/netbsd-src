/*	$NetBSD: nouveau_subdev_mc_nv4c.c,v 1.1.1.1 2014/08/06 12:36:31 riastradh Exp $	*/

/*
 * Copyright 2014 Ilia Mirkin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ilia Mirkin
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: nouveau_subdev_mc_nv4c.c,v 1.1.1.1 2014/08/06 12:36:31 riastradh Exp $");

#include "nv04.h"

static void
nv4c_mc_msi_rearm(struct nouveau_mc *pmc)
{
	struct nv04_mc_priv *priv = (void *)pmc;
	nv_wr08(priv, 0x088050, 0xff);
}

struct nouveau_oclass *
nv4c_mc_oclass = &(struct nouveau_mc_oclass) {
	.base.handle = NV_SUBDEV(MC, 0x4c),
	.base.ofuncs = &(struct nouveau_ofuncs) {
		.ctor = nv04_mc_ctor,
		.dtor = _nouveau_mc_dtor,
		.init = nv44_mc_init,
		.fini = _nouveau_mc_fini,
	},
	.intr = nv04_mc_intr,
	.msi_rearm = nv4c_mc_msi_rearm,
}.base;
