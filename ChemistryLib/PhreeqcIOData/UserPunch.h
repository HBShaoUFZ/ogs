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
#include <vector>

#include "ChemistryLib/Output.h"

namespace BaseLib
{
class ConfigTree;
}

namespace ChemistryLib
{
struct SecondaryVariable
{
    SecondaryVariable(std::string&& name_) : name(std::move(name_)) {}

    std::string const name;
    double value = std::numeric_limits<double>::quiet_NaN();
    static const ItemType item_type = ItemType::SecondaryVariable;
};

struct UserPunch
{
    UserPunch(
        std::vector<std::vector<SecondaryVariable>>&& secondary_variables_,
        std::vector<std::string>&& statements_)
        : secondary_variables(secondary_variables_), statements(statements_)
    {
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    UserPunch const& user_punch);

    std::vector<std::vector<SecondaryVariable>> secondary_variables;
    std::vector<std::string> const statements;
};
}  // namespace ChemistryLib
