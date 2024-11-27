/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/***************************************************************************
 *   Copyright (C) 2009 by VisualData                                      *
 *                                                                         *
 *   Redistributed under LGPL license terms.                               *
 ***************************************************************************/

#ifndef _SEGVCATCH_H
#define	_SEGVCATCH_H

/*! \brief segvcatch namespace


*/
namespace segvcatch
{

/*! Signal handler, used to redefine standart exception throwing. */
typedef void (*handler)();

/*! Initialize segmentation violation handler.
    \param h (optional) - optional user's signal handler. By default used an internal signal handler to throw
 std::runtime_error.
   */
void init_segv(handler h = 0);

/*! Initialize floating point error handler.
    \param h - optional user's signal handler. By default used an internal signal handler to throw
 std::runtime_error.*/
void init_fpe(handler h = 0);

}

#endif	/* _SEGVCATCH_H */