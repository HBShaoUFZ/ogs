/**
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include <ostream>

#include "EquilibriumPhase.h"

namespace ChemistryLib
{
void EquilibriumPhase::print(std::ostream& os,
                             std::size_t const chemical_system_id) const
{
    os << "EQUILIBRIUM_PHASES " << 2 * chemical_system_id + 1 << "\n";

    os << name << " " << saturation_index << " "
       << (*amount_prev)[chemical_system_id] << "\n";

    os << "\n";

    os << "EQUILIBRIUM_PHASES " << 2 * chemical_system_id + 2 << "\n";

    os << name << " " << saturation_index << " "
       << (*amount)[chemical_system_id] << "\n";

    os << "\n";
}
}  // namespace ChemistryLib
