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

namespace BaseLib
{
class ConfigTree;
}

namespace ChemistryLib
{
struct UserPunch
{
    UserPunch(std::string&& headline_, std::vector<std::string>&& statements_)
        : headline(headline_), statements(statements_)
    {
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    UserPunch const& user_punch);

    std::string const headline;
    std::vector<std::string> const statements;
};
}  // namespace ChemistryLib
