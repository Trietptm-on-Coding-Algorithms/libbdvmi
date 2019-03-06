// Copyright (c) 2015-2019 Bitdefender SRL, All rights reserved.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3.0 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library.

#ifndef __BDVMIDOMAINHANDLER_H_INCLUDED__
#define __BDVMIDOMAINHANDLER_H_INCLUDED__

#include <string>

namespace bdvmi {

class DomainHandler {

public:
	// base class, so virtual destructor
	virtual ~DomainHandler() = default;

public:
	virtual void handleDomainFound( const std::string &uuid, const std::string &name ) = 0;

	virtual void handleDomainFinished( const std::string &uuid ) = 0;

	// For those backends capable of figuring this out, if introspection is stopped as a
	// consequence of suspending the domain in which introspection is running then
	// suspendIntrospectorDomain will be true.
	virtual void cleanup( bool suspendIntrospectorDomain = false ) = 0;
};

} // namespace bdvmi

#endif // __BDVMIDOMAINHANDLER_H_INCLUDED__
