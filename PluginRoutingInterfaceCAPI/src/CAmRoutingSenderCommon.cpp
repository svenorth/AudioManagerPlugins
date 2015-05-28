/**
 *  Copyright (c) 2012 BMW
 *
 *  \author Aleksandar Donchev, aleksander.donchev@partner.bmw.de BMW 2013
 *
 *  \copyright
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
 *  including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 *  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  For further information see http://www.genivi.org/.
 */


#include "CAmRoutingSenderCommon.h"

/**
 * Utility functions
 */

void CAmConvertCAPI2AM(const am_types::am_Domain_s & source, am::am_Domain_s & destination)
{
	destination.domainID = source.getDomainID();
	destination.name = source.getName();
	destination.busname = source.getBusname();
	destination.nodename = source.getNodename();
	destination.early = source.getEarly();
	destination.complete = source.getComplete();
	destination.state = static_cast<am::am_DomainState_e>((int)source.getState());
}

void CAmConvertCAPI2AM(const am_types::am_SoundProperty_s & source, am::am_SoundProperty_s & destination)
{
	destination.type = static_cast<am::am_CustomSoundPropertyType_t>(source.getType());
	destination.value = source.getValue();
}

void CAmConvertCAPIVector2AM(const std::vector<am_types::am_SoundProperty_s> & source, std::vector<am::am_SoundProperty_s> & destination)
{
	am::am_SoundProperty_s soundProp;
	destination.clear();
	for(std::vector<am_types::am_SoundProperty_s>::const_iterator iter = source.begin(); iter!=source.end(); ++iter)
	{
		CAmConvertCAPI2AM(*iter, soundProp);
		destination.push_back(soundProp);
	}
}

void CAmConvertCAPI2AM(const am_types::am_MainSoundProperty_s & source, am::am_MainSoundProperty_s & destination)
{
	destination.type = static_cast<am::am_CustomMainSoundPropertyType_t>(source.getType());
	destination.value = source.getValue();
}


void CAmConvertCAPI2AM(const am_types::am_NotificationPayload_s & source, am::am_NotificationPayload_s & destination)
{
	destination.type = static_cast<am::am_CustomNotificationType_t>(source.getType());
	destination.value = source.getValue();
}

void CAmConvertCAPIVector2AM(const std::vector<am_types::am_Volumes_s> & source, std::vector<am::am_Volumes_s> & destination)
{
	destination.clear();
	for(std::vector<am_types::am_Volumes_s>::const_iterator iter = source.begin(); iter!=source.end(); ++iter)
	{
		am::am_Volumes_s volume;
		CAmConvertCAPI2AM(*iter, volume);
		destination.push_back(volume);
	}
}

void CAmConvertCAPIVector2AM(const std::vector<am_types::am_MainSoundProperty_s> & source, std::vector<am::am_MainSoundProperty_s> & destination)
{
	am::am_MainSoundProperty_s soundProp;
	destination.clear();
	for(std::vector<am_types::am_MainSoundProperty_s>::const_iterator iter = source.begin(); iter!=source.end(); ++iter)
	{
		CAmConvertCAPI2AM(*iter, soundProp);
		destination.push_back(soundProp);
	}
}

void CAmConvertCAPI2AM(const am_types::am_NotificationConfiguration_s & source, am::am_NotificationConfiguration_s & destination)
{
	destination.type = static_cast<am::am_CustomNotificationType_t>(source.getType());
	destination.status = static_cast<am::am_NotificationStatus_e>((int)source.getStatus());
	destination.parameter = source.getParameter();
}

void CAmConvertCAPIVector2AM(const std::vector<am_types::am_NotificationConfiguration_s> & source, std::vector<am::am_NotificationConfiguration_s> & destination)
{
	am::am_NotificationConfiguration_s soundProp;
	destination.clear();
	for(std::vector<am_types::am_NotificationConfiguration_s>::const_iterator iter = source.begin(); iter!=source.end(); ++iter)
	{
		CAmConvertCAPI2AM(*iter, soundProp);
		destination.push_back(soundProp);
	}
}

void CAmConvertCAPIVector2AM(const std::vector<am_types::am_ConnectionFormat_pe> & source, std::vector<am::am_CustomConnectionFormat_t> & destination)
{
	destination.clear();
	for(std::vector<am_types::am_ConnectionFormat_pe>::const_iterator iter = source.begin(); iter!=source.end(); ++iter)
		destination.push_back(static_cast<am::am_CustomConnectionFormat_t>(*iter));
}



