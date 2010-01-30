/*
 * Copyright (c) 2010 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_BSD_LICENSE_HEADER_START@
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @APPLE_BSD_LICENSE_HEADER_END@
 */

#include <string.h>
#include <stdlib.h>
#include "Column.h"

Column::Column() {
	m_name      = strdup("unnamed_column");
	m_type      = SQLITE_INTEGER;
	m_is_index  = false;
	m_is_pk     = false;
	m_is_unique = false;
}

Column::Column(const char* name, uint32_t type) {
	m_name      = strdup(name);
	m_type      = type;
	m_is_index  = false;
	m_is_pk     = false;
	m_is_unique = false;
}

Column::Column(const char* name, uint32_t type, bool is_index, bool is_pk, bool is_unique) {
	m_name      = strdup(name);
	m_type      = type;
	m_is_index  = is_index;
	m_is_pk     = is_pk;
	m_is_unique = is_unique;
}

Column::~Column() {
	free(m_name);
}

const char* Column::name() {
	return m_name;
}

const int Column::type() {
	return m_type;
}

const bool Column::is_index() {
	return m_is_index;
}

const bool Column::is_pk() {
	return m_is_pk;
}

const bool Column::is_unique() {
	return m_is_unique;
}

