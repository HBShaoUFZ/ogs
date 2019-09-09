/**
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include <ostream>

#include "AqueousSolution.h"

namespace ChemistryLib
{
void AqueousSolution::output(std::size_t const& chemical_system_id,
                             std::ostream& os) const
{
    os << "SOLUTION " << 2 * chemical_system_id + 1 << "\n";

    os << "temp " << temperature << "\n";

    os << "pressure " << pressure << "\n";

    switch (means_of_adjusting_charge)
    {
        case MeansOfAdjustingCharge::pH:
            os << "pH " << pH << " charge"
               << "\n";
            os << "pe " << pe << "\n";
            break;
        case MeansOfAdjustingCharge::pe:
            os << "pH " << pH << "\n";
            os << "pe " << pe << " charge"
               << "\n";
            break;
        case MeansOfAdjustingCharge::Unspecified:
            os << "pH " << pH_prev << "\n";
            //            os << "pe " << aqueous_solution.pe << "\n";
            break;
    }

    os << "units mol/kgw\n";

    for (auto const& component : components)
    {
        os << component.name << " " << component.amount_prev << "\n";
    }

    os << "\n";

    os << "SOLUTION " << 2 * chemical_system_id + 2 << "\n";

    os << "temp " << temperature << "\n";

    os << "pressure " << pressure << "\n";

    switch (means_of_adjusting_charge)
    {
        case MeansOfAdjustingCharge::pH:
            os << "pH " << pH << " charge"
               << "\n";
            os << "pe " << pe << "\n";
            break;
        case MeansOfAdjustingCharge::pe:
            os << "pH " << pH << "\n";
            os << "pe " << pe << " charge"
               << "\n";
            break;
        case MeansOfAdjustingCharge::Unspecified:
            os << "pH " << pH << "\n";
            //            os << "pe " << aqueous_solution.pe << "\n";
            break;
    }

    os << "units mol/kgw\n";

    for (auto const& component : components)
    {
        os << component.name << " " << component.amount << "\n";
    }

    os << "\n";
}

std::ostream& operator<<(std::ostream& os,
                         AqueousSolution const& aqueous_solution)
{
    os << "temp " << aqueous_solution.temperature << "\n";

    os << "pressure " << aqueous_solution.pressure << "\n";

    switch (aqueous_solution.means_of_adjusting_charge)
    {
        case MeansOfAdjustingCharge::pH:
            os << "pH " << aqueous_solution.pH << " charge"
               << "\n";
            os << "pe " << aqueous_solution.pe << "\n";
            break;
        case MeansOfAdjustingCharge::pe:
            os << "pH " << aqueous_solution.pH << "\n";
            os << "pe " << aqueous_solution.pe << " charge"
               << "\n";
            break;
        case MeansOfAdjustingCharge::Unspecified:
            os << "pH " << aqueous_solution.pH << "\n";
//            os << "pe " << aqueous_solution.pe << "\n";
            break;
    }

    os << "units mol/kgw\n";

    for (auto const& component : aqueous_solution.components)
    {
        os << component.name << " " << component.amount << "\n";
    }

    return os;
}
}  // namespace ChemistryLib
