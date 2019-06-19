/**
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include <ostream>

#include "Knobs.h"

namespace ChemistryLib
{
std::ostream& operator<<(std::ostream& os, Knobs const& knobs)
{
    os << "-iterations " << knobs.max_iterations << "\n";
    os << "-convergence_tolerance  " << knobs.relative_convergence_tolerance
       << "\n";
    os << "-tolerance " << knobs.tolerance << "\n";
    os << "-step_size " << knobs.step_size << "\n";
    os << "-diagonal_scale " << knobs.scaling << "\n";

    return os;
}
}  // namespace ChemistryLib
