// viconClient.h: interface for the viconClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VICONCLIENT_H__A15D3061_47B5_11D6_9A0B_0800690F62B2__INCLUDED_)
#define AFX_VICONCLIENT_H__A15D3061_47B5_11D6_9A0B_0800690F62B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#include <windows.h>
#include <cassert>
#endif
#include <string>

#include <math.h>

#include <vector>
#include "ClientCodes.h"

//typedef u_int  SOCKET;

#ifdef WIN32
	#ifdef _STATIC_VICON
		#define VICON_DLL_DEF
	#else
		#ifdef VICON_EXPORTS
			#define VICON_DLL_DEF __declspec(dllexport)
		#else
			#define VICON_DLL_DEF __declspec(dllimport)
			#ifdef _DEBUG
				#pragma comment (lib, "viconD")
			#else
				#pragma comment (lib, "vicon")
			#endif
		#endif
	#endif
#else
#define VICON_DLL_DEF
#endif

class VICON_DLL_DEF viconClient  
{

	std::vector< MarkerChannel >	MarkerChannels;
	std::vector< BodyChannel >		BodyChannels;
	int	FrameChannel;
	
	//typedef u_int SOCKET;
	int SocketHandle;

	std::vector< std::string > info;
	int bufferSize;
	char buff[2040];
	char * pBuff;

	long int size;

	std::vector< double > data;

	std::vector< MarkerData > markerPositions;

	std::vector< BodyData > bodyPositions;
	
public:
	viconClient(char* vicon_ip_address);
	virtual ~viconClient();

	int readData();
	
	int numberOfBodyParts() { return this->BodyChannels.size(); }

	int numberOfMarkers() { return this->MarkerChannels.size(); }
	
	std::vector<BodyData> * getBodyPositions() { return &(this->bodyPositions); }
	
	std::vector< BodyChannel > * getBodyChannels() { return &(this->BodyChannels); }

	std::vector<MarkerData> * getMarkerPositions() { return &(this->markerPositions); }
	
	std::vector< MarkerChannel > * getMarkerChannels() { return &(this->MarkerChannels); }
	
};

#endif // !defined(AFX_VICONCLIENT_H__A15D3061_47B5_11D6_9A0B_0800690F62B2__INCLUDED_)
