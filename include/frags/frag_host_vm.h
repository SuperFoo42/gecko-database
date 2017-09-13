// Copyright (C) 2017 Marcus Pinnecke
//
// This program is free software: you can redistribute it and/or modify it under the terms of the
// GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

// ---------------------------------------------------------------------------------------------------------------------
// I N C L U D E S
// ---------------------------------------------------------------------------------------------------------------------

#include <stdinc.h>
#include <schema.h>

// ---------------------------------------------------------------------------------------------------------------------
// T Y P E   F O R W A R D I N G S
// ---------------------------------------------------------------------------------------------------------------------

struct frag_t;

// ---------------------------------------------------------------------------------------------------------------------
// I N T E R F A C E   F U N C T I O N S
// ---------------------------------------------------------------------------------------------------------------------

struct frag_t *frag_host_vm_nsm_new(schema_t *schema, size_t tuplet_capacity);
struct frag_t *frag_host_vm_dsm_new(schema_t *schema, size_t tuplet_capacity);
