/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		DDESTRING.HPP
** COMPONENT:	Network & Comms Library
** DESCRIPTION:	The CDDEString class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DDESTRING_HPP
#define DDESTRING_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include "DDEInst.hpp"
#include "DDEException.hpp"

////////////////////////////////////////////////////////////////////////////////
// The build agnostic definition to use for selecting the code page when using
// the DDE String functions.

#ifdef ANSI_BUILD
#define CP_WIN_TCHAR	CP_WINANSI
#else
#define CP_WIN_TCHAR	CP_WINUNICODE
#endif

/******************************************************************************
** 
** This is a helper class for dealing with DDE string handles.
**
*******************************************************************************
*/

class CDDEString
{
public:
	//
	// Constructors/Destructor.
	//
	CDDEString(CDDEInst* pInst, const tchar* pszString, bool bOwn = true);
	CDDEString(CDDEInst* pInst, HSZ hsz, bool bOwn = false);
	~CDDEString();

	//
	// Operators.
	//
	operator HSZ() const;
	operator const tchar*() const;

protected:
	// Max length of string (as per DDE documentation).
	enum { MAX_LENGTH = 255 };

	//
	// Members.
	//
	CDDEInst*	m_pInst;				// The instance handle.
	HSZ			m_hsz;					// The string handle.
	bool		m_bOwn;					// Ownership flag.
	tchar		m_sz[MAX_LENGTH+1];		// Original string.

	// Disallow copies.
	CDDEString(const CDDEString&);
	void operator=(const CDDEString&);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CDDEString::CDDEString(CDDEInst* pInst, const tchar* pszString, bool bOwn)
	: m_pInst(pInst)
	, m_bOwn(bOwn)
{
	ASSERT(pInst     != NULL);
	ASSERT(pszString != NULL);

	// Create the string handle.
	m_hsz = ::DdeCreateStringHandle(m_pInst->Handle(), pszString, CP_WIN_TCHAR);

	if (m_hsz == NULL)
		throw CDDEException(CDDEException::E_STRING_FAILED, m_pInst->LastError());

	// Save original string.
	tstrncpy(m_sz, pszString, MAX_LENGTH);

	m_sz[MAX_LENGTH] = '\0';
}

inline CDDEString::CDDEString(CDDEInst* pInst, HSZ hsz, bool bOwn)
	: m_pInst(pInst)
	, m_hsz(hsz)
	, m_bOwn(bOwn)
{
	ASSERT(pInst != NULL);

	// Extract original string.
	::DdeQueryString(m_pInst->Handle(), m_hsz, m_sz, MAX_LENGTH+1, CP_WIN_TCHAR);
}

inline CDDEString::~CDDEString()
{
	// Free the string, if owned.
	if (m_bOwn)
		::DdeFreeStringHandle(m_pInst->Handle(), m_hsz);
}

inline CDDEString::operator HSZ() const
{
	return m_hsz;
}

inline CDDEString::operator const tchar*() const
{
	return m_sz;
}

#endif // DDESTRING_HPP
