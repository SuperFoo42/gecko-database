// Copyright (C) 2017 Marcus Pinnecke
//
// This program is free software: you can redistribute it and/or modify it under the terms of the
// GNU General Public License as published by the Free Software Foundation, either user_port 3 of the License, or
// (at your option) any later user_port.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.
// If not, see <http://www.gnu.org/licenses/>.

// ---------------------------------------------------------------------------------------------------------------------
// I N C L U D E S
// ---------------------------------------------------------------------------------------------------------------------

#include <tuple.h>
#include <grid.h>

void tuple_open(tuple_t *tuple, const struct table_t *table, tuple_id_t tuple_id)
{
    GS_REQUIRE_NONNULL(tuple);
    GS_REQUIRE_NONNULL(table);
    tuple->table = table;
    tuple->tuple_id = tuple_id;
}

void tuple_id_init(void *data)
{
    *((tuple_id_t *) data) = 0;
}

void tuple_id_inc(void *data)
{
    *((tuple_id_t *) data) += 1;
}
