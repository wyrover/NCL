/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		DDEDATA.HPP
** COMPONENT:	Network & Comms Library
** DESCRIPTION:	The CDDEData class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DDEDATA_HPP
#define DDEDATA_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include "DDEFwd.hpp"
#include <WCL/Buffer.hpp>

/******************************************************************************
**
** This is a helper class for dealing with DDE data.
**
*******************************************************************************
*/

class CDDEData
{
public:
	//
	// Constructors/Destructor.
	//
	CDDEData(CDDEInst* pInst, HDDEDATA hData, uint nFormat, bool bOwn);
	CDDEData(CDDEInst* pInst, HSZ hItem, uint nFormat, bool bOwn);
	CDDEData(CDDEInst* pInst, const void* pBuffer, size_t nSize, size_t nOffset, uint nFormat, bool bOwn);
	CDDEData(CDDEInst* pInst, const CBuffer& oBuffer, uint nFormat, bool bOwn);
	CDDEData(const CDDEData& oData);
	~CDDEData();

	//
	// Operators.
	//
	CDDEData& operator=(const CDDEData& oData);

	//
	// Accessors.
	//
	HDDEDATA Handle() const;
	size_t   Size() const;
	size_t   GetData(void* pBuffer, size_t nSize, size_t nOffset = 0) const;
	CBuffer  GetBuffer() const;
	CString  GetString(TextFormat eFormat) const;

	//
	// Mutators.
	//
	void SetData(const void* pBuffer, size_t nSize, size_t nOffset = 0);
	void SetBuffer(const CBuffer& oBuffer);
	void SetString(const CString& str, TextFormat eFormat);

	void Free();

protected:
	// Forward declarations.
	class CHandle;

	//
	// Members.
	//
	CHandle* m_pHandle;
};

/******************************************************************************
**
** This is the reference counted body of CDDEData.
**
*******************************************************************************
*/

class CDDEData::CHandle /*: private NotCopyable*/
{
public:
	CHandle(CDDEInst* pInst, HDDEDATA hData, uint nFormat, bool bOwn);
	~CHandle();

	//
	// Members.
	//
	uint			m_nRefCount;	// The reference count.
	const CDDEInst*	m_pInst;		// The instance handle.
	HDDEDATA		m_hData;		// The data handle.
	const uint		m_nFormat;		// The data format.
	const bool		m_bOwn;			// Ownership flag.

private:
	// NotCopyable.
	CHandle(const CHandle&);
	CHandle& operator=(const CHandle&);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline HDDEDATA CDDEData::Handle() const
{
	ASSERT(m_pHandle != NULL);

	return m_pHandle->m_hData;
}

inline void CDDEData::SetBuffer(const CBuffer& oBuffer)
{
	SetData(oBuffer.Buffer(), oBuffer.Size());
}

#endif // DDEDATA_HPP
