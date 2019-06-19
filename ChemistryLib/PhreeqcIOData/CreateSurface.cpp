/**
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include "BaseLib/ConfigTree.h"
#include "Surface.h"

namespace ChemistryLib
{
std::vector<SurfaceSite> createSurface(
    boost::optional<BaseLib::ConfigTree> const& config)
{
    if (!config)
        return {};

    std::vector<SurfaceSite> surface;
    for (auto const& surface_site_config :
         //! \ogs_file_param{prj__chemical_system__surface__surface_site}
         config->getConfigSubtreeList("surface_site"))
    {
        //! \ogs_file_param{prj__chemical_system__surface__surface_site__name}
        auto name = surface_site_config.getConfigParameter<std::string>("name");

        auto const site_density =
            //! \ogs_file_param{prj__chemical_system__surface__surface_site__site_density}
            surface_site_config.getConfigParameter<double>("site_density");

        auto const specific_area =
            //! \ogs_file_param{prj__chemical_system__surface__surface_site__specific_area}
            surface_site_config.getConfigParameter<double>("specific_area");

        auto const mass =
            //! \ogs_file_param{prj__chemical_system__surface__surface_site__mass}
            surface_site_config.getConfigParameter<double>("mass");

        surface.emplace_back(
            std::move(name), site_density, specific_area, mass);
    }

    return surface;
}
}  // namespace ChemistryLib