void CAmConvertCAPI2AM(const am_types::am_Source_s & source, am::am_Source_s & destination)
{
	destination.sourceID = source.getSourceID();
	destination.domainID = source.getDomainID();
	destination.name = source.getName();
	destination.sourceClassID = source.getSourceClassID();
	destination.sourceState = static_cast<am::am_SourceState_e>((int)source.getSourceState());
	destination.volume = source.getVolume();
	destination.visible = source.getVisible();
	CAmConvertCAPI2AM(source.getAvailable(), destination.available);
	destination.interruptState =  static_cast<am::am_InterruptState_e>((int)source.getInterruptState());
	CAmConvertCAPIVector2AM(source.getListSoundProperties(), destination.listSoundProperties);
	CAmConvertCAPIVector2AM(source.getListConnectionFormats(), destination.listConnectionFormats);
	CAmConvertCAPIVector2AM(source.getListMainSoundProperties(), destination.listMainSoundProperties);
	CAmConvertCAPIVector2AM(source.getListNotificationConfigurations(), destination.listNotificationConfigurations);
	CAmConvertCAPIVector2AM(source.getListMainNotificationConfigurations(), destination.listMainNotificationConfigurations);
}

void CAmConvertCAPI2AM(const am_types::am_Sink_s & source, am::am_Sink_s & destination)
{
	destination.sinkID = source.getSinkID();
	destination.domainID = source.getDomainID();
	destination.name = source.getName();
	destination.sinkClassID = source.getSinkClassID();
	destination.muteState = static_cast<am::am_MuteState_e>((int)source.getMuteState());
	destination.volume = source.getVolume();
	destination.visible = source.getVisible();
	destination.mainVolume = source.getMainVolume();
	CAmConvertCAPI2AM(source.getAvailable(), destination.available);
	CAmConvertCAPIVector2AM(source.getListSoundProperties(), destination.listSoundProperties);
	CAmConvertCAPIVector2AM(source.getListConnectionFormats(), destination.listConnectionFormats);
	CAmConvertCAPIVector2AM(source.getListMainSoundProperties(), destination.listMainSoundProperties);
	CAmConvertCAPIVector2AM(source.getListNotificationConfigurations(), destination.listNotificationConfigurations);
	CAmConvertCAPIVector2AM(source.getListMainNotificationConfigurations(), destination.listMainNotificationConfigurations);
}

void CAmConvertCAPI2AM(const am_types::am_Volumes_s & source, am::am_Volumes_s & destination)
{
	CAmConvertCAPI2AM(source.getVolumeID(), destination.volumeID);
	destination.volume = source.getVolume();
	destination.time = source.getTime();
	destination.volumeType = static_cast<am::am_VolumeType_e>((int)source.getVolumeType());
	destination.ramp = static_cast<am::am_CustomRampType_t>(source.getRamp());
}


void CAmConvertCAPI2AM(const am_types::am_Crossfader_s & source, am::am_Crossfader_s & destination)
{
	destination.crossfaderID = source.getCrossfaderID();
	destination.sinkID_A = source.getSinkIDA();
	destination.sinkID_B = source.getSinkIDB();
	destination.name = source.getName();
	destination.sourceID = source.getSourceID();
	destination.hotSink = static_cast<am::am_HotSink_e>((int)source.getHotSink());
}


void CAmConvertCAPI2AM(const am_types::am_Gateway_s & source, am::am_Gateway_s & destination)
{
	destination.sinkID = source.getSinkID();
	destination.gatewayID = source.getGatewayID();
	destination.name = source.getName();
	destination.sourceID = source.getSourceID();
	destination.domainSinkID = source.getDomainSinkID();
	destination.domainSourceID = source.getDomainSourceID();
	destination.controlDomainID = source.getControlDomainID();
	CAmConvertCAPIVector2AM(source.getListSourceFormats(), destination.listSourceFormats);
	CAmConvertCAPIVector2AM(source.getListSinkFormats(), destination.listSinkFormats);
	destination.convertionMatrix = source.getConvertionMatrix();
}

void CAmConvertCAPI2AM(const am_types::am_Converter_s & source, am::am_Converter_s & destination)
{
	destination.sinkID = source.getSinkID();
	destination.converterID = source.getConverterID();
	destination.name = source.getName();
	destination.sourceID = source.getSourceID();
	destination.domainID = source.getDomainID();
	CAmConvertCAPIVector2AM(source.getListSourceFormats(), destination.listSourceFormats);
	CAmConvertCAPIVector2AM(source.getListSinkFormats(), destination.listSinkFormats);
	destination.convertionMatrix = source.getConvertionMatrix();
}

