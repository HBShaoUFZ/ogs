/**
 * \copyright
 * Copyright (c) 2012-2019, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include "BaseLib/ConfigTree.h"
#include "UserPunch.h"

namespace ChemistryLib
{
std::unique_ptr<UserPunch> createUserPunch(
    boost::optional<BaseLib::ConfigTree> const& config)
{
    if (!config)
        return {};

    auto headline = config->getConfigParameter<std::string>("headline");

    std::vector<std::string> statements;
    auto const statements_config =
        //! \ogs_file_param{prj__chemical_system__user_punch__statements}
        config->getConfigSubtree("statements");
    for (
        auto const& statement :
        //! \ogs_file_param{prj__chemical_system__user_punch__statements__statement}
        statements_config.getConfigParameterList<std::string>("statement"))
        statements.push_back(statement);

    return std::make_unique<UserPunch>(std::move(headline),
                                       std::move(statements));
}
}  // namespace ChemistryLib
