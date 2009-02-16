/* ldap_casa.h
   
   Definition for CASA modules... */

/* Copyright (c) 2004 Internet Systems Consorium, Inc. ("ISC")
 * Copyright (c) 1995-2003 Internet Software Consortium.
 * Copyright (c) 2006 Novell, Inc.

 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met: 
 * 1.Redistributions of source code must retain the above copyright notice, 
 *   this list of conditions and the following disclaimer. 
 * 2.Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution. 
 * 3.Neither the name of ISC, ISC DHCP, nor the names of its contributors 
 *   may be used to endorse or promote products derived from this software 
 *   without specific prior written permission. 

 * THIS SOFTWARE IS PROVIDED BY INTERNET SYSTEMS CONSORTIUM AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL ISC OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.

 * This file was written by S Kalyanasundaram <skalyanasundaram@novell.com>
 */

#if defined(LDAP_CASA_AUTH)
#ifndef __LDAP_CASA_H__
#define __LDAP_CASA_H__

#include <micasa_mgmd.h>
#include <dlfcn.h>
#include <string.h>

#define MICASA_LIB     "libmicasa.so.1"

SSCS_TYPEDEF_LIBCALL(int, CASA_GetCredential_T)
(
       uint32_t            ssFlags,
       SSCS_SECRET_ID_T   *appSecretID,
       SSCS_SECRET_ID_T   *sharedSecretID,
       uint32_t           *credentialType,
       void               *credential,
       SSCS_EXT_T         *ext 
);
SSCS_TYPEDEF_LIBCALL(int, CASA_SetCredential_T)
(
       uint32_t            ssFlags,
       SSCS_SECRET_ID_T   *appSecretID,
       SSCS_SECRET_ID_T   *sharedSecretID,
       uint32_t            credentialType,
       void               *credential,
       SSCS_EXT_T         *ext
);

SSCS_TYPEDEF_LIBCALL(int, CASA_RemoveCredential_T)
(
       uint32_t            ssFlags,
       SSCS_SECRET_ID_T   *appSecretID,
       SSCS_SECRET_ID_T   *sharedSecretID,
       SSCS_EXT_T         *ext
);
static CASA_GetCredential_T            p_miCASAGetCredential = NULL;
static CASA_SetCredential_T            p_miCASASetCredential = NULL;
static CASA_RemoveCredential_T         p_miCASARemoveCredential = NULL;
static void                            *casaIDK = NULL;

int load_casa(void);
static void release_casa(void);
int load_uname_pwd_from_miCASA(char **, char **);

#endif /* __LDAP_CASA_H__ */
#endif /* LDAP_CASA_AUTH */

