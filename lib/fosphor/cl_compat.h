/*
 * cl_compat.h
 *
 * Handle OpenCL 1.1 <> 1.2 fallback and the related uglyness
 *
 * Copyright (C) 2013-2014 Sylvain Munaut
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __FOSPHOR_CL_COMPAT_H__
#define __FOSPHOR_CL_COMPAT_H__

/*! \ingroup cl
 * @{
 */

/*! \file cl_compat.h
 *  \brief Handle OpenCL 1.1 <> 1.2 fallback and the related uglyness
 */

#include "cl_platform.h"
#include "gl_platform.h"


/* Define NVidia specific attributes */
#ifndef CL_DEVICE_COMPUTE_CAPABILITY_MAJOR_NV
# define CL_DEVICE_COMPUTE_CAPABILITY_MAJOR_NV	0x4000
# define CL_DEVICE_COMPUTE_CAPABILITY_MINOR_NV	0x4001
#endif


/* If OpenCL 1.2 isn't supported in the header, add our prototypes */
#ifndef CL_VERSION_1_2

cl_mem
clCreateFromGLTexture(cl_context context,
                      cl_mem_flags flags,
                      GLenum texture_target,
                      GLint miplevel,
                      GLuint texture,
                      cl_int *errcode_ret);

#endif


/* The actual API */
void cl_compat_init(void);
void cl_compat_check_platform(cl_platform_id pl_id);


/*! @} */

#endif /* __FOSPHOR_CL_COMPAT_H__ */