/* The ctok object (implements a config file tokenizer).
 *
 * Copyright 2008 Rainer Gerhards and Adiscon GmbH.
 *
 * This file is part of rsyslog.
 *
 * Rsyslog is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Rsyslog is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Rsyslog.  If not, see <http://www.gnu.org/licenses/>.
 *
 * A copy of the GPL can be found in the file "COPYING" in this distribution.
 */
#ifndef INCLUDED_CTOK_H
#define INCLUDED_CTOK_H

#include "obj.h"
#include "stringbuf.h"
#include "ctok_token.h"

/* the ctokession object */
typedef struct ctok_s {
	BEGINobjInstance;	/* Data to implement generic object - MUST be the first data element! */
	uchar *pp;		/* this points to the next unread character, it is a reminescent of pp in
				   the config parser code ;) */
	ctok_token_t *pUngotToken; /* buffer for ctokUngetToken(), NULL if not set */
} ctok_t;


/* prototypes */
rsRetVal ctokConstruct(ctok_t **ppThis);
rsRetVal ctokConstructFinalize(ctok_t __attribute__((unused)) *pThis);
rsRetVal ctokDestruct(ctok_t **ppThis);
rsRetVal ctokGetpp(ctok_t *pThis, uchar **pp);
rsRetVal ctokGetToken(ctok_t *pThis, ctok_token_t **ppToken);
rsRetVal ctokUngetToken(ctok_t *pThis, ctok_token_t *pToken);
PROTOTYPEObjClassInit(ctok);
PROTOTYPEpropSetMeth(ctok, pp, uchar*);

#endif /* #ifndef INCLUDED_CTOK_H */
