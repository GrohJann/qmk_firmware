/* Copyright 2019 Thomas Baart
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#pragma once

#include "quantum.h"

#define LAYOUT_ortho_4x3( \
    K00, K01, K02, \
    K03, K04, K05, \
    K06, K07, K08, \
    K09, K10, K11  \
   ) { \
    {K00, K01, K02}, \
    {K03, K04, K05}, \
    {K06, K07, K08}, \
    {K09, K10, K11} }

#define LAYOUT_ortho_encoder( \
    K00, K01, K02, K03, K04, \
    K05, K06, K07, \
    K08, K09, K10, \
    K11, K12, K13 \
   ) { \
    {K00, K01, K02, K03, K04}, \
    {K05, K06, K07, KC_NO, KC_NO}, \
    {K08, K09, K10, KC_NO, KC_NO}, \
    {K11, K12, K13, KC_NO, KC_NO} }