/*
 * Basic Excel R Toolkit (BERT)
 * Copyright (C) 2014 Structured Data, LLC
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef __RINTERFACE_H
#define __RINTERFACE_H

#include "XLCALL.H"
#include "util.h"

#define MAX_LOGLIST_SIZE	80

typedef std::vector< std::string > SVECTOR;
typedef std::vector< SVECTOR > FDVECTOR;

extern FDVECTOR RFunctions;

void RInit();
void RShutdown();

LPXLOPER12 RExec(LPXLOPER12 code);
bool RExec2(LPXLOPER12 rslt, std::string &funcname, std::vector< LPXLOPER12 > &args);
void RExecVector(std::vector < std::string > &vec, int *err = 0, PARSE_STATUS_2 *parseErr = 0, bool printResult = true);
int UpdateR(std::string &str);
void MapFunctions();
void LoadStartupFile();

short InstallPackages();

#endif // #ifndef __RINTERFACE_H