/**
 * \file
 *
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include "CreateBHE1U.h"
#include "BaseLib/ConfigTree.h"
#include "CreateFlowAndTemperatureControl.h"
namespace ProcessLib
{
namespace HeatTransportBHE
{
namespace BHE
{
BHE::BHE_1U createBHE1U(
    BaseLib::ConfigTree const& config,
    std::map<std::string,
             std::unique_ptr<MathLib::PiecewiseLinearInterpolation>> const&
        curves)
{
    // if the BHE is using python boundary condition
    bool bhe_if_use_python_bc = false;
    if (auto const bhe_if_use_python_bc_conf =
            config.getConfigParameterOptional<bool>(
                "bhe_if_use_python_bc"))
    {
        DBUG("If  using python boundary condition : %s",
             (*bhe_if_use_python_bc_conf) ? "true" : "false");
        bhe_if_use_python_bc = *bhe_if_use_python_bc_conf;
    }

    //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__borehole}
    auto const borehole_geometry =
        createBoreholeGeometry(config.getConfigSubtree("borehole"));

    //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__pipes}
    auto const& pipes_config = config.getConfigSubtree("pipes");
    //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__pipes__inlet}
    Pipe const inlet_pipe = createPipe(pipes_config.getConfigSubtree("inlet"));
    Pipe const outlet_pipe =
        //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__pipes__outlet}
        createPipe(pipes_config.getConfigSubtree("outlet"));
    const auto pipe_distance =
        //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__pipes__distance_between_pipes}
        pipes_config.getConfigParameter<double>("distance_between_pipes");
    const auto pipe_longitudinal_dispersion_length =
        //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__pipes__longitudinal_dispersion_length}
        pipes_config.getConfigParameter<double>(
            "longitudinal_dispersion_length");
    PipeConfiguration1U const pipes{inlet_pipe, outlet_pipe, pipe_distance,
                                    pipe_longitudinal_dispersion_length};

    //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__grout}
    auto const grout = createGroutParameters(config.getConfigSubtree("grout"));

    //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__refrigerant}
    auto const refrigerant =
        createRefrigerantProperties(config.getConfigSubtree("refrigerant"));

    auto const flowAndTemperatureControl = createFlowAndTemperatureControl(
        //! \ogs_file_param{prj__processes__process__HEAT_TRANSPORT_BHE__borehole_heat_exchangers__borehole_heat_exchanger__flow_and_temperature_control}
        config.getConfigSubtree("flow_and_temperature_control"),
        curves,
        refrigerant);

    return {borehole_geometry, refrigerant, grout, flowAndTemperatureControl, pipes, bhe_if_use_python_bc};
}
}  // namespace BHE
}  // namespace HeatTransportBHE
}  // namespace ProcessLib
