/**
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#pragma once

#include <iosfwd>
#include <string>

namespace BaseLib
{
class ConfigTree;
}

namespace ChemistryLib
{
struct SurfaceSite
{
    SurfaceSite(std::string&& name_,
                double site_density_,
                double specific_area_,
                double mass_)
        : name(std::move(name_)),
          site_density(site_density_),
          specific_area(specific_area_),
          mass(mass_)
    {
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    SurfaceSite const& surface_site);

    std::string const name;
    double const site_density;
    double const specific_area;
    double mass;
};
}  // namespace ChemistryLib
