/*
 * Copyright (c) 2001 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 *
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _DHCPCLIENTPREFERENCES_H
#define _DHCPCLIENTPREFERENCES_H

#include <sys/cdefs.h>
#include <CoreFoundation/CFString.h>

/*!
	@header DHCPClientPreferences.h
 */

__BEGIN_DECLS

/*!
	@function DHCPClientPreferencesSetApplicationOptions
	@discussion Updates the DHCP client preferences to include the
		given list of options for the given "applicationID".
	@param applicationID The application's preference ID, for example:
		"com.apple.SystemPreferences".
	@param options An array of 8-bit values containing the
		DHCP option codes (see RFC 2132) for this applicationID.
		A NULL value will clear the list of options for this
		application ID.
	@param count The number of elements in "options".
	@result TRUE if the operation succeeded, FALSE otherwise.
 */

Boolean
DHCPClientPreferencesSetApplicationOptions(CFStringRef applicationID,
					   UInt8 * options,
					   CFIndex count);

/*!
	@function DHCPClientPreferencesCopyApplicationOptions
	@discussion Copies the requested DHCP options for the
		given "applicationID".
	@param applicationID The application's preference ID, for example
		"com.apple.SystemPreferences".
	@param count The number of elements in the returned array.
	@result The list of options for the given "applicationID", or
		NULL if no options are defined or an error occurred.

		When done, use free() to release a non-NULL return value.
 */

UInt8 *
DHCPClientPreferencesCopyApplicationOptions(CFStringRef applicationID,
					    CFIndex * count);

__END_DECLS

#endif /* _DHCPCLIENTPREFERENCES_H */
