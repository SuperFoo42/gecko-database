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

#include <frag_printer.h>

#define IMPL_COMPLETE(printer)                                                                                         \
    (printer->_print != NULL && printer->_free != NULL)                                                                \

void frag_printer_print(FILE *file, frag_printer_type_tag type, frag_t *frag, size_t row_offset, size_t limit)
{
    REQUIRE_NONNULL(file);
    REQUIRE_NONNULL(frag);

    size_t num_installed_printers = sizeof(frag_printer_register) / sizeof(frag_printer_register[0]);
    for (size_t i = 0; i < num_installed_printers; i++) {
        if (frag_printer_register[i].type == type) {
            frag_printer_t *printer = frag_printer_register[i].create();
            panic_if(!(IMPL_COMPLETE(printer)), BADINTERNAL, "fragment printer implementation is incomplete");
            printer->_print(printer, file, frag, row_offset, limit);
            printer->_free(printer);
            free (printer);
            return;
        }
    }
    panic(BADINTERNAL, "selected printer implementation is unknown");
}