void CAmConvertCAPI2AM(const am_types::am_EarlyData_u & source, am::am_EarlyData_u & destination)
{
	if(source.isType<am_types::am_volume_t>())
	{
		am_volume_t value = static_cast<am_volume_t>(source.get<am_types::am_volume_t>());
		destination.volume = value;
	}
	else if(source.isType<am_types::am_SoundProperty_s>())
	{
		am_types::am_SoundProperty_s value = source.get<am_types::am_SoundProperty_s>();
		am_SoundProperty_s converted;
		CAmConvertCAPI2AM(value, converted);
		destination.soundProperty = converted;
	}
}

void CAmConvertCAPI2AM(const am_types::am_DataType_u & source, am::am_DataType_u & destination)
{
	if(source.isType<am_types::am_sinkID_t>())
	{
		am_sinkID_t value = static_cast<am_sinkID_t>(source.get<am_types::am_sinkID_t>());
		destination.sink = value;
	}
	else if(source.isType<am_types::am_sourceID_t>())
	{
		am_sourceID_t value = static_cast<am_sourceID_t>(source.get<am_types::am_sourceID_t>());
		destination.source = value;
	}
}

void CAmConvertCAPI2AM(const am_types::am_EarlyData_s & source, am::am_EarlyData_s & destination)
{
	CAmConvertCAPI2AM(source.getData(), destination.data);
	CAmConvertCAPI2AM(source.getSinksource(), destination.sinksource);
	destination.type = static_cast<am_EarlyDataType_e>((int)source.getType());
}


void CAmConvertCAPI2AM(const am_types::am_Availability_s  & source,  am_Availability_s & destination)
{
	destination.availability = static_cast<am_Availability_e>((int)source.getAvailability());
	destination.availabilityReason = static_cast<am_CustomAvailabilityReason_t>((int)source.getAvailabilityReason());
}

void CAmConvertCAPI2AM(const am_types::am_Handle_s& source, am_Handle_s& destination)
{
	destination.handle = static_cast<int16_t>(source.getHandle());
	destination.handleType = static_cast<am_Handle_e>((int)source.getHandleType());
}

void CAmConvertAM2CAPI(const am_Availability_s & source,  am_types::am_Availability_s & destination)
{
	destination.setAvailability(source.availability);
	destination.setAvailabilityReason(source.availabilityReason);
}

void CAmConvertAM2CAPI(const am::am_SoundProperty_s & source, am_types::am_SoundProperty_s & destination)
{
	destination.setType(source.type);
	destination.setValue(source.value);
}

extern void CAmConvertAM2CAPI(const am::am_Handle_s& source,am_types::am_Handle_s& destination)
{
	destination.setHandle(source.handle);
	destination.setHandleType(source.handleType);
}


void CAmConvertAM2CAPI(const am::am_NotificationConfiguration_s & source, am_types::am_NotificationConfiguration_s & destination)
{
	destination.setType(source.type);
	destination.setStatus(source.status);
	destination.setParameter(source.parameter);
}

void CAmConvertAM2CAPI(const am::am_Volumes_s & source, am_types::am_Volumes_s & destination)
{
	if(source.volumeType == VT_SINK)
		destination.setVolumeID(am_types::am_DataType_u(static_cast<am_types::am_sinkID_t>(source.volumeID.sink)));
	else if(source.volumeType == VT_SOURCE)
		destination.setVolumeID(am_types::am_DataType_u(static_cast<am_types::am_sourceID_t>(source.volumeID.source)));
	destination.setVolumeType(source.volumeType);
	destination.setVolume(source.volume);
	destination.setRamp(source.ramp);
	destination.setTime(source.time);
}

void CAmConvertAMVector2CAPI(const std::vector<am::am_Volumes_s> & source, am_types::am_Volumes_L & destination)
{
	destination.clear();
	for(std::vector<am::am_Volumes_s>::const_iterator iter = source.begin(); iter!=source.end(); ++iter)
	{
		am_types::am_Volumes_s volume;
		CAmConvertAM2CAPI(*iter, volume);
		destination.push_back(volume);
	}
}

void CAmConvertCAPIVector2AM(const am_types::am_EarlyData_L& source,std::vector<am::am_EarlyData_s>& destination)
{
	destination.clear();
	for (am_types::am_EarlyData_L::const_iterator iter = source.begin(); iter!=source.end(); ++iter)
	{
		am_EarlyData_s earlyData;
		CAmConvertCAPI2AM(*iter,earlyData);
		destination.push_back(earlyData);
	}
}

void CAmConvertAMVector2CAPI(const std::vector<am::am_SoundProperty_s> & source, std::vector<am_types::am_SoundProperty_s> & destination)
{
	am_types::am_SoundProperty_s soundProp;
	destination.clear();
	for(std::vector<am::am_SoundProperty_s>::const_iterator iter = source.begin(); iter!=source.end(); ++iter)
	{
		CAmConvertAM2CAPI(*iter, soundProp);
		destination.push_back(soundProp);
	}
}
