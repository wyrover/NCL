/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		DDEEXCEPTION.CPP
** COMPONENT:	Network & Comms Library
** DESCRIPTION:	CDDEException class definition.
**
*******************************************************************************
*/

#include "Common.hpp"
#include "DDEException.hpp"
#include "DDEInst.hpp"
#include "DDECltConv.hpp"
#include <Core/StringUtils.hpp>

/******************************************************************************
** Method:		Constructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CDDEException::CDDEException(int eErrCode, uint nDDECode)
	: m_nDDECode(nDDECode)
{
	// Get error code as #defined symbol.
	CString strErrDef = CDDEInst::GetErrorCode(m_nDDECode);

	// Convert error to string.
	switch(eErrCode)
	{
		case E_INIT_FAILED:
			m_details = Core::fmt(TXT("Failed to initialise DDE: %s"), strErrDef.c_str());
			break;

		case E_CONN_FAILED:
			m_details = Core::fmt(TXT("Failed to connect to DDE server: %s"), strErrDef.c_str());
			break;

		case E_STRING_FAILED:
			m_details = Core::fmt(TXT("Failed to create DDE string: %s"), strErrDef.c_str());
			break;

		case E_REQUEST_FAILED:
			m_details = Core::fmt(TXT("Failed to request DDE item: %s"), strErrDef.c_str());
			break;

		case E_LINK_FAILED:
			m_details = Core::fmt(TXT("Failed to create DDE advise loop: %s"), strErrDef.c_str());
			break;

		case E_ALLOC_FAILED:
			m_details = Core::fmt(TXT("Failed to allocate DDE data handle: %s"), strErrDef.c_str());
			break;

		case E_QUERY_FAILED:
			m_details = Core::fmt(TXT("Failed to query DDE servers: %s"), strErrDef.c_str());
			break;

		case E_EXECUTE_FAILED:
			m_details = Core::fmt(TXT("Failed to execute a DDE command: %s"), strErrDef.c_str());
			break;

		case E_POKE_FAILED:
			m_details = Core::fmt(TXT("Failed to poke an item: %s"), strErrDef.c_str());
			break;

		case E_STRCOPY_FAILED:
			m_details = Core::fmt(TXT("Failed to query string data: %s"), strErrDef.c_str());
			break;

		// Shouldn't happen!
		default:
			ASSERT_FALSE();
			break;
	}
}

/******************************************************************************
** Method:		Destructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CDDEException::~CDDEException() throw()
{
}
